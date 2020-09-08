//Implementing single level directory structure
#include<stdio.h>
#include<string.h>
char files[50][50];
char dir_name[50];
int search()
{
  printf("Enter name of the file: ");
  char filename[50];
  scanf("%s",filename);
  for(int i=0;i<50;i++)
    if(strcmp(filename,files[i])==0)
      return i;
  return -1;
}
void menu()
{
  printf("\n1.Insert file\n2.Search file\n3.Delete file\n4.Display contents\n0.EXIT\nCHOOSE OPTION: ");
  int option;
  scanf("%d",&option);
  switch(option)
  {
    case 1: for(int i=0;i<50;i++)
            {
              if(strcmp(files[i],"\0")==0)
              {
                printf("Enter name of the file: ");
                scanf("%s",files[i]);
                printf("FILE CREATED");
                menu();
              }
            }
            printf("NO MORE SPACE");
            break;
    case 2: if(search()!=-1)
              {
                printf("FILE FOUND");
                menu();
              }
            printf("FILE NOT FOUND");
            break;
    case 3: int s=search();
            if(s!=-1)
            {
              files[s]="\0";
              printf("FILE DELETED");
              menu();
            }
            printf("FILE DOES NOT EXIST");
            break;

    case 4: printf("Contents of Directory %s",dir_name);
            for(int i=0;i<50;i++)
            {
              if(strcmp(files[i],"\0")!=0)
                printf("%s\n",files[i]);
            }
            break;
    default: menu();
  }


}
int main()
{
  menu();
  printf("Enter the name of directory ");
  scanf("%s",dir_name);
  return 0;
}
