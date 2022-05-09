#include <stdio.h>

int main(void) {
	for (unsigned i = 0; i < 0xa; ++i) {
		printf("%02x", "4@ss724536"[i]);
	}

	putchar(0xa);

	return 0;
}
