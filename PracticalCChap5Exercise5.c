#include "stdio.h"
#include "string.h"

//chap 5 exercise 5 
//input: hours and minutes string
//output: total minutes

int hours, minutes;
int total_minutes;
char user_input[100];
char user_hour[25];
char user_and[25];
char user_minutes[25];

int main()
{
    printf("Enter amount of time i.e. \"1 hour and 30 minutes\" :");
    fgets(user_input, sizeof(user_input), stdin);
    sscanf(user_input,"%d %s %s %d %s", &hours, &user_hour, &user_and, &minutes, &user_minutes);
    for(int i = 1; i <=hours; i++)
    {
        total_minutes+=60;
    }
    total_minutes += minutes;

    printf("%d hours and %d minutes is %d total minutes", hours, minutes, total_minutes);
    return 0;
}