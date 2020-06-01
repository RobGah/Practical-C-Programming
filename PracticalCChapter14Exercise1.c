#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* 
Program reads in a file and counts # of lines
*/

FILE *in_file;
char user_input[100];
char filename_string[100];
char *fgets_string_ptr;

int main()
{
    while(1)
    {
        int line_count_in_file = 0; 

        printf("Enter a file name: \n");
        fgets(user_input,sizeof(user_input),stdin);
        strcpy(filename_string,user_input);
    
        filename_string[strlen(filename_string)-1] = '\0'; //kill the newline char 

        in_file = fopen(filename_string,"r");
        if(in_file == NULL)
        {
            printf("Can't open, sorry! File %s not found.\n",filename_string);
        }
        while(1)
        {
            fgets_string_ptr = fgets(user_input,sizeof(user_input),in_file);
        
            if(fgets_string_ptr == NULL)
            {
                break;
            }
        
            ++line_count_in_file;
        }

        printf("Your file contains %d lines \n",line_count_in_file);
        fclose(in_file);
        printf("Press enter to run again or q to quit");
        fgets(user_input,sizeof(user_input),stdin);
        if(user_input[0] == 'q')
        {
            break;
        }
    }
}