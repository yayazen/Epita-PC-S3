#include <stdio.h>
#include "is_perfect_number.h"

int main() {
	for (unsigned long n = 1; n <= 100000; n++) {
		if (is_perfect_number(n))
			printf("%lu\n", n);
	}
	return 0;
}
