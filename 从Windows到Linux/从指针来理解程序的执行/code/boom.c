#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

#define GB (double)(1l<<30)
#define MB (double)(1l<<20)

_Bool check(void* ptr) {
	if (ptr != NULL) 
		return true;
	perror("\033[31m申请失败");
	return false;
}

int main(){
	long long total_malloc = 0;

remalloc:
	void* ptr = malloc(13l << 23);
	if(!check(ptr)) goto end;
	long long nbytes = malloc_usable_size(ptr);
	memset(ptr,255,nbytes);

	total_malloc += nbytes;

	printf("现在开辟的内存：%.2lfMB/%.2lfGB\n", (total_malloc/MB),(total_malloc/GB));
	usleep(0.5e6);

	// loop
	if(total_malloc > 2*GB)
		goto end;
	goto remalloc;

end:
	free(ptr);
	return 0;
}

