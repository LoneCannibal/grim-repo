//To implement two level directory structure
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct  dir
{
  char dir_name[50];
  char files[50][50];
};

void menu()
{
  printf("\n\n\n1.Create Directory\n2.Create File\n3.Create\n4.Delete diretory\n5.Delete file\n5.Search\n0.EXIT\nCHOOSE OPTION: ");
  int option;
  scanf("%d",&option);
  switch(option)
  {
    case 0: exit(0);
            break;
    case 1: printf("Enter the name of the directory\n");
            for(int i=0;i<50;i++)
            {
              if(strcmp())
            }
  }

}

int main()
{
  menu();
  return 0;
}
