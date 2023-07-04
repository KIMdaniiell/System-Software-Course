#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <stdbool.h>

#define BUFFER_SIZE 4096 
#define PATH "/proc/"
#define PARAMETER "PPid"



int parse_line(const char* line, char* key_buffer, char* value_buffer);

int read_file(const char* path, char buffer[]);

int get_next_line(char** text_ptr, char* line_buffer);

bool string_is_number(char* string);

int get_proc_info(char* path, char* parameter, char* value) {
	char file_buf[BUFFER_SIZE + 1];

	if (read_file(path, file_buf) != 0) {
		printf("Что-то пошло не так, прочитать данные из файла не удалось!\n");
		return 1;
	}


	char* text_ptr = file_buf;
	while (text_ptr < file_buf + strlen(file_buf) ) {
		char line_buf[BUFFER_SIZE + 1];
		char key_buf[BUFFER_SIZE + 1];
		char value_buf[BUFFER_SIZE + 1];

		get_next_line(&text_ptr, line_buf);
		
		parse_line(line_buf, key_buf, value_buf);
		
		//printf("%d[%s] - [%s]\n", strcmp(key_buf, PARAMETER), key_buf, value_buf);
		if (strcmp(key_buf, parameter) == 0) {
			strcpy(value, value_buf);
			return 0;
		}
	}
	return 1;
}

int count_children(char* pid_value) {
	char text_buffer [BUFFER_SIZE + 1];

	char path[BUFFER_SIZE+1];
	strcpy(path, PATH);
	strcat(path, pid_value);
	strcat(path, "/task/");
	strcat(path, pid_value);
	strcat(path, "/children");
						
	int file_descriptor = open(path, O_RDONLY);
	read(file_descriptor, text_buffer, BUFFER_SIZE);


	int count = 0;
	int i;
	bool was_space = true;

	char pid_buffer[BUFFER_SIZE + 1];
	int pid_buffer_index = 0;

	for (i = 0; i < strlen(text_buffer); i++) {
		if (text_buffer[i] != ' ') {
			pid_buffer[pid_buffer_index++] = text_buffer[i];

			if (was_space)
				count++;
			was_space = false;
		} else {
			pid_buffer[pid_buffer_index] = '\0';
			//printf("[%s]\n", pid_buffer);

			count += count_children(pid_buffer);

			pid_buffer_index = 0;
			was_space = true;
		}
	}
	return count;
}

int main(int argc, char** argv) {
	if (argc != 2) 
		return 1;
	int count = 1;
	count += count_children(argv[1]);

	printf("%d\n", count);
}


bool string_is_number (char * string) {
	int i;
	for (i = 0; i < strlen(string); i++) {
		if (string[i] < '0' || string[i] > '9') {
			return false;
		}
	}


	return true;
}

int get_next_line (char** text_ptr, char* line_buffer) {
	char line[BUFFER_SIZE + 1];
	int len = strlen(*text_ptr); 

	int i; 
	for (i = 0; i < len && (*text_ptr)[i] != '\n'; i++) {
		line[i] = (*text_ptr)[i];
	}
	
	if (i >= len) {
		printf("[get_next_line] Что-то пошло не так! Символ '\n' не обнаружен.\n");
		return 1;
	}
	
	line[i++] = ';';
	line[i] = '\0';
	
	strcpy(line_buffer, line);
	

	*text_ptr = *text_ptr + i;
	return 0;
}


int read_file(const char* path,char buffer[]) {
	int file_descriptor = open(path, O_RDONLY);

	size_t char_read_from_file  = read(file_descriptor, buffer, BUFFER_SIZE);
	
	if (char_read_from_file < 0)
		return 1;

	return 0;
}	


int parse_line (const char* line, char* key_buffer, char* value_buffer) {
	char key[BUFFER_SIZE + 1];
	char value[BUFFER_SIZE + 1];
	int key_index = 0;
	int value_index = 0;

	int len = strlen(line);
	int i;

	// Копирование строки до символа ':'
	for (i = 0; i < len && line[i] != ':'; i++) {
		key[key_index++] = line[i];
	}

	if (i >= len) {
		printf("[parse_line] Что-то пошло не так! Символ ':' не обнаружен - конец строки: [%s]\n", line);
		return 1;
	} 

	i++;
	
	// Избавление от лишних пробелов в конце
	while ((key[key_index - 1] == ' ' || key[key_index - 1] == '\t') && key_index - 1 > 0)
		key_index--;
	key[key_index] = '\0';

	// Избавление от лишних пробелов в начале
	key_index = 0;
	while (key[key_index] == ' ' || key[key_index] == '\t') 
		key_index++;
		
	strcpy(key_buffer, key + key_index);

	
	// Копирование строки после символа ':' до символа ';'
	for (; (i<len) && (line[i] != ';'); i++) {
		value[value_index++] = line[i];
	}
	
	if (i >= len) {
		printf("[parse_line] Что-то поло не так! Символ ';' не обнаружен - конец строки: [%s]\n", line);
		return 1;
	}

	// Избавление от лишних пробелов в конце
	while ((value[value_index - 1] == ' ' || value[value_index - 1] == '\t') && value_index - 1 > 0)
		value_index--;
	value[value_index] = '\0';

	// Избавление от лишних пробелов в начале
	value_index = 0;
	while (value[value_index] == ' ' || value[value_index] == '\t') 
		value_index++;

	strcpy(value_buffer, value + value_index);
	return 0;
}

