//Simulate disk scheduling algorithms
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
int locations[30],n,end,head_loc;
bool served[30];
bool completed()
{
    for(int i=0;i<n;i++)
        if(served[i]==false)
            return false;
    return true;
}
void sort()
{
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(locations[j]>locations[j+1])
            {
                int temp=locations[j];
                locations[j]=locations[j+1];
                locations[j+1]=temp;
            }
 }
void fcfs()
{
    printf("THE ORDER IS:\n%d->",head_loc);
    for(int i=0;i<n;i++)
        printf("%d->",locations[i]);
}
void sstf()
{
    printf("THE ORDER IS:\n%d->",head_loc);
    while(!completed())
    {
        int min=2147483647,serve_index=-1;
        for(int i=0;i<n;i++)
        {
            if(min>abs(locations[i]-head_loc) &&served[i]==false)
            {
                min=abs(locations[i]-head_loc);
                serve_index=i;
            }
        }
        head_loc=locations[serve_index];
        printf("%d->",head_loc);
        served[serve_index]=true;
    }
}
void scan()
{
    sort();
    printf("HEAD IS CURRENTLY MOVING FROM L TO R\nTHE ORDER IS:\n%d->",head_loc);
    int i=0,temp=-1;
    while(locations[i]<head_loc)
        i++;
    temp=i;
    while(i!=n)
    {
        printf("%d->",locations[i]);
        i++;
    }
    printf("%d->",end);
    i=temp;
    if(temp-1>=0)
        i=temp-1;
    while(i>=0)
    {
        printf("%d->",locations[i]);
        i--;
    }
}
void cscan()
{
    sort();
    printf("HEAD IS CURRENTLY MOVING FROM L TO R\nTHE ORDER IS:\n%d->",head_loc);
    int i=0,temp=-1;
    while(locations[i]<head_loc)
        i++;
    while(i!=n)
    {
        printf("%d->",locations[i]);
        i++;
    }
    printf("%d->0->",end);
    i=0;
    while(locations[i]<head_loc)
    {
        printf("%d->",locations[i]);
        i++;
    }
    
}

void menu()
{
    char loc_string[100],temp[10];
    int input,i=0,j=0,k=0;
    for(int q=0;q<30;q++)
        served[q]=false;
    printf("\n\nEnter the end position of the disk: ");
    scanf("%d",&end);
    printf("\nEnter the locations seperated by spaces: ");
    fgets(loc_string,100,stdin);//Extra statement because of strange error
    fgets(loc_string,100,stdin);
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
    printf("Enter the head location: ");
    scanf("%d",&head_loc);  
    printf("\n1.FCFS\n2.SSTF\n3.SCAN\n4.CSCAN\nCHOOSE ALGORITHM: ");
    scanf("%d",&input);
    printf("\n\n");
    switch(input)
    {
        case 1:fcfs();
            break;
        case 2:sstf();
            break;
        case 3:scan();
            break;
        case 4:cscan();
            break;
        default:menu();
    }
    printf("STOP");
    menu();
}
void main()
{
    menu();
}