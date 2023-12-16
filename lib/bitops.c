#include<stdio.h>
#include<kun/bitops.h>

void bop_show(long n) {
    printf("0x%lx\n", n);
    printf("0b");
    for (int i = BITS_PER_LONG - 1; i >= 0; i --) {
        printf("%ld", (n >> i) & 0x1);
    }
    printf("\n");
}
