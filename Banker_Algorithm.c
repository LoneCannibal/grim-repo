//Implementing Banker's algorithm for resource allocation
#include<stdio.h>
void main()
{
    int number_of_processes,resource_types,allocated[20][20],need[20][20];
    printf("How many processes are running? ");
    scanf("%d",&number_of_processes);
    printf("Enter the number of resource types ");
    scanf("%d",&resource_types);
    printf("Enter the resource allocation fo each process\n");
    for(int i=1;i<=number_of_processes;i++)
    {
        printf("\033[1;31m\n\n\nPROCESS NUMBER:%d\n\n",i);
        for(int j=1;j<=resource_types;j++)
        {
            printf("\033[0;32mRESOURCE NUMBER %d-> ",j);
            scanf("%d",&allocated[i][j]);
        }
    }

}