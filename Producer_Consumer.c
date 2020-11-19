//Program to provide a solution for producer consumer problem
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>
int input_pointer,buffer_pointer=-1,consume_number,input_count,mutex=1;
int input[100],buffer[100];
void wait(int* a){
    --*a;}
void signal(int* a){
    ++*a;}
void *consumer(void *var)
{
    while(consume_number!=0)
    {
        if(mutex==1 &&buffer_pointer!=-1)
        {
            wait(&mutex);
            consume_number--;
            printf("Consumed item %d at location %d\n",buffer[buffer_pointer--],buffer_pointer);
            signal(&mutex);
        }
        else if(buffer_pointer==-1)
            printf("Buffer is empty\n");
        sleep(2);
    }
    return NULL;
}
void *producer(void *var)
{
    while(input_count!=0)
    {
        if(mutex==1)
        {
            wait(&mutex);
            buffer[++buffer_pointer]=input[input_pointer++];
            printf("Produced item %d at location %d\n",buffer[buffer_pointer],buffer_pointer);
            input_count--;
            signal(&mutex) ;
        }
        sleep(1);
    }
    return NULL; 
}
int main()
{
    pthread_t thread_id1,thread_id2;
    printf("Enter the elements in the input seperated by spaces: ");
    char c[200];
    fgets(c,200,stdin);
    char* token=strtok(c," ");
    while(token!=NULL)
    {
        sscanf(token,"%d",&input[input_pointer++]);
        token=strtok(NULL," ");
    }
    printf("Enter the number of inputs to be consumed: ");
    scanf("%d",&consume_number);
    input_count=input_pointer;
    input_pointer=0;
    pthread_create(&thread_id1, NULL, consumer, NULL);
    pthread_create(&thread_id2, NULL, producer, NULL); 
    pthread_join(thread_id1,NULL);
    pthread_join(thread_id2,NULL);
    pthread_exit(NULL);
    return 0;
}