#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEN 0x2f

int main(void) {
	unsigned sum, i, flag, r;
	char key[LEN+1];

	srand(time(NULL));

	flag = 1;

	while (flag) {
		sum = 0x32;
		i = 0;

		while (i < LEN) {
			r = rand() % 0xa;
			key[i] = (r + 0x30) & 0xff;
			sum -= r;
			++i;

			if (!sum) {
				flag = 0;
				break;
			}
		}

		if (key[i-1] < 0x33) flag = 1;
	}

	key[i] = 0;

	printf("%s", key);

	return 0;
}
