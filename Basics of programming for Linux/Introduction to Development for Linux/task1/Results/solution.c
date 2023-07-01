#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include "solution.h"

int stringStat(const char* string, size_t multiplier, int* count) {
	size_t result = strlen(string);
	//printf("Длина строки: %zd\n", result);

	result *= multiplier;
	//printf("Длина строки * множитель: %zd\n", result);

	(*count)++;

	return result;
}


