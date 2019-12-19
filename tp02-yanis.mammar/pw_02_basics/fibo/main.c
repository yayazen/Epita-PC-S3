#include <stdio.h>
#include "fibo.h"

int main() {
	for (unsigned long n = 0; n <= 90; n++) {
		printf("fibo(%lu) = %lu\n", n, fibo(n));
	}

	return 0;	
}
