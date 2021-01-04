//Uses a hashing function to store and retrieve values from symtab
#include<stdio.h>
struct symtab
{
    int key;
    int address;
    char label[50];
}s1 [10];
int hash(int address)
{
    
}
void enter()
{
    printf("Enter the address");
    int address;
    scanf("%d",&address);
    int location=hash(address);
}
void menu()
{
    printf("CHOOSE OPTION:\n1.Enter value into symtab\n2.Search\n0.EXIT");
    int choice;
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:enter();
        break;
        case 2:search();
        break;
        case 0:exit(0);
    }
}
void main()
{
    menu();
}