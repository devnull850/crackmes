#include <elf.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	FILE *fd;
	uint8_t *b, *p;
	size_t len;

	fd = fopen("nasm_crack", "rb");
	
	fseek(fd, 0, SEEK_END);
	len = ftell(fd);
	fseek(fd, 0, SEEK_SET);

	b = malloc(len);
	fread(b, 1, len, fd);

	fclose(fd);

	p = b+((Elf64_Phdr *)(b+0xb0))->p_offset;

	for (size_t i = 0; i < ((Elf64_Phdr *)(b+0xb0))->p_filesz; ++i) {
		if (!(i % 0x10)) {
			printf("0x%0lx:\t",
				((Elf64_Phdr *)(b+0xb0))->p_vaddr + i);
		}

		printf("%02x", p[i]);

		if (i % 0x10 == 0xf) {
			putchar(9);

			for (int j = 0xf; j >= 0; --j) {
				putchar(p[i-j] > 0x1a ? p[i-j] : 0x2e);
			}

			putchar(0xa);
		}
		else if (i % 2 == 1) {
			putchar(0x20);
		}
	}

	putchar(0xa);

	free(b);

	return 0;
}
