#include<stdio.h>
#include<unistd.h>
#include<dlfcn.h>
#include<openssl/ssl.h>

#define _GNU_SOURCE

int SSL_write(SSL *context, const void *buffer, int bytes){
	
	int (*old_ssl_write)(SSL *context, const void *buffer, int bytes);
	old_ssl_write = dlsym(RTLD_NEXT, "SSL_write");
	FILE *log = fopen("logfile", "a+");
	fprintf(log, "Process %d:\n%s", getpid(), (char *)buffer);
	fclose(log);
	return old_ssl_write(context, buffer, bytes);
}
