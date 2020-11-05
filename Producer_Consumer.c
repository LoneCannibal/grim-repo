//Program to provide a solution for producer consumer problem
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
int main()
{
    int i=0;
    pid_t pid;
    for(int i=0;i<10;i++)
    {
        pid=fork();    
        printf("%d   %d\n",i,pid);
    }
    return 0;
}