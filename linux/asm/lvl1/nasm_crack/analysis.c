#include <elf.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include <capstone/capstone.h>

int main(void) {
	FILE *fd;
	uint8_t *b;
	size_t len, cnt;
	csh handle;
	cs_insn *insn;

	fd = fopen("nasm_crack", "rb");
	
	fseek(fd, 0, SEEK_END);
	len = ftell(fd);
	fseek(fd, 0, SEEK_SET);

	b = malloc(len);
	fread(b, 1, len, fd);

	fclose(fd);

	cs_open(CS_ARCH_X86, CS_MODE_64, &handle);
	cnt = cs_disasm(
		handle,
		b+((Elf64_Phdr *)(b+0x78))->p_offset,
		((Elf64_Phdr *)(b+0x78))->p_filesz,
		((Elf64_Phdr *)(b+0x78))->p_vaddr,
		0,
		&insn);

	for (size_t i = 0; i < cnt; ++i) {
		printf("0x%0lx:\t%s\t\t%s\n", insn[i].address,
			insn[i].mnemonic, insn[i].op_str);
	}

	cs_free(insn, cnt);
	cs_close(&handle);

	free(b);

	return 0;
}
