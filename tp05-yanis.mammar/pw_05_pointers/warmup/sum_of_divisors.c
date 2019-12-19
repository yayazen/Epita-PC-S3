# include <stdio.h>

#define sqr(x)	((x) * (x))

unsigned long sum_of_divisors(unsigned long n, size_t *count)
{
	unsigned long s = *count = (n == 1) ? 0 : 1;

	for (unsigned long i = 2; sqr(i) <= n; i++) {
		if (n % i == 0) {
			s += i;
			(*count)++;
	
			if (n / i != i) {
				s += n / i;
				(*count)++;
			}
		}
	}

	return s;
}

int main()
{
    unsigned long x;
    unsigned long sum;
    size_t count;

    x = 28;
    sum = sum_of_divisors(x, &count);
    printf("x = %lu\n", x);
    printf("sum   = %lu\n", sum);
    printf("count = %zu\n\n", count);

    x = 100;
    sum = sum_of_divisors(x, &count);
    printf("x = %lu\n", x);
    printf("sum   = %lu\n", sum);
    printf("count = %zu\n", count);
}
