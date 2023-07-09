#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BKLGSIZE 15
#define BSIZE 10000

void swap(char* buffer, int a, int b) {
	printf("[swap] [%c <-> %c] ", buffer[a], buffer[b]);
	char temp = buffer[a];
	buffer[a] = buffer[b];
	buffer[b] = temp;
	printf("[%c <-> %c]\n", buffer[a], buffer[b]);
	return;
}

void sort_string(char* buffer) {
	int i;
	int j;
	int len = strlen(buffer);

	for (i = 0; i < len; i++) {
		for (j = i+1; j < len; j++) {
			if (buffer[i] > buffer[j])
				swap(buffer, i, j);
		}
	}
	return;
}

void client(int server_port) {
	printf("[CLIENT] Running client\n");
	
	struct sockaddr_in caddr;		// Client address
	caddr.sin_family = AF_INET;
	caddr.sin_port = htons(40747);
	inet_aton("127.0.0.1", &caddr.sin_addr);

	struct sockaddr_in saddr;		// Server address
	saddr.sin_family = AF_INET;
	saddr.sin_port = htons(server_port);
	inet_aton("127.0.0.1", &saddr.sin_addr);



	//1. socket
	int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (socket_fd == -1) {
		printf("[CLIENT] Can't init socket\n");
		return;
	}

	//2. bind
	int result = bind(socket_fd, (struct sockaddr *) &caddr, sizeof(caddr));
	if (result == -1) {
		printf("[CLIENT] Can't bind socket to address\n");
		return;
	}

	//3. connect
	result = connect(socket_fd, (struct sockaddr *) &saddr, sizeof(saddr));
	if (result == -1) {
		printf("[CLIENT] Can't connect to server socket\n");
		return;
	}

	//4. send
	char buffer[BSIZE];

	for (;;) {
		scanf("%s", buffer);
		printf("[CLIENT].   Sending message: {%s}\n", buffer);

		int c = send(socket_fd, buffer, strlen(buffer)+1, 0 );
		if (c != strlen(buffer) + 1) {
			printf("[CLIENT] Error! Sent only %d/%ld chars\n", c, strlen(buffer) + 1);
		} else {
			printf("[CLIENT]..  Message sent!\n");
		}

		if ( 0 == strcmp(buffer, "OFF")) {
			break;
		}

		// (5) recv
		c = recv(socket_fd, buffer, BSIZE, 0);
		buffer[c] = '\0';
		printf("[CLIENT]... Got response message: {%s}\n", buffer);
	}

	printf("[CLIENT] Closing socket...\n");
	close(socket_fd);
}

void server(int port) {
	printf("[SERVER] Running server on port: %d\n", port);

	struct sockaddr_in addr;	// Server(self) address
	addr.sin_port = htons(port);
	addr.sin_family = AF_INET;
	inet_aton("127.0.0.1", &addr.sin_addr);

	// 1. socket
	int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (socket_fd == -1) {
		printf("[SERVER] Can't open socket\n");
		return;
	}

	// 2. bind
	int result = bind(socket_fd, (struct sockaddr *) &addr, sizeof(addr));
	if (result == -1) {
		printf("[SERVER] Can't bind socket to address\n");
		return;
	}

	// 3. listen
	result = listen(socket_fd, BKLGSIZE);
	if (result == -1) {
		printf("[SERVER] Can't start listening connection requests\n");
		return;
	}

	char buffer[BSIZE + 1];
	buffer[0] = '\0';
	int i;
	for (i = 0; i < 1; i++) {
		struct sockaddr_in caddr;			// Clients address
		int caddr_len;

		// 4. accept
		int communicator_socket_fd = accept(socket_fd, (struct sockaddr *) &caddr, &caddr_len);
		if (communicator_socket_fd == -1) {
			printf("[SERVER][COMMUNICATOR] Can't accept clients connection request\n" );
			continue;
		}

		printf("[SERVER] New connection accepted\n");

		// 5. recv
		for (;;) {
			int c = recv(communicator_socket_fd, buffer, BSIZE, 0);
			buffer[c] = '\0';
			
			if (0 == strcmp(buffer, "OFF")) {
				printf("[SERVER][COMMUNICATOR] Received OFF message\n");
				close(communicator_socket_fd);
				break;
			}
			
			
			printf("[SERVER][COMMUNICATOR].    Received %d chars\n", c);
			printf("[SERVER][COMMUNICATOR]..   Received message: [%s]\n", buffer);

			sort_string(buffer);
			printf("[SERVER][COMMUNICATOR]...  Sorted message: [%s]\n", buffer);

			// (6) send

			c = send(communicator_socket_fd, buffer, strlen(buffer) + 1, 0);
			if (c == strlen(buffer) + 1)
				printf("[SERVER][COMMUNICATOR].... Responce sent\n");
			else 
				printf("[SERVER][COMMUNICATOR] Error! Sent only %d/%ld chars\n", c, strlen(buffer));
		}

	}
	
}

int main(int argc, char* argv[]) {

	if (argc != 3) {
		printf("Error! Run %s port [s|c]\n", argv[0]);
		return -1;
	}


	if (argv[2][0] == 's') 
		server(atoi(argv[1]));

	else if (argv[2][0] == 'c')
		client(atoi(argv[1]));

	else {
		printf("Unknown argument :[%s]\n", argv[2]);
		return -1;
	}
	
	printf("Shuting down...\n");
	return 0;

}
