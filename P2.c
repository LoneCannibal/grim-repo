//Implement heirarchical file structure
#include<stdio.h>
#include<string.h>
char path[200];
char command[50];
int current_dir_id;
void console();
struct Dir
{
    char dirname[200];
    char files[20][200] ;
    int parent_id;
    int file_count;
    int subdir_count;
    int dir_id;
};
struct Dir d[30];



void make_file(int i)
{
  char filename1[200];
  int j=0;
  while(command[i]!='\0')
  {
    filename1[j]=command[i];
    j++;
    i++;
  }
  if(d[0].file_count==20)
    printf("No more available space for files\n");
  for(int k=0;k<20;k++)
  {
    if(strcmp(filename1,d[i].files[k])==0)
    {
      printf("This file already exists\n");
      console();
    }
  }
  for(int k=0;k<20;k++)
  {
    if(strcmp(d[i].files[k],"\0")==0)
    {
      d[i].file_count++;
      strcpy(d[i].files[k],filename1);
      printf("File created\n");
      console();
    }
  }


}


void make_directory(int i)
{
  char dirname1[200];
  int j=0;
  while(command[i]!='\0')
  {
    dirname1[j]=command[i];
    j++;
    i++;
  }
  for(int k=0;k<30;k++)
  {
    if(strcmp(d[k].dirname,"\0")==0)
    {
      strcpy(d[k].dirname,dirname1);
      d[k].dir_id=i;
      d[k].file_count=0;
      d[k].subdir_count=0;
      d[k].parent_id=current_dir_id;
      d[i].subdir_count++;
      printf("New directory '%s' created.\n",d[k].dirname);
      console();
    }
  }
  printf("NO SPACE FOR NEW DIRECTORY\n");
  console();

}



void change_directory(int i)
{
  char dirname1[200];
  int j=0;
  while(command[i]!='\0')
  {
    dirname1[j]=command[i];
    j++;
    i++;
  }
  for(int i=0;i<30;i++)
  {
    if(strcmp(dirname1,d[i].dirname)==0)
    {
      current_dir_id=0;
      path[strlen(path)]='/';
      int k=strlen(path),l=0;
      while(dirname1[l]!='\0')
      {
        path[k]=dirname1[l];
        k++;
        l++;
      }
      console();
    }
  }
  printf("No such directory exists\n");
  console();
}


void console()
{
  printf("%s> ",path);
  fflush(stdin);
  gets(command);
  char cmdword[20];
  int i=0;
  while(command[i]!=' ' && command[i]!='\0')
  {
    cmdword[i]=command[i];
    i++;

  }
  i++;
  if(strcmp(cmdword,"cd")==0)
    change_directory(i);
  else if(strcmp(cmdword,"mkdir")==0)
    make_directory(i);
  else if(strcmp(cmdword,"touch")==0)
    make_file(i);
  else if(strcmp(cmdword,"exit")==0)
  {
    printf("Program Terminated\n");
    exit(0);
  }
  else
  {
    printf("Unrecognised command\n");
    console();
  }
}


int main()
{
  strcpy(d[0].dirname,"Console/root");
  d[0].file_count=0;
  d[0].subdir_count=0;
  d[0].parent_id=-1;
  d[0].dir_id=0;
  strcpy(path,d[0].dirname);
  current_dir_id=0;
  console();
  return 0;
}
