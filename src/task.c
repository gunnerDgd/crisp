#include "task.h"
#include "details/task.h"

obj_trait* task_t = &__task_trait;

void* 
    task_wait
        (task* par)                              { 
            if (!par)                    return 0;
            if (trait_of(par) != task_t) return 0;
            return __task_wait(par); 
}

void 
    task_susp
        (task* par) { 
            if (!par)                    return;
            if (trait_of(par) != task_t) return;
            __task_susp(par); 
}

void  
    task_resm
        (task* par)                            {
            if (!par)                    return;
            if (trait_of(par) != task_t) return;
            __task_resm(par); 
}