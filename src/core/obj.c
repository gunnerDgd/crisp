#include "obj.h"
#include "atom.h"
#include "mem.h"

obj*
    obj_new
		(mem* mem, obj_trait* trait, u32_t count, ...) {
    		va_list  arg;
			va_start(arg, count); obj* ret = obj_new_va(mem, trait, count, arg);
			va_end  (arg);
			return   ret ;
}

obj*
    obj_new_va
		(mem* mem, obj_trait* trait, u32_t count, va_list arg) {
			if (trait_of(mem) != mem_t) mem = get_mem();
			if (trait_of(mem) != mem_t) return null_t;
			if (!trait)					return null_t;

            if (trait->size < sizeof(obj)) return null_t;
			if (!mem) mem = get_mem();
			if (!mem) return   null_t;
			

			obj *ret = mem_use (mem, null_t, trait->size);
			if (!ret) return null_t;
			ret->trait = trait;
			ret->mem   = mem  ;
			ret->ref   = 1	  ;

			if (!trait->on_new)        return ret;
			if (!trait->on_new(ret, count, arg)) {
				mem_free(mem, ret, 0);
				return null_t;
			}

			return ret;
}

bool_t
	obj_new_at
		(obj* self, obj_trait* trait, u32_t count, ...) {
			va_list  arg;
			va_start(arg, count); 
			bool_t ret = obj_new_at_va (
				self , 
				trait,
				count,
				arg
			);
			
			va_end (arg);
			return  ret ;
}

bool_t 
	obj_new_at_va
		(obj* self, obj_trait* trait, u32_t count, va_list arg) {
			if (!trait) return false_t;
			if (!self)  return false_t;

			if (trait->size < sizeof(obj)) return false_t;
			mem_set(self, 0x00, trait->size);
			self->trait = trait ;
			self->mem   = null_t;
			self->ref   = 1     ;

			if (!trait->on_new)      return true_t;
			if (!trait->on_new(self, count, arg)) {
				mem_set(self, 0x00, trait->size);
				return false_t;
			}

			return true_t;
}

obj*	   
	obj_clone   
		(obj* self)                             {
		    if (!trait_of (self)) return false_t;
		    if (!use_count(self)) return false_t;
			obj_trait *trait = self->trait;
			mem		  *mem   = self->mem  ;

            if (trait->size < sizeof(obj)) return null_t;
			if (trait_of(mem) != mem_t)    mem = get_mem();
			if (trait_of(mem) != mem_t)    return null_t;

			obj *ret = mem_use (mem, null_t, trait->size);
			if (!ret) return null_t;
			ret->trait = trait;
			ret->mem   = mem  ;
			ret->ref   = 1	  ;

			if (!trait->on_clone)			    {
				mem_copy(ret, self, trait->size);
				return   ret;
			}

			if (!trait->on_clone(ret, self)) goto err;
			return ret;
	err:    mem_free(mem, ret, 0);
			return null_t;
}

bool_t     
	obj_clone_at
		(obj* self, obj* clone)            {
			obj_trait *trait = clone->trait;
			if (!clone->ref) return false_t;
            if (!trait)      return false_t;

            self->trait =  trait;
            self->mem   = null_t;
            self->ref   = 1;

			if (!trait->on_clone)                 {
				mem_copy(self, clone, trait->size);
				return true_t;
			}

			if(!trait->on_clone(self, clone)) goto err;
			return true_t;
	err:    mem_set(self, 0x00, trait->size);
			return false_t;
}

obj*
	obj_ref
		(obj* self)							    {
			if (!use_count(self)) return false_t;
			if (!trait_of (self)) return false_t;

			if (!self->trait->on_ref)   {
				lock_inc(&self->ref);
				return self;
			}
			
			if (!self->trait->on_ref(self)) return null_t;
			lock_inc(&self->ref);
			return self;
}

u64_t
	obj_del
		(obj* self)								{
			if (!use_count(self)) return false_t;
			if (!trait_of (self)) return false_t;

			u64_t ref = lock_cas_dec(&self->ref);
			if (ref) return ref;
			if (self->trait->on_del) self->trait->on_del(self);
			if (!self->mem)						      {
				mem_set(self, 0x00, self->trait->size);
				return 0;
			}

			mem_free(self->mem, self, 0);
			return 0;
}

obj_trait* 
	obj_get_trait
		(obj* par)				   {
			if (!par) return null_t;
			return par->trait;
}

u64_t 
	obj_use_count
		(obj* par)					 {
			if (!par)		 return 0;
			if (!par->trait) return 0;

			return par->ref;
}