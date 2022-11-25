#include "turbo_list.h"

__list_controller
__list_controller_turbo =
    {
        .push_front = &__turbo_list_push_front,
        .push_back  = &__turbo_list_push_back ,
        .push_at    = &__turbo_list_push_at   ,

        .pop_front  = &__turbo_list_pop_front ,
        .pop_back   = &__turbo_list_pop_back  ,
        .pop_at     = &__turbo_list_pop_at
    };

__list_controller*
    __turbo_list_controller() {
        return
            &__list_controller_turbo;
}