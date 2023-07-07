#include <stdlib.h>
#include <stdio.h>
#include <sys/shm.h>
#include <stddef.h>

#define REG_SIZE 1000
#define LIST_SIZE 100


int main(int argc, char* argv[]) {
	if (argc != 3)
		return 1;
	
	int shmkey1 = atoi(argv[1]);
	int shmkey2 = atoi(argv[2]);
	key_t key = ftok(argv[0], 0);
	printf("%d\n", key);

	int shmid1 = shmget(shmkey1, REG_SIZE, 0);
	int shmid2 = shmget(shmkey2, REG_SIZE, 0);
	int shmid3 = shmget(key, REG_SIZE, 0666|IPC_CREAT);
	int * reg_ptr1 = shmat(shmid1, NULL, SHM_RDONLY);
	int * reg_ptr2 = shmat(shmid2, NULL, SHM_RDONLY);
	int * reg_ptr = shmat(shmid3, NULL, 0);

	int i;
	for (i = 0; i < LIST_SIZE; i++) {
		reg_ptr[i] = reg_ptr1[i] + reg_ptr2[2];
	}

	shmdt(reg_ptr1);
	shmdt(reg_ptr2);
	shmdt(reg_ptr);
	
	return 0;

}
