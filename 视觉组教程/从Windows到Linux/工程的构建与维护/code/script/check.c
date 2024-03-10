#include <stdio.h>
#include <stdlib.h>

struct X {
    struct X* next;
};

int main(int argc, char* argv[]) {
    struct X* p = NULL;
    printf("%p", p->next);
    return 0;
}
