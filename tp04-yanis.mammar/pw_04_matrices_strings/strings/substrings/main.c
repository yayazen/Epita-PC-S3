#include <stdio.h>
#include <err.h>

int main(int argc, char **argv) {

	if (argc != 3)
		errx(1, "Usage: str1 str2");

	int i = 0, m = 0, pos = -1;
	
	while (argv[1][i] != '\0' && argv[2][m] != '\0') {
		if (argv[1][i] == argv[2][m]) {
			if (pos == -1)
				pos = i;
			
			i++;
			m++;
		}

		else if (m != 0) {
			pos = -1;
			m = 0;
		}
		
		else
			i++;

	}

	
	if (argv[2][m] == '\0')
		printf("%s\n%*c\n", argv[1], pos + 1, '^'); 

	else
		printf("Not Found!");

	return 0;

}
