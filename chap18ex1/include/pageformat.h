#ifndef PAGEFORMAT_H
#define PAGEFORMAT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 
Contains functions for opening/closing text files and 
formatting pages - creates a heading, writes a new line 
and signals a new page
*/

FILE *open_file(char *name);
/*
opens a file with a given name to be written

inputs: the file name i.e. "foo.txt"
outputs: the pointer to the file structure (opens file)
*/

char *define_header(char *header);
/*
Formats and prints header for a section of the file

inputs: The file pointer and header text string
outputs: a pointer to the formatted header
*/
void print_line(char *line);
/* 
Prints a line to the file

input: line pointer
output: void
*/

void page(void);
/* 
Signals a new page

input: void
output: void
*/

int close_file(void);
/*
Closes the file being used

input: void
output: integer value 
(0 if successful close, EOF if error)
*/


#endif