#include <stdio.h>

#define LEN 8

int main(void) {
	unsigned n;
	char s[LEN+1];

	n = 0x4919ab9;

	for (int i = LEN - 1; i >= 0; --i) {
		if ((n & 0xf) < 0xa) {
			s[i] = ((n & 0xf) + 0x30) & 0xff;
		}
		else {
			s[i] = (((n - 0xa) & 0xf) + 0x41) & 0xff;
		}

		n >>= 4;
	}

	s[LEN] = 0;

	puts(s);

	return 0;
}

