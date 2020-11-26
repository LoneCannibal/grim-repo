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
int i=0;
char *strrev(char *str)
{
  int q = strlen(str) - 1, j = 0;
  char ch;
  while (q > j)
  {
    ch = str[q];
    str[q] = str[j];
    str[j] = ch;
    q--;
    j++;
  }
  return str;
}
int hextodec(char a[10])
{
    int dec=0;
    for(int j=0;j<strlen(a);j++)
    {
        if(a[j]>=48 && a[j]<59)
            dec=dec*16+(a[j]-48);
        else    
            dec=dec*16+(a[j]-65+10);
    }
    return dec;
}
char* dectohex(int d)
{
    char h[10];
    int j=0;
    while(d>0)
    {
        int n=d%16;
        if(n<10)
          h[j++]=n+48;
        else
          h[j++]=(n-10+65);
        
        d=d/16;
    }
    char h2[10];
    int k=0;
    for(int i=0;i<strlen(h);i++)
    {
      if((h[i]>=48&&h[i]<59) || (h[i]>=65&&h[i<=91]))
        h2[k++]=h[i];
    }
    return strrev(h2);
}
void address_calc()
{
    char addr[10];
    if(strcmp(l[0].opcode,"START")==0)
        strcpy(addr,l[0].operand);
    strcpy(l[0].address,addr);
    for(int j=1;j<=i;j++)
    {
        
    }
}
void assemble()
{
    char data1[50],data2[50],data3[50];
    while(feof(ptrin)==0)
    {
       fscanf(ptrin,"%s%s%s",l[i].label,l[i].opcode,l[i].operand);
       i++;
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
