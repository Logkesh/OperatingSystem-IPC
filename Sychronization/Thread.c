#include <stdio.h>
#include <pthread.h>

int arr[50],i,n  =5;

void *th0()
{
    int sum = 0;
    float average;
    printf("enter your number: ");
    scanf("%d",&n);
    for(int i = 0; i<n ; i++)
    {
       scanf("%d",&arr[i]);
        sum = sum + arr[i];
    }
    average = sum / n;
    printf("The average value is %f\n",average);
}

void *th1()
{
    int temp = arr[0];
    for(int i = 1; i<n;i++)
    {
        if(temp > arr[i])
            temp = arr[i];
    }
    printf("The minimum value is %d\n",temp);
}

void *th2()
{
    int temp = arr[0];
    for(int i = 1; i<n;i++)
    {
        if(temp < arr[i])
            temp = arr[i];
    }
    printf("The maximum value is %d\n",temp);
}



int main()
{
    int i,n;
    pthread_t thread1,thread2,thread3;
    int t1 = pthread_create(&thread1,NULL,&th0,NULL);
    pthread_join(thread1,NULL);
    int t2 = pthread_create(&thread2,NULL,&th1,NULL);
    pthread_join(thread2,NULL);
    int t3 = pthread_create(&thread3,NULL,&th2,NULL);
    pthread_join(thread3,NULL);
}