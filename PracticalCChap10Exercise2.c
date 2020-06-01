#include <stdio.h>

#define IS_DIGIT(x) (x < 10 && x >= 0)

int number_to_check = 0;
char quit_check;
char user_input[100];

int main()
{
    while(1)
    {
        printf("Enter an integer - enter q to quit: ");
        fgets(user_input,sizeof(user_input),stdin);
        sscanf(user_input,"%d",&number_to_check);
        sscanf(user_input,"&c",&quit_check);
        
        if(quit_check == 'q')
        
        {
            break;
        }

        int result = IS_DIGIT(number_to_check);

        if(result == 1) //TRUE
        {
            printf("The number entered is a digit.\n");
        }
        
        else //FALSE
        {
            printf("The number entered is NOT a digit.\n");
        }
        
    }
    return(0);
}
