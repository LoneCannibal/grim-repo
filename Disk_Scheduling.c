//Simulate disk scheduling algorithms
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
int locations[30],locations2[35],n,n2,end,head_loc;
bool served[30];
bool completed()
{
    for(int i=0;i<n;i++)
        if(served[i]==false)
            return false;
    return true;
}
int time_taken()
{
    int sum=0;
    for(int i=0;i<n-1;i++)
        sum=sum+abs(locations[i]-locations[i+1]);
    return sum;
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
    for(int i=0;i<n;i++)
        printf("%d ",locations[i]);
 }
void unique()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i!=j&&locations[i]==locations[j])
            {
                int k=n-1;
                while(k!=j)
                {
                    locations[k]=locations[k+1];
                    k--;
                }
                n--;
            }
        }
    }
}
void prepare()
{
    locations[n-1]=head_loc;
    locations[n]=0;
    locations[n+1]=end;
    n=n+3;
    sort();
    unique();
}


void fcfs()
{
    printf("THE ORDER IS:\n%d->",head_loc);
    for(int i=0;i<n;i++)
    printf("%d->",locations[i]);
}

void scan()
{
    prepare();
    printf("HEAD IS CURRENTLY MOVING FROM L TO R\nTHE ORDER IS:\n%d->",head_loc);
    int i=0,temp=-1,q=0;
    while(locations[i]<head_loc)
        i++;
    temp=i;
    while(i!=n)
    {
        printf("%d->",locations[i]);
        i++;
    }
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
    prepare();
    printf("HEAD IS CURRENTLY MOVING FROM L TO R\nTHE ORDER IS:\n%d->",head_loc);
    int i=0,temp=-1;
    while(locations[i]<head_loc)
        i++;
    while(i!=n)
    {
        printf("%d->",locations[i]);
        i++;
    }
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
            sscanf(temp,"%d",&locations[j]);
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
    printf("\n1.FCFS\n2.SCAN\n3.CSCAN\n0.EXIT\nCHOOSE ALGORITHM: ");
    scanf("%d",&input);
    printf("\n\n");
    switch(input)
    {
        case 1:fcfs();
            break;
        case 2:scan();
            break;
        case 3:cscan();
            break;
        case 0: exit(0);
        default:menu();
    }
    printf("STOP");
    printf("\n\nSEEK TIME: %d",time_taken());
    printf("\nAVERAGE SEEK TIME: %d",time_taken()/n);
    menu();
}
void main()
{
    menu();
}