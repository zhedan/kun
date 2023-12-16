#ifndef __BITOPS
#define __BITOPS

#include<kun/math.h>
#include<asm/bitops.h>

#define BITS_PER_LONG 64

void bop_show(long n);

#ifndef __ffs
#error "__ffs not defined"
#endif

/*
 * @addr: bitmap base addr
 * @sz: bitmap size in bits
 * @offset: offset in bits in bitmap, start at 0
 * Return: idx in bitmap if found, start at 0, else -1
 */
static inline int find_next_bit(void *addr, size_t sz, size_t offset) {
    int idx = -1;
    size_t offset_l = offset / BITS_PER_LONG;
    long *start = addr + offset_l;
    for (size_t i = offset_l; i * BITS_PER_LONG < sz; i ++) {
        long cur = *(long*) (start + i);
        if (cur) {
            idx = min(i * BITS_PER_LONG + __ffs(cur), sz);
            break;
        }
    }
    return idx;
}

static inline int find_first_bit(void *addr, size_t sz) {
    return find_next_bit(addr, sz, 0);
}

#endif
