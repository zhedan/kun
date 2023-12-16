#ifndef __X86_BITOPS
#define __X86_BITOPS

static __always_inline unsigned long variable__ffs(unsigned long word)
{
    asm("rep; bsf %1,%0"
        : "=r" (word)
        : "rm" (word));
    return word;
}

/**
 * __ffs - find first set bit in word
 * @word: The word to search
 *
 * Undefined if no bit exists, so code should check against 0 first.
 */

#define __ffs(word)             \
    (__builtin_constant_p(word) ?       \
     (unsigned long)__builtin_ctzl(word) :  \
     variable__ffs(word))

#endif
