#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	uint8_t *b;
	uint32_t *p;
	FILE *fd;
	size_t len;

	fd = fopen("tiny-crackme", "rb");
	fseek(fd, 0, SEEK_END);
	len = ftell(fd);
	fseek(fd, 0, SEEK_SET);
	b = malloc(len);
	fread(b, 1, len, fd);
	fclose(fd);

	p = (uint32_t *) (b+0x4b);

	for (size_t i = 0; i < 0x2a5 >> 2; ++i) {
		*p ^= 0x3f5479f1;
		++p;
	}

	p = (uint32_t *) (b+0x19e);

	for (size_t i = 0; i < 0xf4 >> 2; ++i) {
		*p ^= 0xbeefc0da;
		++p;
	}

	fd = fopen("tiny-crackme2", "wb");
	fwrite(b, 1, len, fd);
	fclose(fd);

	return EXIT_SUCCESS;
}
