#include <stdio.h>
#include "power_of_two.h"

int main() {
	for (unsigned char n = 0; n <=  63; n++) {
		printf("power_of_two(%u) = %lu\n", n, power_of_two(n));
	}
	return 0;
}
