#define sqr(x) (x * x)

unsigned long isqrt(unsigned long n) {
	unsigned long r = n;
	
	while (sqr(r) > n) {
		r += n / r;
		r /= 2;
	}
	
	return r;
}
