#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	srand((unsigned)time(NULL));
	int x = random();
	printf("%d\n",x);
	int(*p)()=main;
	//bug
	//ex:
	if(x % 2)
		free(p);
	return 0;
}
