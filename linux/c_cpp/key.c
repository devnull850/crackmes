#include <stdio.h>

int main(void) {
    char s[5];

    s[0] = 0xcb ^ 0x13 ^ 0x37;
    s[1] = 0x16 ^ 0x90 ^ 0xf ^ 0x37;
    s[2] = 0xad;
    s[3] = 0xe9 ^ 0x37;
    s[4] = 0;

    printf("0x%x\t\t%u\n", *((unsigned *)s), *((unsigned *)s));

    return 0;
}
