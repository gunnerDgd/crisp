#include <list/type_list.h>

__list_controller*
    __turbo_list_controller();

void
    __turbo_list_push_front
        (__list_head*, __list_node*);

void
    __turbo_list_push_back
        (__list_head*, __list_node*);

void
    __turbo_list_push_at
        (__list_head*, __list_node*, __list_node*);

__list_node*
    __turbo_list_pop_front
        (__list_head*);

__list_node*
    __turbo_list_pop_back
        (__list_head*); 

void
    __turbo_list_pop_at
        (__list_head*, __list_node*);