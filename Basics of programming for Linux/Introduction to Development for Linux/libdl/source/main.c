#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

#include <dlfcn.h>

void (* hello) (const char*);

bool init_lib () {
	
	void* hdl = dlopen("./libhello.so", RTLD_LAZY);	
	if (NULL == hdl) {
		printf("hdl is NULL!\n");
		return false;
	}


	hello = ( void (*)(const char*) )  dlsym(hdl, "hello");
	if (NULL == hello) {
		printf("hello is NULL!\n");
		return false;
	}

	return true;
}

int main() {
	
	if ( init_lib() )
		hello("Daniiell");
	else 
		printf("Can't load library!\n");

	return 0;
}
