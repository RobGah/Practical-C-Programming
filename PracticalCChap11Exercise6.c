#include <stdio.h>

/* takes the bits in a number (integer?) and shifts them all to the left i.e. 001010 becomes 110000
*/

char user_input[100];

int main()
{
    while(1)
    {
        unsigned int int_to_shift = 0;
        printf("Enter an integer to bit shift\n");
        fgets(user_input,sizeof(user_input),stdin);
        sscanf(user_input, "%d",&int_to_shift);
        
        
    }
}`