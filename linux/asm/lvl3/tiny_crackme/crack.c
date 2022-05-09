#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define LEN 0x2df

int main(void) {
	FILE *fd;
	uint8_t b[LEN];
	uint32_t *p, sum, n, x;
	char s[5];

	fd = fopen("tiny-crackme2", "rb");
	fseek(fd, 0x8, SEEK_SET);
	fread(b, 1, LEN, fd);
	fclose(fd);

	p = (uint32_t *) b;
	sum = 0;

	for (size_t i = 0; i < LEN >> 2; ++i) {
		sum += *p;
		++p;
	}

	s[4] = 0;

	for (size_t i = 0x20; i < 0x7f; ++i) {
	for (size_t j = 0x20; j < 0x7f; ++j) {
	for (size_t k = 0x20; k < 0x7f; ++k) {
	for (size_t l = 0x20; l < 0x7f; ++l) {
		n = sum;

		s[0] = i & 0xff;
		s[1] = j & 0xff;
		s[2] = k & 0xff;
		s[3] = l & 0xff;

		x = s[3] << 0x18 | s[2] << 0x10 | s[1] << 8 | s[0];
		n += (s[1] << 0x18 | s[0] << 0x10 | s[3] << 8 | s[2]);

		n ^= 0x5508046b;

		if (x == n) puts(s);
	}
	}
	}
	}
	
	return EXIT_SUCCESS;
}
