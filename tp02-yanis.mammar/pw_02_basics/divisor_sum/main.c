#include <stdio.h>
#include <stdlib.h>
#include <err.h>
#include "divisor_sum.h"

int main(int argc, char** argv) {
	unsigned long n;
	if (argc != 2 || (n = strtoul(argv[1],NULL,10)) == 0) {
		errx(1,"Error");
	}
	
	printf("divisor_sum(%lu) = %lu\n", n, divisor_sum(n));
		
	return 0;
}
