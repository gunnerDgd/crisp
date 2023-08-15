#include <crisp/atomic.h>
#include <stdio.h>

int main() {
	c_atomic_i64_t a = 1;
	printf("%d", c_atomic_cmpxchg_i64(&a, a + 1));

}