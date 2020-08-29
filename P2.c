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
    char subdirs[20][200];
    int parent_id;
    int file_count;
    int subdir_count;
    int dir_id;
};
struct Dir d[30];



void make_file(int i)
{
  char dirname1[200];
  int j=0;
  while(command[i]!='\0')
  {
    dirname1[j]=command[i];
    j++;
    i++;
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
  for(int i=0;i<30;i++)
  {
    if(strcmp(d[i].dirname,"\0")==0)
    {
      strcpy(d[i].dirname,dirname1);
      d[i].dir_id=i;
      d[i].file_count=0;
      d[i].subdir_count=0;
      d[i].parent_id=current_dir_id;
      printf("New directory '%s' created.\n",d[i].dirname);
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
  while(command[i]!=' ')
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
