
unsigned long fibo(unsigned long n) {
	unsigned long f0 = 0, f1 = 1, swp;
	while (n --> 0) {
		swp = f1;
		f1 += f0;
		f0 = swp;
	}

	return f0;
}
