#include <stdio.h>

#define LEN 0xb

int main(void) {
	FILE *fd;
	char buf[LEN+1];

	fd = fopen("grainne", "rb");
	fseek(fd, 0x12e, SEEK_SET);
	fread(buf, 1, LEN, fd);
	fclose(fd);

	for (unsigned i = 0, x = 0x1a; i < LEN - 1; ++i, ++x) {
		buf[i] ^= x;
	}

	puts(buf);

	return 0;
}
