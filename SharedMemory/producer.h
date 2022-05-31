#include <stdio.h>
#include <sys/shm.h>

int Producer()
{
    key_t key = 66;

    int shmid = shmget((key_t) key, sizeof(int), 0666 | IPC_CREAT);

    char *data = shmat(shmid , NULL , 0);

    printf("Producer: \n");
    printf("Enter A String: ");

    gets(data);

    shmdt(data);

    return 0;

}