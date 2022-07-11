#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int MAX = 10;
int count = 1;

pthread_mutex_t thr = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

void *even()
{
    while(count < MAX)
    {
        pthread_mutex_lock(&thr);
        while(count%2 != 0)
        {
            pthread_cond_wait(&cond,&thr);
        }
        printf("%d\n",count++);
        pthread_mutex_unlock(&thr);
        pthread_cond_signal(&cond);
    }
    pthread_exit(0);
}

void *odd()
{
    while(count < MAX)
    {
        pthread_mutex_lock(&thr);
        while(count%2 != 1)
        {
            pthread_cond_wait(&cond,&thr);
        }
        printf("%d\n",count++);
        pthread_mutex_unlock(&thr);
        pthread_cond_signal(&cond);
    }
    pthread_exit(0);
}

int main()
{
    pthread_t thread1,thread2;
    pthread_mutex_init(&thr,NULL);
    pthread_cond_init(&cond,NULL);
    pthread_create(&thread1,NULL,&even,NULL);
    pthread_create(&thread2,NULL,&odd,NULL);
    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);
    pthread_mutex_destroy(&thr);
    pthread_cond_destroy(&cond);
    return 0;
}