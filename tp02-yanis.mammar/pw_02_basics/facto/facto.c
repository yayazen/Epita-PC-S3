
unsigned long facto(unsigned long n) {
	unsigned long f = 1;
	for (; n > 1; f *= n--);
	
	return f;
}
