#include <atomic_structure/spsc/spsc_manip.h>
#include <atomic_structure/spsc/details/details_spsc_manip.h>

void*
    atomic_spsc_read_from
        (atomic_spsc pSpsc)
{
    if(!pSpsc.handle)
        return 0;
    
    return
        __atomic_spsc_read_from
            (pSpsc.handle);
}

void*
    atomic_spsc_read_from_until_success
        (atomic_spsc pSpsc)
{
    if(!pSpsc.handle)
        return 0;
    
    return
        __atomic_spsc_read_from_until_success
            (pSpsc.handle);
}

bool
    atomic_spsc_write_to
        (atomic_spsc pSpsc,
         void*       pSpscWriteData)
{
    if(!pSpsc.handle)
        return false;
    
    return
        __atomic_spsc_write_to
            (pSpsc.handle, pSpscWriteData);
}

void
    atomic_spsc_write_to_until_success
        (atomic_spsc pSpsc,
         void*       pSpscWriteData)
{
    if(pSpsc.handle)
        __atomic_spsc_write_to_until_success
            (pSpsc.handle, pSpscWriteData);
}