#include <malloc.h>

#define N (1l << 32)

int main(){
    // int array[N];
    int *ptr = (int*)malloc(sizeof(int)*N);
	//exit(0);
	free(ptr);
	// ptr[1000] = 666;
    return 0;
}
