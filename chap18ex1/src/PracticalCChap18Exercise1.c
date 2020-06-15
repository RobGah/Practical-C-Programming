#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pageformat.h"

/*
Create a module containing a set of functions that:
-open a text file
-define a printed header
-create a new page
-close a text file
*/

#define LINESPERPAGE 5

char user_input[200];
char filename[200];
int close_flag = 1;
int main()
{
    int line_count = 0; //initialize line count 
    printf("To begin, type a filename to open or create i.e. 'abc.txt':\n");
    fgets(user_input,sizeof(user_input),stdin);
    strcpy(filename,user_input);
    filename[strlen(filename)-1] = '\0'; //kill newline char 
    open_file(filename);
    printf("Now enter a header for the document.\n To skip this step, press @:\n");
    fgets(user_input,sizeof(user_input),stdin);
    user_input[strlen(user_input)-1] = '\0'; //kill newline char 
    if(strcmp(user_input,"@") != 0) //if the line is NOT an @
    {
        print_line(define_header(user_input));
        ++line_count;
    }

    while(close_flag != 0)
    {
        printf("Start typing lines to enter into the file\n Or type @ to enter a header\n or # to close file:\n");
        fgets(user_input,sizeof(user_input),stdin);
        user_input[strlen(user_input)-1] = '\0'; //kill newline char
        if (strcmp(user_input,"#") != 0 && strcmp(user_input,"@") != 0)
        {
            print_line(user_input);
            ++line_count;
        }

        else if(strcmp(user_input,"@") == 0)
        {
            printf("Enter a header for the document.\n");
            fgets(user_input,sizeof(user_input),stdin);
            print_line(define_header(user_input));
            ++line_count;
        }

        else if(strcmp(user_input,"#") == 0)
        {
            close_flag = close_file();
        }

        if(line_count >= LINESPERPAGE)
        {
            page();
            line_count = 0;
        }
    }
return(0);
}

