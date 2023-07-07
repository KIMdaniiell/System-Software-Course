#include <stdio.h>
#include <signal.h>
#include <stdlib.h>


void signal_handler (int signal_number) {
	static int counter_usr1 = 0;
	static int counter_usr2 = 0;
	
	if (signal_number == 10) {
		/* SIGUSR1 */
		
		counter_usr1++;
		
		//printf("[SIGUSR1-%d] \tSignal SIGUSR1 received!\n", counter_usr1);

		return;

	} else if (signal_number == 12) {
		/* SIGUSR2 */
		
		counter_usr2++;
		
		//printf("[SIGUSR2-%d] \tSignal SIGUSR2 received!\n", counter_usr2);

		return;
	} else {
		/* SIGTERM */
		
		//printf("[SIGTERM] Terminating...\n");
		printf("%d %d\n", counter_usr1, counter_usr2);
		exit(0);
	}
}

int main() {
	signal(15, signal_handler);
	signal(10, signal_handler);
	signal(12, signal_handler);
	
	for(;;){}
}

