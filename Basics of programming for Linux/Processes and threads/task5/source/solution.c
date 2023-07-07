#include <unistd.h>
#include <stdio.h>

#define ROOT_DIR "/"


int close_standart_io() {
	int result = 0;
	
	result = fclose(stdin);
	if (result != 0)
		return result;

	fclose(stdout);
	if (result != 0)
		return result;

	return fclose(stderr);
}


void print_own_pid() {
	printf("%d\n", getpid());
	return;
}


int set_new_session_id() {
	pid_t session_id = setsid();
	if (session_id == -1) 
		return 1;
	return 0;
}

int change_dir(const char* path) {
	return chdir(path);	
}


int child_runnable() {
	//printf("[CHILD] [child_runnable] - started\n");

	int result = 0;

	result = change_dir(ROOT_DIR);
	if (result != 0) 
		return result;
	//printf("[CHILD] [child_runnable] - changed dir\n");

	result = set_new_session_id();
	if (result != 0) 
		return result;
	//printf("[CHILD] [child_runnable] - set new session id\n");

	print_own_pid();

	result = close_standart_io();
	//printf("[CHILD] [child_runnable] - closed IO files\n");

	//printf("[CHILD] [child_runnable] - end\n"); - не выведется, т.к. закрыты файлы ввода/вывода
	
	pause();
	return result;
}


int main() {
	
	pid_t pid = fork();

	if (pid == 0) {
		//printf("[CHILD] Я ребёнок!\n");

		if (child_runnable() != 0) {
			//printf("[CHILD] Что-то пошло не так!\n");
			return 1;
		}

		return 0;
	} else {
		//printf("[PARENT] Я родитель!\n");
		return 0;
	}
	
}
