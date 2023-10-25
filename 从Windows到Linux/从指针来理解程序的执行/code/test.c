#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PUT_INFO printf("\n[%ld|%s:%d]", (long)time(NULL), __FILE__, __LINE__)
#define PUTX(x)                                                                \
    PUT_INFO;                                                                  \
    printf("%s的地址:%X\n", #x, (void *)(&x))
#define PUTXN(x, type)                                                         \
    PUT_INFO;                                                                  \
    printf("%s的值/地址:%" #type "/%X\n", #x, x, (void *)(&x))

// #define GOTO goto

#define RANGE(n) for (int64_t i = 0; i < n; ++i)
#define FOR(start, end, step)                                                  \
    assert(sizeof(start) == sizeof(int));                                      \
    assert(sizeof(end) == sizeof(int));                                        \
    assert(sizeof(step) == sizeof(int));                                       \
    for (int64_t i = start; i < end; i += step)

void F(int x) {
    PUTX(x);
    return;
}

int main(int argc, const char *argv[]) {
    PUTX(main);
    static int x = 0;
    {
        PUTXN(x, d);
        int x = 10;
        PUTXN(x, d);
    }

    PUTXN(x, d);

    RANGE(10) { printf("hello world!%d\n", i); }

    FOR(0, 100, 20) { printf("hello world!%d\n", i); }

    return 0;
}
