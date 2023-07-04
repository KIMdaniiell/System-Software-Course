#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1000


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


int main () {
	char key_buffer[BUFFER_SIZE + 1];
	char value_buffer[BUFFER_SIZE + 1];
	char* test_lines[4];
	test_lines[0] = "Key1:value1;";
	test_lines[1] = "     Key2      :                 value2                          ;";
	test_lines[2] = "   Key3                       value3                          ;";
	test_lines[3]= "   Key4      :	               value4                          ";

	for (int test_index = 0; test_index < 4; test_index ++) {
		char* test_line = test_lines[test_index];
		int result = parse_line(test_line, key_buffer, value_buffer);
		if (result) {
			printf("[Main] Test #%d - [%s]  failed!\n\n", test_index + 1, test_lines[test_index]);
			continue;
		}
		printf("[Main] Test #%d - [%s]\n[Main]\tKey: [%s]\n[Main]\tValue: [%s]\n\n", test_index + 1, test_lines[test_index], key_buffer, value_buffer);
	}
}
