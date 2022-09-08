#include <atomic_structure/queue/spsc/spsc_manip.h>
#include <atomic_structure/queue/spsc/details/details_spsc_manip.h>

void*
    atomic_spsc_read_from
        (atomic_spsc pSpsc)
{
    if(!pSpsc.handle)
        return 0;
    
    return
        __atomic_spsc_read_from(&pSpsc); 
}

void*
    atomic_spsc_read_from_until_success
        (atomic_spsc pSpsc)
{
    return
        __atomic_spsc_read_from_until_success
            (&pSpsc);
}

bool
    atomic_spsc_write_to
        (atomic_spsc pSpsc,
         void*       pSpscWriteData)
{
    return
        __atomic_spsc_write_to
            (&pSpsc, pSpscWriteData);
}

void
    atomic_spsc_write_to_until_success
        (atomic_spsc pSpsc,
         void*       pSpscWriteData)
{
    __atomic_spsc_write_to_until_success
        (&pSpsc, pSpscWriteData);
}