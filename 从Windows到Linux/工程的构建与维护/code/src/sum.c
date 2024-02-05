#include "sum.h"

int64_t sum(int arg_n,...){
	int64_t result = 0;
	va_list arg_list;
	va_start(arg_list, arg_n);
	for(short i = 0;i < arg_n;++i){
		result += va_arg(arg_list,int64_t);
	}
	va_end(arg_list);
	return result;
}
