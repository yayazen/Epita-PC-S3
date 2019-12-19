#include <stdio.h>
#include "digit_count.h"

int main() {
	unsigned long n = 0;
	for (char p = 0; p <= 64; p++) {
		printf("digit_count(%lu) = %u\n", n, digit_count(n));
		n = (n == 0) ? 1UL : n << 1;
	}
	return 0;
}
