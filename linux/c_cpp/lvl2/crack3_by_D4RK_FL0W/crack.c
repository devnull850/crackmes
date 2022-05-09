#include <stdio.h>

#define LEN 0xa

int get_digit(int *);

int main(void) {
	int a1[LEN], a2[LEN], a3[LEN], a4[LEN];
	FILE *fd;

	fd = fopen("crack3-by-D4RK_FL0W", "rb");

	fseek(fd, 0x3080, SEEK_SET);
	fread(a1, 4, LEN, fd);

	fseek(fd, 0x18, SEEK_CUR);
	fread(a2, 4, LEN, fd);

	fseek(fd, 0x18, SEEK_CUR);
	fread(a3, 4, LEN, fd);

	fseek(fd, 0x18, SEEK_CUR);
	fread(a4, 4, LEN, fd);

	fclose(fd);

	printf("%d\n%d\n%d\n%d\n", get_digit(a1),
		get_digit(a2), get_digit(a3), get_digit(a4));

	return 0;
}

int get_digit(int *p) {
	unsigned x, y, z;

	x = 0;
	y = 0;

	for (unsigned i = 0; i < LEN; ++i) {
		y |= p[i] & x;
		x ^= p[i];
		z = ~(x & y);
		x &= z;
		y &= z;
	}

	return (int) x;
}
