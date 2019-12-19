#include <stdio.h>
#include "isqrt.h"

int main() {
	for (unsigned long n = 0; n <= 200; n += 8) {
		printf("isqrt(%lu) = %lu\n", n, isqrt(n));
	}

	return 0;
}
