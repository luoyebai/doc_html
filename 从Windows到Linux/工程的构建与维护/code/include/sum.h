#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>

int64_t sum(int arg_cnt, ...) {
    int64_t res = 0;
    va_list args;
    va_start(args, arg_cnt);
    for (int i = 0; i < arg_cnt; ++i) {
        res += va_arg(args, int);
    }
    va_end(args);
    return res;
}
