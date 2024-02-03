obj = mini_sh.o sh-xv6.o test.o

edit: ${obj}
	cc -c -ffreestanding -fno-stack-protector mini_sh.c && \
		ld mini_sh.o -o mini_sh && \
		cc -c -ffreestanding  -fno-stack-protector sh-xv6.c && \
		ld sh-xv6.o -o sh &&\
		cc -c -ffreestanding  -fno-stack-protector test.c && \
		ld test.o -o test \

mini_sh.o : mini_sh.c
sh-xv6.o : sh-xv6.c
test.o : test.c
