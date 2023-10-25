#include <stdio.h>

#define DEBUG 1
#define N 30
#define PUTSX(x) if(DEBUG) printf("%s的地址:%X\n", #x, (void *)(&x))
#define PUTSV(x,type) if(DEBUG) printf("%s的值:%"#type"\n", #x,x)

int global_x = 0;

void callBack(_Bool (*response_f)(), void (*callback_f)(), _Bool (*stop_f)()) {
    while (stop_f()) {
		++global_x;
        if (!response_f()) 
			continue;
            callback_f();
	}
    return;
}

_Bool judgeXParity() { return global_x % 2 == 0; }

_Bool compareXSizes() { return global_x < N; }

int main(int argc, char *argv[]) {
    PUTSX(main);
	PUTSV(global_x,d);
    callBack(judgeXParity, main, compareXSizes);
    return 0;
}
