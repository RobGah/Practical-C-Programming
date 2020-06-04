#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*Fixed Point Math 
I basically already did this with Exercise 16.1 in my reporting of the number
because I didn't like the decimal out to like 9 places. 
...its really just a formatting thing at the output?
*/

char user_input[100];
double num_total; 
double num_to_operate;
char operator;
char float_string[20];

int main()
{
    printf("Enter a number\n");
    fgets(user_input,sizeof(user_input),stdin);
    sscanf(user_input,"%lf",&num_total); //take in a double
    
    while (1)
    {
        //basically just report a number with a set number of places and a "fixed" place for the decimal?
        //I referenced https://stackoverflow.com/questions/7524838/fixed-point-vs-floating-point-number
        //I also referenced https://kernelthusiast.com/exercise-16-2-practical-c-programming-functions-to-handle-fixed-point-numbers/
        printf("Your number is currently %010.3lf\nWhat would you like to do?\n",num_total);
        printf("Options are add('+')\nsubtract('-')\nmultiply('x')\ndivide('/')\n");
        //Don't get the overflow when I make the total something 7 or more places long...
        //I think I understand the concept though.
        printf("OR Press 'q' to quit\n");
        fgets(user_input,sizeof(user_input),stdin);
        sscanf(user_input,"%c",&operator);

        if(operator == 'q')
        {
            break;
        }

        printf("Enter a number with which to perform the operation on your current number:\n");
        fgets(user_input,sizeof(user_input),stdin);
        sscanf(user_input,"%lf",&num_to_operate);

        switch(operator)
        {
            case '+':
            num_total += num_to_operate;
            break;
            
            case '-':
            num_total -= num_to_operate;
            break;
            
            case 'x':
            num_total *= num_to_operate;
            break;
            
            case '/':
            if(num_to_operate != 0)
            {
            num_total /= num_to_operate;
            }
            else
            {
                printf("Cannot divide by zero!\n");
            }
            break;
            
            default:
            printf("Invalid input\n");
            break;
        }

    }
    return(0);

}