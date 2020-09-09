//To implement two level directory structure
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct  dir
{
  char dir_name[50];
  char files[50][50];
};
struct dir d[50];
void menu()
{
  printf("\n\n\n1.Create Directory\n2.Create File\n3.Create\n4.Delete diretory\n5.Delete file\n5.Search\n0.EXIT\nCHOOSE OPTION: ");
  int option;
  char dir_name[50],file_name[50];
  scanf("%d",&option);
  switch(option)
  {
    case 0: exit(0);
            break;
    case 1: printf("Enter the name of the directory: ");
            scanf("%s",dir_name);
            for(int i=0;i<50;i++)
              if(strcmp(d[i].dir_name,"\0")==0)
              {
                strcpy(d[i].dir_name,dir_name);
                menu();
              }
            printf("NO MORE SPACE LEFT");
            break;
    case 2: printf("Select directory to store file: ");
            scanf("%s",dir_name);
            for(int i=0;i<50;i++)
            {
              if(strcmp(d[i].dir_name,dir_name)==0)
              {
                printf("Enter the filename: ");
                scanf("%s",file_name);
                for(int j=0;j<50;j++)
                  if(strcmp(d[i].files[j],"\0")==0)
                    strcpy(d[i].files[j],file_name);
                printf("FILE CREATED");
                menu();
              }
            }
            printf("DIRECTORY DOES NOT EXIST");
            break;


  }
  menu();

}

int main()
{
  menu();
  return 0;
}
