#include <boost/thread.hpp>
#include <chrono>

extern "C"
{
#include <crisp/atomic/spsc.h>
#include <crisp/queue/queue.h>
#include <crisp/allocator/standard_library.h>
}

void
	pf_spsc_initialize
		(crisp_spsc*, crisp_u64);

void
	pf_spsc_cleanup
		(crisp_spsc*);

void
	pf_spsc_push
		(crisp_spsc*, crisp_u64, crisp_u64&);

void
	pf_spsc_pop
		(crisp_spsc*, crisp_u64, crisp_u64&);

void
	pf_spsc_push_and_pop
		(crisp_spsc*, crisp_u64, crisp_u64, crisp_u64&);