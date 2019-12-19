#include <stdio.h>
#include "facto.h"

int main() {
	for (unsigned long n = 0; n <= 20; n++) {
		printf("facto(%lu) = %lu\n", n, facto(n));
	}

	return 0;	
}
