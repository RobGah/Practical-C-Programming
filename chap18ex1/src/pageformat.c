#include "pageformat.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

FILE *new_file = NULL;

FILE *open_file(char *name)
{
    /*
    opens a file with a given name to be written

    inputs: the file name i.e. "foo.txt"
    outputs: the pointer to the file structure (opens file)
    */

    new_file = fopen(name,"w");

    if(new_file==NULL)
    {
        printf("Error! Cannot open %s\n,name");
        exit(8);
    }

    return(new_file);
    
}

char header_formatted[200];

char *define_header(char *header)
{
    /*
    Formats header for a section of the file

    inputs: The file pointer and header text string
    outputs: the formatted header
    */

   sprintf(header_formatted,"~~%s~~\n",header);

   return(header_formatted);

}

void print_line(char *line)
{
    /* 
    Prints a line to the file

    input: line pointer
    output: void
    */

   fprintf(new_file,"%s\n",line);

}

void page(void)
{
    /* 
    Signals a new page

    input: void
    output: void
    */
   fprintf(new_file,"\f");
}

int close_file(void)
{
    /*
    Closes the file being used

    input: void
    output: integer value 
    (0 if successful close, EOF if error)
    */

   int fclose_flag = fclose(new_file);
   if(fclose_flag==EOF)
   {
       printf("Error saving file!");
   }
   return(fclose_flag);

}