#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>

#include <dlfcn.h>


int (*plugin_function)(int arg);


bool init_lib(const char* lib_name, const char* func_name ) {

	void* hdl = dlopen(lib_name, RTLD_LAZY);
	if (NULL == hdl) 
		return false;
	

	plugin_function = (int (*)(int)) dlsym(hdl, func_name);
	if (NULL == plugin_function) 
		return false;

	return true;
}

int main(int args_count, char** arg_values) {
	if (args_count != 4) {
		return 1;
	}

	char* lib_name = *++arg_values;
	char* func_name = *++arg_values;
	int func_arg = atoi(*++arg_values);
	
	if (!init_lib(lib_name, func_name)) {
		return 1;
	}

	printf("%d\n", plugin_function(func_arg));

	return 0;
}


