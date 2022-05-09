#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include <capstone/capstone.h>

#define LEN 0xc5

int generate_byte(void);

int main(void) {
	uint8_t b[LEN], c;
	FILE *fd;
	unsigned i, checksum;
	csh handle;
	cs_insn *insn;
	size_t cnt;

	fd = fopen("hidden_password", "rb");
	fseek(fd, 0x11b3, SEEK_SET);

	for (i = 0; i < 9; ++i) {
		fseek(fd, 2, SEEK_CUR);
		fread(b + i * 0x10, 1, 8, fd);
		fseek(fd, 2, SEEK_CUR);
		fread(b + i * 0x10 + 8, 1, 8, fd);
		if (i < 8) fseek(fd, 0xe, SEEK_CUR);
	}

	for (; i < 0xc; ++i) {
		fseek(fd, 0x8, SEEK_CUR);
		fseek(fd, 2, SEEK_CUR);
		fread(b + i * 0x10, 1, 8, fd);
		fseek(fd, 2, SEEK_CUR);
		fread(b + i * 0x10 + 8, 1, 8, fd);
	}

	fseek(fd, 0xb, SEEK_CUR);
	fread(b + i * 0x10, 1, 4, fd);
	fseek(fd, 0x3, SEEK_CUR);
	fread(b + i * 0x10 + 4, 1, 1, fd);

	fclose(fd);

	checksum = 0;

	for (unsigned i = 0; i < LEN; ++i) {
		c = generate_byte();
		b[i] ^= c;
		checksum = checksum + i * b[i];
	}

	printf("checksum: 0x%0x\n\n", checksum);

	cs_open(CS_ARCH_X86, CS_MODE_64, &handle);
	cnt = cs_disasm(handle, b, LEN, 0, 0, &insn);

	for (size_t j = 0; j < cnt; ++j) {
		printf("0x%0lx:\t%s\t\t%s\n", insn[j].address,
			insn[j].mnemonic, insn[j].op_str);
	}

	cs_free(insn, cnt);
	cs_close(&handle);

	fd = fopen("hidden_bytes", "wb");
	fwrite(b, 1, LEN, fd);
	fclose(fd);

	return 0;
}

int generate_byte(void) {
	static uint64_t n = 0x8000203d;

	n *= 0x41c64e6d;
	n += 0x3039;

	return (n >> 0x10) & 0x7fff;
}
