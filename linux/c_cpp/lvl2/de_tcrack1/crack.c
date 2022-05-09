#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	char *s;
	unsigned len;
	FILE *fd;

	srand(time(NULL));

	len = rand() % 0xb + 0xa;

	s = malloc(len + 1);

	for (unsigned cnt = 0, i; cnt < 3; ) {
		if ((i = rand() % len & 0xffffffff) == 4) continue;

		if (s[i] != 0x62) {
			s[i] = 0x62;
			++cnt;
		}
	}

	s[4] = 0x40;

	for (size_t i = 0, t; i < len; ++i) {
		if (s[i] == 0x62 || i == 4) continue;

		s[i] = rand() % 2 ? 0x41 : 0x61;
		while ((t = rand() % 0x1a) == 1);
		s[i] += t;
	}

	s[len] = 0;

	fd = fopen("arg", "wb");
	fwrite(s, 1, len, fd);
	fclose(fd);

	free(s);

	return 0;
}
