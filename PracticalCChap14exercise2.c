#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Program copies a file, expanding tabs encountered to 4 spaces in new file. 
*/
char user_input[100];

int main()
{
    printf("Enter the name of the file you'd like to copy: \n");
    fgets(user_input,sizeof(user_input),stdin);
    char first_file_name[100];
    strcpy(first_file_name,user_input);
    first_file_name[strlen(first_file_name)-1] = '\0'; //kill the newline!
    //printf("%s",first_file_name);

    printf("Enter the name of the file you'd like to create from the previous file: \n");
    fgets(user_input,sizeof(user_input),stdin);
    char second_file_name[100];
    strcpy(second_file_name,user_input);
    second_file_name[strlen(second_file_name)-1] = '\0'; //kill newline!

    FILE *original_file;
    FILE *copied_file;

    original_file = fopen(first_file_name,"r");
    if(original_file == NULL)
    {
        printf("Sorry!, Source file for copy not found.\n");
        exit(8);
    }
    
    copied_file = fopen(second_file_name,"w");

    char *seg_one_ptr;
    char *seg_two_ptr; //potentially?
    char *first_file_fgets_ptr;
    char first_file_lines[200];
    char tab[] = "    "; //4 spaces

    while(1)
    {
        first_file_fgets_ptr = fgets(first_file_lines,sizeof(first_file_lines),original_file);
        if (first_file_fgets_ptr == NULL)
        {
            break;
        }
        seg_one_ptr = first_file_lines; //ptr to beginning of line
        
        //kill the tab!
        for(int i = 0; i<=strlen(first_file_lines); i++)
        {
            if(first_file_lines[i] == '\t')
            {
               //printf("here!\n");
                seg_two_ptr = strchr(first_file_lines, '\t');
                *seg_two_ptr = '\0'; //EOL the tab
                ++seg_two_ptr; //get to start of segment
                strcat(seg_one_ptr,tab);
                strcat(seg_one_ptr,seg_two_ptr);

            }
        }
        fputs(first_file_lines, copied_file);
    }
    printf("Copy Complete!");
    fclose(original_file);
    fclose(copied_file);
    return(0);
}