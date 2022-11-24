#include "spsc_controller.h"

__spsc_controller
__spsc_controller_entity = 
	{
		.push				= &__spsc_push				,
		.push_bounded		= &__spsc_push_bounded		,
		.push_until_success = &__spsc_push_until_success,

		.pop			    = &__spsc_pop			   ,
		.pop_bounded		= &__spsc_pop_bounded	   ,
		.pop_until_success	= &__spsc_pop_until_success
	};

__spsc_controller*
	__spsc_default_controller() {
		return
			&__spsc_controller_entity;
}

crisp_bool
	__spsc_push
		(__spsc_head* pHead, void* pData) {
	return
		__spsc_do_push(pHead);
}

void
	__spsc_push_until_success
		(__spsc_head* pHead, void* pData) {
	__spsc_do_push_until_success
		(pHead, pData);
}

void
	__spsc_push_bounded
		(__spsc_head* pHead, void** pData, crisp_u64 pDataCount) {
	while (--pDataCount >= 0)
		__spsc_push_until_success(pHead, pData[pDataCount]);
}

void*
	__spsc_pop
		(__spsc_head* pHead) {
	return
		__spsc_do_pop(pHead);
}

void*
	__spsc_pop_until_success
		(__spsc_head* pHead) {
	return
		__spsc_do_pop_until_success(pHead);
}

void
	__spsc_pop_bounded
		(__spsc_head* pHead, void** pData, crisp_u64 pDataCount) {
	while (--pDataCount >= 0) {
		pData[pDataCount]
			= __spsc_pop_until_success(pHead);
	}
}