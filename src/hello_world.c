#include<glib/gprintf.h>
#include<kun/align.h>
#include<kun/bitops.h>

#define BITS_PER_LONG 64
#define BITMAP_LAST_WORD_MASK(nbits) (~0UL >> (-(nbits) & (BITS_PER_LONG - 1)))

int main() {
    for (int i; i < 100; i++) {
        printf("%d %ld\n", i, kun_auto_align(i));
    }
    return 0;
}
