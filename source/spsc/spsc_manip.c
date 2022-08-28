#include <atomic_structure/spsc/spsc_manip.h>
#include <atomic_structure/spsc/details/details_spsc_manip.h>

atomic_spsc_read_pointer
    atomic_spsc_retrieve_read_pointer
        (atomic_spsc pSpsc)
{
    atomic_spsc_read_pointer
        hnd_spsc_rdptr = { .handle = 0 };

    if(pSpsc.handle)
        hnd_spsc_rdptr.handle
            = __atomic_spsc_read_pointer(pSpsc.handle);
    
    return
        hnd_spsc_rdptr;
}

atomic_spsc_write_pointer
    atomic_spsc_retrieve_write_pointer
        (atomic_spsc pSpsc)
{
    atomic_spsc_write_pointer
        hnd_spsc_wrptr = { .handle = 0 };

    if(pSpsc.handle)
        hnd_spsc_wrptr.handle
            = __atomic_spsc_write_pointer(pSpsc.handle);
    
    return
        hnd_spsc_wrptr;
}

void*
    atomic_spsc_read_from
        (atomic_spsc pSpsc, atomic_spsc_read_pointer pSpscReadPointer)
{
    if(!pSpsc.handle || !pSpscReadPointer.handle)
        return 0;
    
    return
        __atomic_spsc_read_from
            (pSpsc.handle, pSpscReadPointer.handle);
}

void*
    atomic_spsc_read_from_until_success
        (atomic_spsc pSpsc, atomic_spsc_read_pointer pSpscReadPointer)
{
    if(!pSpsc.handle || !pSpscReadPointer.handle)
        return 0;
    
    return
        __atomic_spsc_read_from_until_success
            (pSpsc.handle, pSpscReadPointer.handle);
}

bool
    atomic_spsc_write_to
        (atomic_spsc               pSpsc,
         atomic_spsc_write_pointer pSpscWritePointer, 
         void*                     pSpscWriteData)
{
    if(!pSpsc.handle || !pSpscWritePointer.handle)
        return false;
    
    return
        __atomic_spsc_write_to
            (pSpsc.handle, pSpscWritePointer.handle, pSpscWriteData);
}

void
    atomic_spsc_write_to_until_success
        (atomic_spsc               pSpsc, 
         atomic_spsc_write_pointer pSpscWritePointer, 
         void*                     pSpscWriteData)
{
    if(!pSpsc.handle || !pSpscWritePointer.handle)
        return;
    
    return
        __atomic_spsc_write_to_until_success
            (pSpsc.handle, pSpscWritePointer.handle, pSpscWriteData);
}