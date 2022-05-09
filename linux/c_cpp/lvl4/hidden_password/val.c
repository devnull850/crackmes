#include <stdio.h>

int main(void) {
	unsigned n;

	for (unsigned long i = 0; i < 0x100000000; ++i) {
		if (i % 0x7b  == 0x5c  &&
		    i % 0x1c8 == 0x1d  &&
		    i % 0x315 == 0x17c &&
		    i % 0x3db == 0x2   &&
		    i % 0x28e == 0x1f1 &&
		    i % 0x141 == 0x128) {
			n = i & 0xffffffff;
		}
	}

	printf("0x%0x %u %d\n", n, n, n - 0x7fffffff);

	return 0;
}
