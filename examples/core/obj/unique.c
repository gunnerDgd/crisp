#include <core.h>

typedef struct uni {
    obj head;
}   uni;

bool_t uni_new	 (uni* par_obj, u32_t par_count, va_list par) { println("Object Created")         ; return true_t ; }
bool_t uni_clone(uni* par    , uni* par_clone)                { println("Object Created As Clone"); return true_t ; }
bool_t uni_ref  (uni* par)                                    { println("I'm Unique!")            ; return false_t; }
void   uni_del  (uni* par)                                    { println("Object Destroyed")       ; }

obj_trait uni_trait = make_trait (
    uni_new    ,
    uni_clone  ,
    uni_ref    ,
    uni_del    ,
    sizeof(uni),
    null_t
);

use()

obj_trait* uni_t = &uni_trait;

int run()			             {
    uni* uob = make(uni) from (0);
    ref (uob); println("Use Count : %llu", use_count(uob));
    ref (uob); println("Use Count : %llu", use_count(uob));
    ref (uob); println("Use Count : %llu", use_count(uob));
    del (uob);
}