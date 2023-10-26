#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define PUTSX(x)  printf("%s的地址:%X\n", #x, (void *)(&x))

#define TO_INTX(x) (long long)(&x)

int add(int x,int y){
	return x+y;
}

int main(){
	printf("进程号pid:%d\n",getpid());
	PUTSX(main);
	PUTSX(add);
	printf("地址编号的差:%ld\n",TO_INTX(main)-TO_INTX(add));
	int(*add_ptr)(int,int) = &add;
	int* ptr = (int*)&main;
	ptr -=5;
	printf("ptr存下的地址:%X\n",ptr);
	getchar();
	*ptr = 114514;
	return 0;
}
