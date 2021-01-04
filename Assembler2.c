//To implement both passes of two pass assembler
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct line
{
    int address;
    char label[10];
    char operator[10];
    char operand[10];
    char opcode[10];
} l[100];
FILE *ptrin, *ptrinter,*ptrsymtab,*ptrobj,*ptropcode;
int i=0,last;
int hextodec(char a[10])
{
    int dec=0;
    for(int j=0;j<strlen(a);j++)
    {
        if(a[j]>=48 && a[j]<59)
            dec=dec*16+(a[j]-48);
        else    
            dec=dec*16+(a[j]-97+10);
    }
    return dec;
}

void pass2()
{
    fprintf(ptrobj,"H^%s^00%x^0000%x\n",l[0].label,l[0].address,last-l[0].address);
    fprintf(ptrobj,"T^%x^%x",l[0].address,last-l[0].address);
    for(int j=1;j<=i;j++)
    {
        for(int k=1;k<=i;k++)
        {
            if(strcmp(l[j].operand,l[k].label)==0)
                {
                    if (strcmp(l[j].operator,"BYTE")==0)
                    {
                        fprintf(ptrobj,"^");
                        for(int q=0;q<strlen(l[k].operand);q++)
                            fprintf(ptrobj,"%x",l[k].operand[q]); //Converting each character in byte to ascii hex code
                    }
                    else
                        fprintf(ptrobj,"^%s%x",l[j].opcode,l[k].address);
                }
        }
        if(strcmp(l[j].operator,"WORD")==0)
            fprintf(ptrobj,"^000000");
        
    }
    fprintf(ptrobj,"\nE^00%x",l[0].address);
        
}
void address_calc()
{
    int locctr;
    if(strcmp(l[0].operator,"START")==0)
        locctr=hextodec(l[0].operand);
    for(int j=0;j<i;j++)
    {
        l[j].address=locctr;
        fprintf(ptrinter,"%x %s %s %s\n",l[j].address,l[j].label,l[j].operator,l[j].operand);
        if(strcmp(l[j].label,"**")!=0 &&j!=0)
            fprintf(ptrsymtab,"%s %x\n",l[j].label,l[j].address);
        printf("%x %s %s %s\n",l[j].address,l[j].label,l[j].operator,l[j].operand);
        if(strcmp(l[j].operator,"RESW")==0)
            locctr+=hextodec(l[j].operand)*3;
        else if(strcmp(l[j].operator,"RESB")==0)
            locctr+=hextodec(l[j].operand);
        else if(strcmp(l[j].operator,"BYTE")==0)
            locctr+=strlen(l[j].operand);
        else if(strcmp(l[j].operator,"START")!=0)
            locctr+=3;
         while(feof(ptropcode)==0)
            {
                char optemp[10];
                char opcodetemp[10];
                fscanf(ptropcode,"%s %s",optemp,opcodetemp);
                if(strcmp(optemp,l[j].operator)==0)
                    strcpy(l[j].opcode,opcodetemp);
            }
        fclose(ptropcode);
        ptropcode=fopen("./opcode.txt","r");
    }
    last=locctr;
    pass2();
}
void assemble()
{
    while(feof(ptrin)==0)
    {
       fscanf(ptrin,"%s%s%s",l[i].label,l[i].operator,l[i].operand);
       i++; 
    }
    address_calc();
    fclose(ptrin);
    fclose(ptrinter);
    fclose(ptrsymtab);
    fclose(ptrobj);
    fclose(ptropcode);
}
int main()
{
    ptrin=fopen("./input.txt","r");
    ptrinter=fopen("./Intermediate.txt","w");
    ptrsymtab=fopen("./symtab.txt","w");
    ptrobj=fopen("./object_code.txt","w");
    ptropcode=fopen("./opcode.txt","r");
    if(ptrin==NULL||ptrinter==NULL||ptrsymtab==NULL)
    {
        printf("Unable to find required files\n");
        exit(1);
    }
    assemble();
    return 0;
}