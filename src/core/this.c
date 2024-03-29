#include "this.h"

#ifdef PRESET_FEATURE_THREAD
#ifdef PRESET_COMPILER_GCC
__thread struct this *this;
#endif
#else
struct this          *this;
#endif

obj_trait this_trait = make_trait (
    this_new           ,
    this_clone         ,
    this_ref           ,
    this_del           ,
    sizeof(struct this),
    null_t
);

obj_trait *this_t = &this_trait;

bool_t
    this_new
        (struct this* par_this, u32_t par_count, va_list par) {
            par_this->task = null_t;
            return true_t;
}

bool_t this_clone(struct this* par, struct this*) { return false_t; }
bool_t this_ref  (struct this* par)               { return false_t; }
void   this_del  (struct this* par)               {                 }