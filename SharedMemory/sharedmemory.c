#include <stdio.h>
#include <pthread.h>
#include "producer.h"
#include "consumer.h"

int main()
{

    pthread_t thread1,thread2;
    int t1,t2;
    // producer
    t1 = pthread_create(&thread1,NULL,&Producer,NULL);
    t2 = pthread_create(&thread2,NULL,&Consumer,NULL);//consumer

    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);//consumer

    
    return 0;
}