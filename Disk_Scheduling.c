//Simulate disk scheduling algorithms
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
int locations[30],n,end,head_loc;
bool served[30];
void fcfs()
{
    printf("THE ORDER IS:\n%d->",head_loc);
    for(int i=0;i<n;i++)
        printf("%d->",locations[i]);
    printf("STOP\n");
    menu();
}
void sstf()
{
    printf("Work in progress");
    
    menu();
}
void menu()
{
    int input;
    printf("Enter the head location");
    scanf("%d",&head_loc);  
    printf("\n1.FCFS\n2.SSTF\n3.SCAN\n4.CSCAN\nCHOOSE ALGORITHM: ");
    scanf("%d",&input);
    printf("\n\n");
    switch(input)
    {
        case 1:fcfs();
            break;
        //case 2:sstf();
            break;
        //case 3:scan();
            break;
        //case 4:cscan();
            break;
        default:menu();
        menu();
    }
}
void main()
{
    char loc_string[100],temp[10];
    int i=0,j=0,k=0;
    strcpy(temp,"");
    printf("Enter the end position of the disk: ");
    scanf("%d",&end);
    printf("\nEnter the locations seperated by spaces: ");
    fgets(loc_string,100,stdin);//Extra statement because of strange error
    fgets(loc_string,100,stdin);
    i=0,j=0,k=0;
    while(loc_string[i]!='\0')
    {
        if(loc_string[i]==' ')
        {
            sscanf(temp, "%d", &locations[j]);
            strcpy(temp,"");
            k=0;
            j++;
        }
        else
            temp[k++]=loc_string[i];
        i++;
    }
    sscanf(temp, "%d", &locations[j]);
    n=j+1;
    menu();
}