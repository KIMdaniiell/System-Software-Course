#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stddef.h>


#define BUFFER_SIZE 1024

void make_a_line_command(char* command_name, char* command_param, char* buffer, bool in_current_dir);

int execute_util(char* command_line);

int main(int argc, char** argv) {
	if (argc != 3)
		printf("error\n");  // Not enough arguments

	char * uname = argv[1];
	char * uparam = argv[2];
	//printf("Calling [%s] with param [%s]\n", uname, uparam);

	char command_buffer[BUFFER_SIZE];
	make_a_line_command(uname, uparam, command_buffer, false);
	//printf("The line is [%s]\n", command_buffer);

	int count = execute_util(command_buffer);
	
	printf("%d\n", count);
	return 0;
}

int execute_util(char* command_line) {
	FILE* pipe_file = popen(command_line, "r");
	char buffer [BUFFER_SIZE + 1];

	if (NULL == pipe_file)
		return -1;

	int c;
	int i;
	int count = 0;
       	while ((c = fread(buffer, sizeof(char), BUFFER_SIZE, pipe_file)) != 0) {
		buffer[c] = '\0';
		for (i = 0; i < strlen(buffer); i++) {
			if (buffer[i] == '0')
				count++;
		}
	}

	fclose(pipe_file);
	return count;
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
