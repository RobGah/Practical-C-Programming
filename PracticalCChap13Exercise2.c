#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char *get_first_white_char(char *array_ptr)
{
    while(*array_ptr != ' ')
    {
        if(*array_ptr =='\0')
        {
            return(NULL);
        }
        ++array_ptr;
    }
    return(array_ptr);
}

char *get_first_nonwhite_char(char *array_ptr)
{
    while(1)
    {
        if(*array_ptr == '\0') //if EOL
        {
            return(NULL);
        }

        if(*array_ptr != ' ') //if not space
        {
            return(array_ptr);
        }

        ++array_ptr; //increment
    }
}

int main()
{
    while(1)
    {
        char user_input[100];
        char *report_ptr;

        printf("Enter a string: \n");
        fgets(user_input,sizeof(user_input),stdin);
        user_input[strlen(user_input)-1] = '\0'; //remove \n from fgets

        report_ptr = get_first_nonwhite_char(user_input);

        if(report_ptr == NULL)
        {
            printf("No character found.\n");
        }

        else
        {
            printf("The character returned is \"%c\" at address %p.\n",(*report_ptr), report_ptr);
        }

        printf("Enter to do again or q to quit: ");
        fgets(user_input,sizeof(user_input),stdin);

        if(user_input[0] == 'q')
        {
            break;
        }
    }
    return(0);
}
