#include <stdio.h>
#include "mix.h"

int main(int argc, char **argv) {
	char def[] = "This is the default text.";

	char *p = (argc != 2) ? def : argv[1];
	
	printf("%s\n", p);
	mix(p);
	printf("%s\n", p);

	return 0;
}
