#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEN 0x10

const char set[] = "0123456789"
		   "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                   "abcdefghijklmnopqrstuvwxyz";

int main(void) {
	char serial[LEN+1];
	FILE *fd;
	double x, y, z;
	int a, b, c;
	uint8_t arr[0x8000];

	srand(time(NULL));

	fd = fopen("muldimalph", "rb");
	fseek(fd, 0x2020, SEEK_SET);
	fread(arr, 1, 0x8000, fd);
	fclose(fd);

	for (size_t i = 0; i < 3; ++i) {
		serial[i] = set[rand() % 0x3e];
	}

	x = (double) serial[0] / 122.0;
	y = (double) serial[1] / 122.0;
	z = (double) serial[2] / 122.0;

	for (size_t i = 3; i < LEN; ++i) {
		a = (int) (i*z + i*z);
		b = (int) (i*y + i*y);
		c = (int) (i*x + i*x);

		serial[i] = arr[32*(b + 32*a) + c] & 0xff;
	}

	serial[LEN] = 0;

	fd = fopen("serial", "wb");
	fwrite(serial, 1, LEN, fd);
	fclose(fd);

	return EXIT_SUCCESS;
}
