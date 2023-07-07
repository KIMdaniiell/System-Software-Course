#include <stdlib.h>
#include <stdio.h>
#include <sys/shm.h>
#include <stddef.h>

#define REG_SIZE 1000
#define LIST_SIZE 100


int main(int argc, char* argv[]) {
	if (argc != 3)
		return 1;
	
	int shmid1 = atoi(argv[1]);
	int shmid2 = atoi(argv[2]);
	//printf("%d %d\n", shmid1, shmid2);

	int * reg_ptr1 = NULL;
	int * reg_ptr2 = NULL;
	int * reg_ptr3 = NULL;

	shmat(shmid1, reg_ptr1, SHM_RDONLY);
	shmat(shmid2, reg_ptr2, SHM_RDONLY);
	
	key_t key = ftok(argv[0], 0);
	int shmid3 = shmget(key, REG_SIZE, 0666|IPC_CREAT);
	shmat(shmid3, reg_ptr3, 0);

	int i;
	for (i = 0; i < LIST_SIZE; i++) {
		reg_ptr3[i] = reg_ptr1[i] + reg_ptr2[2];
	}

	shmdt(reg_ptr1);
	shmdt(reg_ptr2);
	shmdt(reg_ptr3);


	printf("%d\n", key);
	return 0;

}
