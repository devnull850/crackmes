#include <stdint.h>
#include <stdio.h>

#define LEN 6

const uint32_t FACTOR = 0x3b9aca09;

int main(void) {
	char key[LEN+1];
	uint64_t arr[LEN];
	uint32_t val;

	key[LEN] = 0;

	for (uint32_t a = 0x30; a < 0x3a; ++a) {
	for (uint32_t b = 0x30; b < 0x3a; ++b) {
	for (uint32_t c = 0x30; c < 0x3a; ++c) {
	for (uint32_t d = 0x30; d < 0x3a; ++d) {
	for (uint32_t e = 0x30; e < 0x3a; ++e) {
	for (uint32_t f = 0x30; f < 0x3a; ++f) {
		key[0] = a & 0xff;
		key[1] = b & 0xff;
		key[2] = c & 0xff;
		key[3] = d & 0xff;
		key[4] = e & 0xff;
		key[5] = f & 0xff;

		arr[0] = 1;

		for (uint32_t i = 1; i < LEN; ++i) {
			arr[i] = arr[i-1] * 0x83 % FACTOR;
		}

		val = key[0];

		for (uint32_t i = 1; i < LEN; ++i) {
			val += key[i] % FACTOR * arr[i] % FACTOR;
		}

		if (val == 0x3c0431a5) puts(key);
	}
	}
	}
	}
	}
	}

	return 0;
}
