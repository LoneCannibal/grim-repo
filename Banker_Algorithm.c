//Implementing Banker's algorithm for resource allocation
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h> 
char colours[5][10]={"[0;31m","[0;32m","[0;33m","[0;34m","[0;36m"};
int number_of_processes,resource_types,not_enough_resources=0,allocated[20][5],max[20][5],total_resources[5];
bool finished[20];
void execute(int i)
{
    for(int j=0;j<resource_types;j++)
        total_resources[j]=total_resources[j]+allocated[i][j];
}
bool finished_execution()
{
    not_enough_resources++;
    if(not_enough_resources>number_of_processes+1)
    {
        printf("\n\n\033[1;31mFATAL ERROR OCCURED: NOT ENOUGH RESOURCES\n");
        exit(0);
    }
    for(int i=0;i<number_of_processes;i++)
        if(finished[i]==false)
            return false;
    return true;
}
void main()
{
    printf("\033[1;36mHow many processes are running? ");
    scanf("%d",&number_of_processes);
    printf("Enter the number of resource types ");
    scanf("%d",&resource_types);
    if(resource_types>5)
    {
        printf("\033[1;31mTOO MANY RESOURCE TYPES\n");
        exit(0);
    }
    printf("Enter the  allocated resources fo each process");
    for(int i=0;i<number_of_processes;i++)
    {
        printf("\033[0;35m\n\nPROCESS NUMBER:%d\n\n",i);
        for(int j=0;j<resource_types;j++)
        {
            printf("\033%s RESOURCE NUMBER %d-> ",colours[j],j);
            scanf("%d",&allocated[i][j]);
        }
    }
    printf("\n\n\n\033[1;36mEnter the max resources for each process");
    for(int i=0;i<number_of_processes;i++)
    {
        printf("\033[0;35m\n\nPROCESS NUMBER:%d\n\n",i);
        for(int j=0;j<resource_types;j++)
        {
            printf("\033%s RESOURCE NUMBER %d-> ",colours[j],j);
            scanf("%d",&max[i][j]);
        }
    }
    printf("\n\n\033[1;36mEnter the total available resources\n");
    for(int i=0;i<resource_types;i++)
    {
        printf("\033%sRESOURCE NUMBER %d->",colours[i],i);
        scanf("%d",&total_resources[i]);
    }
    
    while(!finished_execution())
    {
        for(int i=0;i<number_of_processes;i++)
        {
            bool possible=true;
            for(int j=0;j<resource_types;j++)
            {
                
                if(max[i][j]-allocated[i][j]>total_resources[j] && finished[i]==false)
                    possible=false;
            }
            if(possible==true)
            {
                execute(i);
                if(finished[i]==false)
                {
                    printf("\033[1;36m PROCESS %d FINISHED EXECUTION. TOTAL RESOURCES=[",i);
                    for(int k=0;k<resource_types;k++)
                        printf("\033%s   %d",colours[k],total_resources[k]);
                    printf("\033[1;36m   ]\n");
                }
                finished[i]=true;
            }
        }
    }
}