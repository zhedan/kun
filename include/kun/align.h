#ifndef __KUN_ALIGN
#define __KUN_ALIGN

#include<stdlib.h>
#include<kun/types.h>
#include<kun/bitops.h>

static inline long kun_align(long n, size_t align) {
    if ( n < align) {
        g_warning("align %ld < %ld", n, align);
        abort();
    }
    return (n + align -1) & ~(align - 1);
}

static inline long kun_auto_align(long n) {
    if (n == 0 || n == 1)
        return n;

    long idx = __builtin_clzl(n);
    long mask = ((u64)~0 >> (idx + 1));
    return n & mask ? (mask + 1) << 1: n;
}

#endif
