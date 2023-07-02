#include "hello.h"

#include <stdio.h>

int hello(int count){
	for (int i = 0; i < count; i++) {
		printf("%d. Hello world!\n", i+1);
	}

	return count*2;
}
