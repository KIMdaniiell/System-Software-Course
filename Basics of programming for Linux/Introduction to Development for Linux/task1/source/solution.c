#include "solution.h"

int stringStat(const char* string, size_t multiplier, int* count) {
	size_t result = strlen(string);
	//printf("Длина строки: %zd\n", result);

	result *= multiplier;
	//printf("Длина строки * множитель: %zd\n", result);

	//printf("Число до +1: %d\n", *count);
	(*count)++;
	//printf("Число после +1: %d\n", *count);

	return result;
}


