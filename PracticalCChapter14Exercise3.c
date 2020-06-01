#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Sorts numbers divisible by 3 and not divisible by 3 into separate folders
*/

void sort_div_by_3(FILE *file)
{
 //feeling cute, could make it a function later idk   
}

FILE *unsorted_file;
FILE *div_3;
FILE *not_div_3;
char user_input[200];
char unsorted_file_name[200];

int main()
{
    printf("Enter a file name to sort:\n");
    fgets(user_input,sizeof(user_input),stdin);
    strcpy(unsorted_file_name,user_input);
    unsorted_file_name[strlen(unsorted_file_name)-1] = '\0';    
    unsorted_file = fopen(unsorted_file_name,"r");
    div_3  = fopen("div-3-list.txt","w");
    not_div_3 = fopen("not-div-3-list.txt", "w");
    int number_to_test;

    while(1)
    {
        int scan = fscanf(unsorted_file,"%d",&number_to_test);

        if(scan == EOF)
        {
            break;
        }

        if(number_to_test % 3 == 0)
        {
            fprintf(div_3,"%d\n",number_to_test);
        }
        else
        {
            fprintf(not_div_3,"%d\n",number_to_test);
        }
    }
    
    fcloseall;
    return(0);
}
