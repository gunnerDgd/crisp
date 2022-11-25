#include "spsc.h"

__queue_controller
__queue_controller_spsc =
	{
		.push				= &__spsc_push				,
		.push_bounded		= &__spsc_push_bounded		,
		.push_until_success = &__spsc_push_until_success,

		.pop			    = &__spsc_pop,
		.pop_bounded	    = &__spsc_pop_bounded,
		.pop_until_success  = &__spsc_pop_until_success,
	};

__queue_controller*
	__spsc_default_controller() {
		return
			&__queue_controller_spsc;
}

crisp_u64
	__spsc_push_bounded
		(__spsc_head* pHead, void** pEntityArray, crisp_u64 pEntityCount) {
	for(crisp_u64 push_count = 0			;
				  push_count < pEntityCount ;
				  push_count++)
		__spsc_push_until_success(pHead, pEntityArray[pEntityCount]);

	return pEntityCount;
}

crisp_u64
	__spsc_pop_bounded
		(__spsc_head* pHead, void** pEntityArray, crisp_u64 pEntityCount) {
	for(crisp_u64 pop_count = 0;
				  pop_count < pEntityCount ;
				  pop_count++)
		pEntityArray[pEntityCount]
			= __spsc_pop_until_success(pHead);

	return pEntityCount;
}