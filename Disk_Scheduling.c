//Simulate disk scheduling algorithms
#include<stdio.h>
int locations[30],n,head_loc;
void menu()
{
    
}
void main()
{
    printf("Enter the number of locations");
    scanf("%d",&n);
    printf("Enter the locations");
    for(int i=0;i<n;i++)
        scanf("%d",locations[i]);
    menu();
}