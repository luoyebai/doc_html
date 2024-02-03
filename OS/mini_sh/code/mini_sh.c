#include <fcntl.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdbool.h>
#include <sys/syscall.h>

#define PRINT_D(msg) _print("\e[32m",-3); \
	print(msg); \
	print("\e[0m");

#define PRINT_E(msg) _print("\e[31m",-3); \
	print(msg); \
	print("\e[0m");

enum {EXEC = 1, REDIR, PIPE, LIST, BACK};

struct CMD{
	int type;
};

long syscall(int num, ...) {
  va_list ap;
  va_start(ap, num);
  register long a0 asm ("rax") = num;
  register long a1 asm ("rdi") = va_arg(ap, long);
  register long a2 asm ("rsi") = va_arg(ap, long);
  register long a3 asm ("rdx") = va_arg(ap, long);
  register long a4 asm ("r10") = va_arg(ap, long);
  va_end(ap);
  asm volatile("syscall"
    : "+r"(a0) : "r"(a1), "r"(a2), "r"(a3), "r"(a4)
    : "memory", "rcx", "r8", "r9", "r11");
  return a0;
}

void print(const char*s){
	syscall(SYS_write,1, s, sizeof(s)+1);
}

void _print(const char*s,int add){
	syscall(SYS_write,1, s, sizeof(s)+1+add);
}


_Bool getcmd(char* buf, int nbuf){

	PRINT_D("[mini_sh] >");

	struct CMD cmd;
	for (int i = 0; i < nbuf; i++) buf[i] = '\0';
	  while (nbuf-- > 1) {
		  int nread = syscall(SYS_read, 0, buf, 1);
		  if (nread <= 0) return false;
		  if (*(buf++) == '\n') break;
	  }
	  return true;
}

_Bool runcmd(short type,short cmd,char* buf,int nbuf){
	return true;
}

void _start(){
	static char buf[100];
	char mini_sh_say[100]="\033[32m----this is a mini shell----\033[0m\n";
	syscall(SYS_write,1,mini_sh_say, 100);

	while(getcmd(buf, sizeof(buf)) >= 0){
		if(buf[0]==' ')
			continue;
		if(buf[0]=='c' && buf[1] == 'd' && buf[2] == ' '){
			if(syscall(SYS_chdir,buf+3)<0) {
			}
		}
	}
	syscall(SYS_exit,0);
}





