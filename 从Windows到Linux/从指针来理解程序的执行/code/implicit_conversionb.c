#include <stdio.h>
#include <stdlib.h>

#define PUTSX(x) printf("%s的地址:%X\n", #x, (void *)(&x))

int main() {
    int x[2] = {114, 514};
    PUTSX(x);

    // for i in range(3):
    // print(f"PUTSX({i}[x]); PUTSX(x[{i}]);")

    PUTSX(0 [x]);
    PUTSX(x[0]);
    PUTSX(1 [x]);
    PUTSX(x[1]);
    PUTSX(2 [x]);
    PUTSX(x[2]);

    printf("x[2]初始值: %d\n", x[2]);
    //! Error
    x[2] = 1919810;

    // x[2] = 1919810;
    // printf("x[2]现在的值: %d\n", x[2]);
    // exit(0);

    return 0;
}
