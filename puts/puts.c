#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<dlfcn.h>

#define _GNU_SOURCE

int puts(const char *msg){
	int (*old_puts)(const char *message);
	int res;
	old_puts = dlsym(RTLD_NEXT, "puts");

	if(strncmp(msg, "hello", 5) == 0){
		res = old_puts("Goodbye");	
	}
	else{
		res = old_puts(msg);
	}
	return res;
}
