 #include <stdlib.h>

#define InitSize 10

typedef struct {
	int *data;
	int MaxSize;
	int length;
}SeqList;

void InitList(SeqList & L){
	L.data = (int*)malloc(InitSize*sizeof(int));
	L.length = 0;
	L.MaxSize = InitSize;
}

int main(){
	SeqList L;
	InitList(L);
}
