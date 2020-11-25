//To implement one pass assembler
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct line
{
    char address[10];
    char label[10];
    char opcode[10];
    char operand[10];

} l[100];
FILE *ptrin, *ptrinter,*ptrsymtab;
void address_calc()
{
    
}
void assemble()
{
    char data1[50],data2[50],data3[50];
    int i=0;
    while(feof(ptrin)==0)
    {
       fscanf(ptrin,"%s%s%s",l[i].label,l[i].opcode,l[i].operand);
       printf("%s %s %s",l[i].label,l[i].opcode,l[i].operand);   
    }
    address_calc();
    fclose(ptrin);
    fclose(ptrinter);
    fclose(ptrsymtab);
}

int main()
{
   
    ptrin=fopen("./input.txt","r");
    ptrinter=fopen("./Intermediate.txt","rw");
    ptrsymtab=fopen("./symtab.txt","rw");
    if(ptrin==NULL||ptrinter==NULL||ptrsymtab==NULL)
    {
        printf("Unable to find required files\n");
        exit(1);
    }
    assemble();
    return 0;
}
