//Implementing Banker's algorithm for resource allocation
#include<stdio.h>
void main()
{
    char colours[5][10]={"[0;31m","[0;32m","[0;33m","[0;34m","[0;36m"};
    int number_of_processes,resource_types,allocated[20][5],need[20][5];
    printf("How many processes are running? ");
    scanf("%d",&number_of_processes);
    printf("Enter the number of resource types ");
    scanf("%d",&resource_types);
    if(resource_types>5)
    {
        printf("\033[1;31mTOO MANY RESOURCE TYPES\n");
        exit(0);
    }
    printf("Enter the resource allocation fo each process\n");
    for(int i=1;i<=number_of_processes;i++)
    {
        printf("\033[0;35m\n\n\nPROCESS NUMBER:%d\n\n",i);
        for(int j=1;j<=resource_types;j++)
        {
            printf("\033%s RESOURCE NUMBER %d-> ",colours[j-1],j);
            scanf("%d",&allocated[i][j]);
        }
    }
    printf("Enter the resource need fo each process\n");
    for(int i=1;i<=number_of_processes;i++)
    {
        printf("\033[0;35m\n\n\nPROCESS NUMBER:%d\n\n",i);
        for(int j=1;j<=resource_types;j++)
        {
            printf("\033%s RESOURCE NUMBER %d-> ",colours[j-1],j);
            scanf("%d",&allocated[i][j]);
        }
    }

}