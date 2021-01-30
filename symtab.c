//To implement the symtab search and input using hashing
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct symtab
{
    int address;
    char symbol[10];
}s[10];
int count=0;
int key(int n)
{
    return(n%11);
}
void display()
{
    for(int i=0;i<10;i++)
        printf("%d  %d  %s\n",i,s[i].address,s[i].symbol);
}
void search()
{
    printf("Enter the address where the symbol is located: ");
    int address,j=0;
    scanf("%d",&address);
    for(int i=key(address);i<10;i++)
    {
        if(s[i].address==address)
        {
            printf("Symbol at address %d found at key '%d': %s\n",address,i,s[i].symbol);
            menu();
        }
        if (i==9)
            i=0;
        j++;
        if(j==10)
            printf("Symbol not found");
    }
}
void enter()
{
    if(count==10)
    {
        printf("Symbol table is full\n");
        menu();
    }
    printf("Enter the address: ");
    int address;
    scanf("%d",&address);
    printf("Enter the symbol: ");
    char sym[10];
    scanf("%s",sym);
    for(int i=key(address);i<10;i++)
    {
        if(strcmp(s[i].symbol,"\0")==0)
        {
            s[i].address=address;
            strcpy(s[i].symbol,sym);
            count++;
            display();
            menu();
        }
        if(i==9)
            i=0;
    }
}
void menu()
{
    printf("1.Enter symbol\n2.Search for symbol\n3.Display symtab\n0.EXIT\nEnter the option: ");
    int choice;
    scanf("%d",&choice);
    if(choice==1)
        enter();
    else if(choice==2)
        search();
    else if(choice==3)
        display();
    else if(choice==0)
        exit(0);
    else
        menu();
}
void main()
{
    menu();
}
