#include <string.h>
#include <stdio.h>

char name[50];
char first_name[50];
char last_name[50];
char full_name[100];

int main()
{
    strcpy(name,"Robert");
    printf(strcat(name,"\n"));
    strcpy(first_name,"Robert");
    strcpy(last_name,"Garrone");
    strcpy(full_name,strcat(first_name," "));
    strcat(full_name,last_name);
    printf("The full name is %s\n",full_name);
}