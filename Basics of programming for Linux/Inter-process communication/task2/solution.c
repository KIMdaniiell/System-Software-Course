#include <stdbool.h>
#include <fcntl.h>
#include <sys/select.h>
#include <stddef.h>
#include <unistd.h>
#include <stdio.h>

#define BUFFER_SIZE 1024

int main() {
	int in1 = open("./in1", O_RDONLY);
	int in2 = open("./in2", O_RDONLY);

	if (in1 == -1 || in2 == -1)
		return 1;

	fd_set watch_list;
	int count = 0;
	bool eol1 = false;
	bool eol2 = false;

	for (;eol1 == false && eol2 == false;) {
		FD_ZERO(&watch_list);	
		if (eol1 == false)
			FD_SET(in1, &watch_list);
		if (eol2 == false)
			FD_SET(in2, &watch_list);

		int result = select(in2+1, &watch_list, NULL, NULL, NULL);
		
		if (eol1 == false && FD_ISSET(in1, &watch_list)) {
			char buffer[BUFFER_SIZE];
			int c = read(in1, buffer, BUFFER_SIZE) ;
			if (c == 0) {
				eol1 = true;
				break;
			} else {
				int i;
				for (i = 0; i < c; i++) 
					count += (int)( buffer[i] - '0');
			}
		}

		if (eol2 == false && FD_ISSET(in2, &watch_list)) {
			char buffer[BUFFER_SIZE];
			int c = read(in2, buffer, BUFFER_SIZE);
			if (c == 0) {
				eol2 = true;
				break;
			} else {
				int i;
				for (i = 0; i < c; i++)
					count += (int)(buffer[i] - '0');
			}
		}		
	}

	printf("%d\n", count);

	return 0;
}
