#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*
Fun program to demonstrate floating point math using strings!
*/

char *float_to_string(double number, char *float_string)
{
    /* 
    input: a double to be converted to a string and a string array to place the result in
    output: a string that is the representation of the floating point number entered. 
    */
   
   int exponent = 0;
   char num_sign;
   double abs_number = fabs(number);

   if(number < 0)
   {
       num_sign = '-';
   }
   else
   {
       num_sign =  '+';
   }

   while(abs_number>=10)
   {
        abs_number =  abs_number / 10;
        ++exponent;
   }
   
   while(abs_number<1)
   {
        abs_number =  abs_number * 10;
        --exponent;
   }
   
   sprintf(&float_string[0],"%c%.3lfE%d",num_sign,abs_number,exponent);

   return(float_string);

    
}



char user_input[100];
double floating_pt_num_total; 
double floating_pt_num_to_operate;
char operator;
char float_string[20];

int main()
{
    printf("Enter a number\n");
    fgets(user_input,sizeof(user_input),stdin);
    sscanf(user_input,"%lf",&floating_pt_num_total); //take in a double
    float_to_string(floating_pt_num_total,float_string);
    
    while (1)
    {
        printf("Your number is currently %s and %.3lf\nWhat would you like to do?\n",float_string, floating_pt_num_total);
        printf("Options are add('+')\nsubtract('-')\nmultiply('x')\ndivide('/')\n");
        printf("OR Press 'q' to quit\n");
        fgets(user_input,sizeof(user_input),stdin);
        sscanf(user_input,"%c",&operator);

        if(operator == 'q')
        {
            break;
        }

        printf("Enter a number with which to perform the operation on your current number:\n");
        fgets(user_input,sizeof(user_input),stdin);
        sscanf(user_input,"%lf",&floating_pt_num_to_operate);

        switch(operator)
        {
            case '+':
            floating_pt_num_total += floating_pt_num_to_operate;
            float_to_string(floating_pt_num_total,float_string);
            break;
            
            case '-':
            floating_pt_num_total -= floating_pt_num_to_operate;
            float_to_string(floating_pt_num_total,float_string);
            break;
            
            case 'x':
            floating_pt_num_total *= floating_pt_num_to_operate;
            float_to_string(floating_pt_num_total,float_string);
            break;
            
            case '/':
            if(floating_pt_num_to_operate != 0)
            {
            floating_pt_num_total /= floating_pt_num_to_operate;
            float_to_string(floating_pt_num_total,float_string);
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