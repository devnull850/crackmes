#include <stdint.h>
#include <stdio.h>
#include <string.h>

const uint64_t n = 0x405e800000000000;

int main(void) {
	double d;
	memcpy(&d, &n, 0x8);
	printf("%lf\n", d);
	return 0;
}
