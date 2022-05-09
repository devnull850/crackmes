#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEN 0x16

int main(void) {
	char ch;
	srand(time(NULL));

	for (size_t i = 0; i < LEN; i+=2) {
		ch = (rand() % 0x58 + 0x21) & 0xff;
		printf("%c%c", ch, ch+2);
	}

	putchar(0xa);

	return EXIT_SUCCESS;
}
