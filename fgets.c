#include <stdio.h>
#include <string.h>

char user_age[100];     /* user entered age */
char user_desired_year[100];    /*user entered desired year*/
char user_current_year[100];    /*user's current year*/
char response[10];
int main()
{
    while(1)
    {
        printf("enter your age\n");
        fgets(user_age,sizeof(user_age),stdin);
        int age = atoi(user_age);

        printf("enter the current year\n");
        fgets(user_current_year,sizeof(user_current_year),stdin);
        int current_year = atoi(user_current_year);

        printf("enter the year that you would like to know your age in\n");
        fgets(user_desired_year,sizeof(user_desired_year),stdin);
        int desired_year = atoi(user_desired_year);

        int age_in_desired_year = desired_year - current_year + age;
        printf("your age in %d will be %d\n",desired_year,age_in_desired_year);

        printf("enter y to try again or any other key to quit\n");
        fgets(response,sizeof(response),stdin);
        
        if(response[0] != 'y')
        {
            break;
        }
        
    }
    return(0);
}