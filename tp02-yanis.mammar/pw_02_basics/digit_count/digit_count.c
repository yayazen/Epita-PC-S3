
unsigned char digit_count(unsigned long n) {
	unsigned char count = 1;
	for (; (n /= 10) != 0; count++);

	return count;
}
