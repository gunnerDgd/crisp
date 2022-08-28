#include <atomic_structure/spsc/details/details_spsc_manip.h>

#ifdef ATOMIC_STRUCTURE_BUILD_ENVIRONMENT_GNU
#include <stdatomic.h>
#elif  ATOMIC_STRUCTURE_BUILD_ENVIRONMENT_MSVC
#include <Windows.h>
#endif

void*
    __atomic_spsc_read_from
        (__atomic_spsc* pSpsc)
{
    void*
        ptr_spsc_rdptr_data;

#ifdef ATOMIC_STRUCTURE_BUILD_ENVIRONMENT_LINUX 
    atomic_exchange
        (&pSpsc->ptr_cqueue_rdptr,
            pSpsc->ptr_cqueue_rdptr->ptr_cqueue_next);
#endif
    ptr_spsc_rdptr_data
        = pSpsc->ptr_cqueue_rdptr->ptr_cqueue_data;
    
    return
        ptr_spsc_rdptr_data;
}

void*
    __atomic_spsc_read_from_until_success
        (__atomic_spsc* pSpsc)
{
    void*
        ptr_spsc_read_data;
    
    while
        ((ptr_spsc_read_data = __atomic_spsc_read_from(pSpsc)) == -1);
    return
        ptr_spsc_read_data;
}

bool
    __atomic_spsc_write_to
        (__atomic_spsc* pSpsc,
         void*          pSpscWriteData)
{
    if(pSpsc->ptr_cqueue_wrptr->ptr_cqueue_next
            == pSpsc->ptr_cqueue_rdptr)
                return false;
    
    pSpsc->ptr_cqueue_wrptr
        = pSpscWriteData;

#ifdef ATOMIC_STRUCTURE_BUILD_ENVIRONMENT_LINUX
    atomic_exchange
        (&pSpsc->ptr_cqueue_wrptr,
            pSpsc->ptr_cqueue_wrptr->ptr_cqueue_next);
#endif
    return true;
}

void
    __atomic_spsc_write_to_until_success
        (__atomic_spsc* pSpsc,
         void*          pSpscWriteData)
{
    while
        (!__atomic_spsc_write_to(pSpsc, pSpscWriteData));
}