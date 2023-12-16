// safe, but no optimize for const expression
#define min(x, y) ({ \
    typeof(x) __x = x; \
    typeof(y) __y = y; \
    __x > __y ? __y: __x; })
