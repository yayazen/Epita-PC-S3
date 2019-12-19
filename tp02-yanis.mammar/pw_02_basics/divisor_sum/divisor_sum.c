#define sqr(x) (x * x)

unsigned long divisor_sum(unsigned long n) {
	unsigned long s = (n == 1) ? 0 : 1;

	for (unsigned long i = 2; sqr(i) <= n; i++) {
		if (n % i == 0) {
			s += (n / i == i) ? i : i + n / i;
			
		}
	}
	return s;
}
