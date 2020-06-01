#include <stdio.h>

#define DIV_BY_10(x) (x % 10 == 0)

int number_to_check = 0;
char user_input[100];

int main()
{
    while(1)
    {
        printf("Enter an integer - enter 0 to quit: ");
        fgets(user_input,sizeof(user_input),stdin);
        sscanf(user_input,"%d",&number_to_check);
        
        if(number_to_check == 0)
        {
            break;
        }

        int result = DIV_BY_10(number_to_check);

        if(result == 1) //TRUE
        {
            printf("The number entered is divisible by 10.\n");
        }
        
        else //FALSE
        {
            printf("The number entered is NOT divisible by 10.\n");
        }
        
    }
    return(0);
}
