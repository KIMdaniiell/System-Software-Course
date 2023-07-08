#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


int main(int argc, char* argv[]) {

	if (argc != 2)
		return -1;

	struct hostent * h = gethostbyname(argv[1]);

	if (NULL == h) 
		return -2;


	struct in_addr* addr;

	int i = 0;

	while (NULL != (addr = (struct in_addr * ) h->h_addr_list[i])) {
		printf("%s\n", inet_ntoa(*addr));
		i++;
	}
}

