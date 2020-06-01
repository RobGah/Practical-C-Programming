#include <stdio.h>
#include <string.h>

char user_char;
char user_input[20];

int main()
{
    while(1)
    {
        printf("Enter a character\n");
        fgets(user_input,sizeof(user_input),stdin);
        sscanf(user_input,"%c",&user_char);

        switch (user_char)
         {
            case 'A':
            case 'a':
            case 'E':
            case 'e':
            case 'I':
            case 'i':
            case 'O':
            case 'o':
            case 'U':
            case 'u':
            printf("The character entered IS a vowel.\n");
            break;
    
            case 'Y':
            case 'y':
            printf("The character entered is SOMETIMES a vowel.\n");
            break;

            default:
            printf("The character entered is NOT a vowel. \n");
            break;
        }
        printf("Press enter to try another character or press 0 to quit: ");
        fgets(user_input,sizeof(user_input),stdin);
        sscanf(user_input,"%c",&user_char);
        
        if(user_char=='0')
        {
            break;
        }
    }
    return(0);
}