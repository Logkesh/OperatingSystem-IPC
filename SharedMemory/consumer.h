#include <stdio.h>

int Consumer()
{
    key_t key = 66;

    int shmid = shmget((key_t) key, sizeof(int), 0666 | IPC_CREAT);

    char *data = shmat(shmid , NULL , 0);

    *data = NULL;

    while(*data == NULL);

    printf("Consumer: \n");
    printf("String at the data is: %s\n", data);

    shmdt(data);

    shmctl(shmid, IPC_RMID, 0);

    return 0;

}