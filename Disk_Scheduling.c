//Simulate disk scheduling algorithms
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int locations[30],n,start,end,head_loc;
void fcfs()
{
    printf("THE ORDER IS:\n%d->",head_loc);
    for(int i=0;i<n;i++)
        printf("%d->",locations[i]);
    printf("END\n");
}
void menu()
{
    int input;
    printf("Enter the head location");
    scanf("%d",&head_loc);  
    printf("\n1.FCFS\n2.SSTF\n3.SCAN\n4.CSCAN\nCHOOSE ALGORITHM: ");
    scanf("%d",&input);
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
    char loc_string[100],start_end_string[10],temp[10];
    int i=0,j=0,k=0;
    printf("Enter the start and end positions of the disk seperated by spaces: ");
    fgets(start_end_string,10,stdin);
    while(start_end_string[i]!='\0')
    {
        if(start_end_string[i]==' ')
        {
            start=atoi(temp);
            strcpy(temp,"");
            k=0;
        }
        else
            temp[k++]=start_end_string[i];
        i++;
    }
    end=atoi(temp);
    if(start>end)
    {
        printf("ERROR OCCURED\n");
        exit(0);
    }
    printf("\nEnter the locations seperated by spaces: ");
    fgets(loc_string,100,stdin);
    i=0,j=0,k=0;
    while(loc_string[i]!='\0')
    {
        if(loc_string[i]==' ')
        {
            locations[j]=atoi(temp);
            strcpy(temp,"");
            k=0;
            j++;
        }
        else
            temp[k++]=loc_string[i];
        i++;
    }
    locations[j]=atoi(temp);
    n=j+1;
    menu();
}