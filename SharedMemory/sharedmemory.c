#include <stdio.h>
#include <pthread.h>
#include "producer.h"
#include "consumer.h"

int main()
{

    pthread_t thread1,thread2;
    int t1,t2;
    t1 = pthread_create(&thread1,NULL,&Producer,NULL);/* Producer */
    t2 = pthread_create(&thread2,NULL,&Consumer,NULL);/* Consumer */

    pthread_join(thread1,NULL);/* Producer */
    pthread_join(thread2,NULL);/* Consumer */

    
    return 0;
}