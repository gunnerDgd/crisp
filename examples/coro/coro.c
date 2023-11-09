#include "coro.h"
#include <stdio.h>

void test(coro* par_coro, void* par) {
	printf("Hello (")	 ; yield(par_coro, 1);
	printf("World (")	 ; yield(par_coro, 2);
	printf("C (")		 ; yield(par_coro, 3);
	printf("Coroutine\n");
}

int main() {
	coro    coro;
	make_at(coro, coro_t) from(2, test, 0);
	printf("Yield Value : %d)\n", yield(&coro, 0));
	printf("Yield Value : %d)\n", yield(&coro, 0));
	printf("Yield Value : %d)\n", yield(&coro, 0));
	yield (&coro, 0);
}