#include <malloc.h>
#include <stdbool.h>

#define N (1l << 32)

_Bool check(void* ptr) {
	if (ptr != NULL) 
		return true;
	perror("\033[31m申请失败");
	return false;
}

int main(){
    // int array[N];
    int *ptr = (int*)malloc(sizeof(int)*N);
	if (!check(ptr)) return 1;
	//exit(0);
	free(ptr);
	// ptr[1000] = 666;
    return 0;
}
