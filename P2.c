//Implement heirarchical file structure
#include<stdio.h>
#include<string.h>
char path[200];
char command[50];
void console();
struct Dir
{
    char dirname[200];
    char files[20][200] ;
    char subdirs[20][200];
    char parent[100];
    int file_count;
    int subdir_count;
};
struct Dir d[20];

void change_directory(int i)
{
  printf("REACHED");
  while(command[i]!='\0')
  {
    printf("%c",command[i]);
    i++;
  }
}


void console()
{
  printf("%s> ",path);
  gets(command);
  char cmdword[20];
  int i=0;
  while(command[i]!=' ')
  {
    cmdword[i]=command[i];
    i++;
  }
  puts(cmdword);
  i++;


  if(strcmp(cmdword,"cd")==0)
  {

    change_directory(i);
  }
  else
  {
    printf("Unrecognised command\n");
    console();
  }
}


void main()
{
  strcpy(d[0].dirname,"Console/root");
  d[0].file_count=0;
  d[0].subdir_count=0;
  strcpy(path,d[0].dirname);
  console();

}
