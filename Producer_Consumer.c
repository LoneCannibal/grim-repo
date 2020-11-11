//Program to provide a solution for producer consumer problem
#include <unistd.h>
#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#include<pthread.h>
int i=0;
int buffer[100];
void *consumer(void *var)
{
    for(int j=0;j<10;j++)
        printf("THREAD 1 %d\n",i++);
    return NULL;
}
void *producer(void *var)
{
    for(int j=0;j<10;j++)
        printf("THREAD 2 %d\n",i++);
    return NULL;
}
int main()
{
    pthread_t thread_id1,thread_id2;
    printf("Enter the elements in the buffer seperated by spaces ");
    char c[200];
    fgets(c,200,stdin);
    char* token=strtok(c," ");
    while(token!=NULL)
    {
        sscanf(token,"%d",&buffer[i++]);
        strtok(NULL," ");
    }
    pthread_create(&thread_id1, NULL, consumer, NULL);
    pthread_create(&thread_id2, NULL, producer, NULL); 
    pthread_join(thread_id1,NULL);
    pthread_join(thread_id2,NULL);
    pthread_exit(NULL); 
    return 0;
}