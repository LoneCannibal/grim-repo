//To implement one pass assembler
#include<stdio.h>
#include<stdlib.h>
struct
{
    char address[10];
    char label[10];
    char opcode[10];
    char operand[10];

}line[100];
FILE *ptrin, *ptrinter,*ptrsymtab;
void assemble()
{
    char data[50];
    while(ptrin!=EOF)
    {
        fscanf(ptrin,"%[^\n]",data);
        char* token=strtok(data," ");
        
        printf("%s",data);
    }
    fclose(ptrin);
}

int main()
{
    ptrin=fopen("./input.txt","r");
    ptrinter=fopen("./Intermediate.txt","rw");
    ptrsymtab=fopen("./symtab.txt","rw");
    if(ptrin==NULL||ptrinter==NULL||ptrsymtab==NULL)
    {
        printf("Unable to find required files\n");
        exit(0);
    }
    assemble();
    return 0;
}
