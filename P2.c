//Implement heirarchical file structure
#include<stdio.h>
#include<string.h>
char path[200];
void console();
struct Dir
{
    char dirname[200];
    char files[20][200] ;
    char subdirs[20][200];
    int file_count;
    int subdir_count;
};
struct Dir d[20];
void console()
{
  printf("%s> ",path);
  char command[250];
  scanf("%s",command);
}
void main()
{
  strcpy(d[0].dirname,"Console/root");
  d[0].file_count=0;
  d[0].subdir_count=0;
  strcpy(path,d[0].dirname);
  console();

}
