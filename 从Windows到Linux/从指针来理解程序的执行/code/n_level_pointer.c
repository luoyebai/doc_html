#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

// print("#define POINTER1 *")
// for i in range(10):
	// print(f"#define POINTER{2**(i+1)} POINTER{2**i} POINTER{2**i}")
#define POINTER1 *
#define POINTER2 POINTER1 POINTER1
#define POINTER4 POINTER2 POINTER2
#define POINTER8 POINTER4 POINTER4
#define POINTER16 POINTER8 POINTER8
#define POINTER32 POINTER16 POINTER16
#define POINTER64 POINTER32 POINTER32
#define POINTER128 POINTER64 POINTER64
#define POINTER256 POINTER128 POINTER128
#define POINTER512 POINTER256 POINTER256
#define POINTER1024 POINTER512 POINTER512



int main(){
	void POINTER1024  x;
}
