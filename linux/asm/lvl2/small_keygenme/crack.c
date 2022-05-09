#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEN 0x10

const unsigned a[] = { 0x2, 0x5, 0x7, 0xd, 0xf };

int main(void) {
	char serial[LEN+1];
	
	srand(time(NULL));

	for (unsigned i = 0; i < LEN; ++i) {
		serial[i] = a[rand() % 5] & 0xf;

		if (serial[i] < 0xa) {
			serial[i] += 0x30;
		}
		else {
			serial[i] = rand() % 2 ?
				serial[i] + 0x37 : serial[i] + 0x57;
		}
	}

	serial[LEN] = 0;

	puts(serial);

	return EXIT_SUCCESS;
}
