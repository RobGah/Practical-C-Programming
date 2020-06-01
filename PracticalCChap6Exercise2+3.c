#include "string.h"
#include "stdio.h"
#include "math.h" 

//input
char line[100];

//variables 
int grade = 0;
int grade_units_digit = 0;

int try_again =1;

int main()
{
    while(1)
    {
        //get the grade
        printf("Enter a grade to convert:\n");
        fgets(line,sizeof(line),stdin);
        sscanf(line,"%d",&grade);

        //determine letter grade
    
        if (grade <= 100 & grade >=91) 
        {
            if (grade % 10 >=8 | grade % 10 == 0)
            {
                printf("A+\n");
            }
            else if (grade % 10 <=3)
            {
                printf("A-\n");
            }
            else 
            {
                printf("A\n");
            }
        }
        else if (grade <= 90 & grade >= 81)
        {
            if (grade % 10 >=8 | grade % 10 == 0)
            {
                printf("B+\n");
            }
            else if (grade % 10 <=3)
            {
                printf("B-\n");
            }
            else 
            {
                printf("B\n");
            }        
        }
        else if (grade <= 80 & grade >= 71)
        {
            if (grade % 10 >=8 | grade % 10 == 0)
            {
                printf("C+\n");
            }
            else if (grade % 10 <=3)
            {
                printf("C-\n");
            }
            else 
            {
                printf("C\n");
            }   
        }
        else if (grade <= 70 & grade >= 61)
        {
            if (grade % 10 >=8 | grade % 10 == 0)
            {
                printf("D+\n");
            }
            else if (grade % 10 <=3)
            {
                printf("D-\n");
            }
            else 
            {
                printf("D\n");
            }   
        }
        else if (grade <= 60 & grade >= 0)
        {
            printf("F\n");
        }
        else
        {
            printf("invalid!\n");
        }
        //round and round we go!
        printf("enter 1 to try again or 0 to quit: ");
        fgets(line, sizeof(line), stdin);
        sscanf(line,"%d",&try_again);

        if (try_again ==0)
        {
            break;
        }
    }
    return(0);
}