#pragma once
#include "type_list.h"

void
	__list_iterator_next
		(__list_iterator*);

void
	__list_iterator_prev
		(__list_iterator*);

void*
	__list_iterator_value
		(__list_iterator*);

void
	__list_iterator_for_each
		(__list_iterator*, __list_iterator*, void(*)(void*));