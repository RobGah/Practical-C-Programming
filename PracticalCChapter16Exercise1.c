#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Fun program to demonstrate floating point math using strings!
*/

char user_input[100];
char floating_pt_num[11]; //4 digit precision w/signs out front and after 'E' and newline char
char other_floating_pt_num[11];
char operator;
int main()
{
    printf("Enter a floating point representation of a number i.e. 100 is +1.0000E+2\n");
    printf("(Include the signs and mind the precision!):\n");
    fgets(user_input,sizeof(user_input),stdin);
    strcpy(floating_pt_num,user_input);
    
    while (1)
    {
        printf("Your number is currently %s\nWhat would you like to do?\n",floating_pt_num);
        printf("Options are add('+')\nsubtract('-')\nmultiply('x')\ndivide('/')\n");
        printf("OR Press 'q' to quit\n");
        fgets(user_input,sizeof(user_input),stdin);
        sscanf(user_input,"%c",&operator);
        printf("Enter a floating point number with which to perform the operation on your current number:\n");
        fgets(user_input,sizeof(user_input),stdin);
        sscanf(user_input,"%s",&other_floating_pt_num);

        switch(operator)
        {
            case '+':

            case '-':

            case 'x':

            case '/':

            case 'q':
            
            break;
            
            default:

            break;
        }

    }
    

}