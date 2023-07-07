#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stddef.h>


#define BUFFER_SIZE 1024

void make_a_line_command(char* command_name, char* command_param, char* buffer, bool in_current_dir);

int execute_util(char* command_line, char* buffer);

int main(int argc, char** argv) {
	if (argc != 3)
		printf("error\n");  // Not enough arguments

	char * uname = argv[1];
	char * uparam = argv[2];
	//printf("Calling [%s] with param [%s]\n", uname, uparam);

	char command_buffer[BUFFER_SIZE];
	make_a_line_command(uname, uparam, command_buffer, true);
	//printf("The line is [%s]\n", command_buffer);


	char read_buffer[BUFFER_SIZE + 1];
	execute_util(command_buffer, read_buffer);

	int count = 0;
	for (int i = 0; i < strlen(read_buffer); i++) {
		if (read_buffer[i] == '0')
			count++;
	}

	printf("%d\n", count);
	return 0;
}

int execute_util(char* command_line, char* buffer) {
	FILE* pipe_file = popen(command_line, "r");

	if (NULL == pipe_file)
		return 1;

	int c = fread(buffer, sizeof(char), BUFFER_SIZE, pipe_file);
	buffer[c] = '\0';
	fclose(pipe_file);
	return 0;
}

void make_a_line_command(char* command_name, char* command_param, char* buffer, bool in_current_dir) {
	if (in_current_dir)
		strcpy(buffer, "./");
	else 
		strcpy(buffer, "");

	strcat(buffer, command_name);
	strcat(buffer, " ");
	strcat(buffer, command_param);
	
	return;
}
