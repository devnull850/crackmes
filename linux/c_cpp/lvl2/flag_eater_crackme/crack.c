#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEN 0x1e

int isprime(char);
int isprintable(char);

int main(void) {
	unsigned arr[LEN];
	char flag[LEN+1], c;
	unsigned r;
	FILE *fd;

	srand(time(NULL));

	fd = fopen("chall", "rb");
	fseek(fd, 0x3060, SEEK_SET);
	fread(arr, 4, LEN, fd);
	fclose(fd);

	for (unsigned i = 0; i < LEN; ++i) {
		if (arr[i] >= 0x30) {
			flag[i] = ((arr[i] << 1) | 1) & 0xff;
		}
		else {
			do {
				r = rand() % 0x10;
				c = (arr[i] << 4 | r) & 0xff;
			} while (isprime(c) || !isprintable(c));

			flag[i] = c;
		}
	}

	flag[LEN] = 0;

	puts(flag);

	return 0;
}

int isprime(char c) {
	for (int x = 2; c >= x * x; ++x) {
		if (!(c % x)) return 0;
	}

	return 1;
}

int isprintable(char c) {
	return c >= 0x21 && c < 0x7b;
}
