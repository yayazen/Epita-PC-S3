#include <stdio.h>

const char separator[] = " ,;:!?./%*$=+)@_-('&1234567890\"\r\n";


void swap(char s[], size_t i, size_t j) {
	char tmp = s[i];
	s[i] = s[j];
	s[j] = tmp;
}


int is_sep(char s[], size_t p) {
	char c;

	for (size_t i = 0; (c = separator[i]) != '\0'; i++) {
		if (s[p-1] == c || s[p] == c || s[p+1] == c || s[p + 2] == c)
			return 1;
	}

	return 0;
}


void mix(char s[]) {
	for (size_t i = 1; s[i - 1] != '\0' && s[i] != '\0' && s[i + 1] != '\0'; ) {
		
		if (!is_sep(s, i)) {
			swap(s, i, i+1);
			i += 2;
		}
		else
			i++; 
	} 	
}


     
