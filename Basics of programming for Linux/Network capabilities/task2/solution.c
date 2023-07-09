#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

#define CYCLEN 5
#define BSIZE 512

void client(int server_port) {
	printf("[CLIENT] Running client\n");
	
	int socket_fd = socket(AF_INET, SOCK_DGRAM, 0);

	struct sockaddr_in addr;
	inet_aton("127.0.0.1", &addr.sin_addr);
	addr.sin_port = htons(40747);
	addr.sin_family = AF_INET;

	int result = bind(socket_fd, (struct sockaddr *) &addr, sizeof(addr));

	if (result < 0) {
		printf("[CLIENT] Error! Cant bind socket to address!\n");
		return;
	}


	struct sockaddr_in saddr;
	inet_aton("127.0.0.1", &saddr.sin_addr);
	saddr.sin_port = htons(server_port);
	saddr.sin_family = AF_INET;

	int i;
	char buffer[BSIZE + 1];
	strcpy(buffer, "Hello world! I'm CLIENT");
	for (i = 0; i < CYCLEN; i++) {
		int c = sendto(socket_fd, buffer, strlen(buffer)+1, 0, (struct sockaddr * )  &saddr, sizeof(saddr));
		if (c != strlen(buffer) + 1)
			printf("[CLIENT] Error! Sent only %d/%zu chars\n", c, strlen(buffer));
		else
			printf("[CLIENT] Sent message of %d bytes: [%s]\n", c, buffer);
	}
	return;
}

void server(int port) {
	//printf("[SERVER] Running server on port [%d]\n", port);

	int socket_fd = socket(AF_INET, SOCK_DGRAM, 0);

	struct sockaddr_in addr;
	inet_aton("127.0.0.1", &addr.sin_addr);
	addr.sin_port = htons(port);
	addr.sin_family = AF_INET;

	int result = bind(socket_fd, (struct sockaddr *) &addr, sizeof(addr));

	if (result < 0) {
		//printf("[SERVER] Can't bind socket to address!\n");
		return;
	}

	char buffer[BSIZE + 1];
	buffer[0] = '\0';
	/*int i;
	for (i = 0; i < CYCLEN; i++) {
		int c = recvfrom(socket_fd, buffer, BSIZE, 0, NULL, NULL);
		buffer[c] = '\0';
		//printf("[SERVER] Read message: [%s]\n", buffer);
		printf("%s\n", buffer);
	}*/

	while (0 != strcmp(buffer, "OFF\n")) {
		int c = recvfrom (socket_fd, buffer, BSIZE, 0, NULL, NULL);
		buffer[c] = '\0';
		printf("%s\n", buffer);
	}

	return;


}

int main(int argc, char* argv[]) {
	/*if (argc != 3) {
		printf("Error! Run %s [port] [s/c]\n", argv[0]);
		return -1;
	}*/

	if (argc != 2)
		return -1;

	/*if (argv[2][0] == 's') 
		server(atoi(argv[1]));
	else if (argv[2][0] == 'c') 	
		client(atoi(argv[1]));
       	else {
		printf("Error! Uknown argument: [%s]\n", argv[2]);
		return -1;
	}*/
	
	server(atoi(argv[1]));

	//printf("Shutting down...\n");
	return 0;
}
