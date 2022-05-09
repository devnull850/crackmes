#include <stdio.h>

const char FILENAME[] = "./crackMe-by-m00ny-1";

int main(void) {
	FILE *fd;

	fd = fopen("arg", "wb");

	fputc(FILENAME[5], fd);
	fputc(0x30, fd);
	fputc(FILENAME[2], fd);
	fputc(FILENAME[6], fd);

	fclose(fd);

	return 0;
}
