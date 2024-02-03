#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int compare_ints(const void *a, const void *b) {
    int arg1 = *(const int *)a;
    int arg2 = *(const int *)b;

    if (arg1 < arg2)
        return -1;
    if (arg1 > arg2)
        return 1;
    return 0;

    // return (arg1 > arg2) - (arg1 < arg2); // 可行的简写
    // return arg1 - arg2; // 错误的简写（若给出 INT_MIN 则会失败）
}

int main() {
    size_t size = 0;
    size_t cnt = 0;

    puts("输入排序的整数数量");
    scanf("%lu", &size);
    assert(size != 0);

    int ints[size];

    puts("输入排序的整数");
    for (; cnt < size; ++cnt)
        scanf("%d", ints + cnt);

    puts("排序前的数据");
    for (int i = 0; i < size; i++)
        printf("%d ", ints[i]);

    puts("\n排序中");
    qsort(ints, size, sizeof(int), compare_ints);

    puts("排序后的数据");
    for (int i = 0; i < size; i++)
        printf("%d ", ints[i]);
}
