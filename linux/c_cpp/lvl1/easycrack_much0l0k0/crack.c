#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEN 0x27

int is_set1_range(char);
void generate_chars(char *, int, size_t, size_t);

int main(void) {
	char s[LEN+1];
	FILE *fd;

	srand(time(NULL));

	for (size_t i = 0; i < LEN; ++i) s[i] = 0;

	s[0x07] = 0x2d;
	s[0x0f] = 0x2d;
	s[0x17] = 0x2d;
	s[0x1f] = 0x2d;

	generate_chars(s, 1, 0x00, 0x07);
	generate_chars(s, 2, 0x08, 0x0f);
	generate_chars(s, 3, 0x10, 0x17);
	generate_chars(s, 4, 0x18, 0x1f);
	generate_chars(s, 5, 0x20, 0x27);

	s[LEN] = 0;

	fd = fopen("args", "wb");
	fprintf(fd, "check %s", s);
	fclose(fd);

	return EXIT_SUCCESS;
}

void generate_chars(char *s, int cnt, size_t start, size_t end) {
	for (size_t c = 0, j, k; c < cnt; ) {
		j = rand() % 6 + start + 1;
		if (is_set1_range(s[j])) continue;

		k = rand() % 4;

		switch (k) {
			case 0:
				s[j] = 0x25;
				break;
			case 1:
				s[j] = 0x2b;
				break;
			case 2:
				s[j] = 0x3d;
				break;
			case 3:
				s[j] = 0x40;
				break;
		}

		++c;
	}

	for (size_t i = start, k; i < end; ++i) {
		if (is_set1_range(s[i])) continue;

		k = rand() % 3;

		switch (k) {
			case 0:
				s[i] = 0x30 + rand() % 0xa;
				break;
			case 1:
				s[i] = 0x41 + rand() % 0x1a;
				break;
			case 2:
				s[i] = 0x61 + rand() % 0x1a;
				break;
		};
	}
}

int is_set1_range(char c) {
	return (c > 0x22 && c <= 0x2b) || (c > 0x3b && c <= 0x40);
}

