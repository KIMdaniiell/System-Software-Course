#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>

#include <dlfcn.h>


int (*plugin_function)(int arg);


bool init_lib(const char* lib_name, const char* func_name ) {

	void* hdl = dlopen(lib_name, RTLD_LAZY);
	if (NULL == hdl) {
		//printf("Библитека не найдена!\n");
		return false;
	}

	plugin_function = (int (*)(int)) dlsym(hdl, func_name);
	if (NULL == plugin_function) {
		//printf("Функция не найдена\n");
		return false;
	}

	return true;
}


// arg1 - имя динамической библиотеки
// arg2 - имя вызываемой функции
// arg3 - аргумент функции
void main(int args_count, char** arg_values) {
	if (args_count != 4) {
		printf("Invalid arguments!\n");
		return;
	}

	char* lib_name = *++arg_values;
	//printf("Имя динамической библиотеки: %s\n", lib_name);
	char* func_name = *++arg_values;
	//printf("Имя вызываемой функции: %s\n", func_name);
	int func_arg = atoi(*++arg_values);
	//printf("Аргумент функции: %d\n", func_arg); 
	
	if (!init_lib(lib_name, func_name)) {
		//printf("Что-то пошло не так!\n");
		return;
	}

	//printf("\n");
	printf("%d\n", plugin_function(func_arg));

	return;
}


