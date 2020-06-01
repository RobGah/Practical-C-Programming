#include "stdio.h"
#include "math.h"
#include "string.h"

//point 1 coordinates
float x_1 = 0; 
float y_1 = 0;

//point 2 coordinates
float x_2 = 0;
float y_2 = 0;

//diff variables
float diffx = 0;
float diffy = 0;
float distance = 0;

//line
char line[100];
//try_again
int try_again = 1;

int main()
{
    while(1)
    {
        //get user values
        printf("Enter a point 1's x and y coordinates separated by a space:\n");
        fgets(line,sizeof(line),stdin);
        sscanf(line, "%f %f", &x_1,&y_1);
        printf("Enter a point 2's x and y coordinates separated by a space:\n");
        fgets(line,sizeof(line),stdin);
        sscanf(line, "%f %f", &x_2,&y_2);

        //calc distance between pts.
        diffx = x_2 - x_1;
        diffy = y_2 - y_1;
        distance = sqrt(pow(diffx,2)+pow(diffy,2));

        //return value
        printf("the distance between %f,%f and %f,%f is %f.\n", x_1, y_1, x_2, y_2, distance);
        printf("Enter 1 to try again or 0 to quit: ");
        fgets(line,sizeof(line),stdin);
        sscanf(line, "%d", &try_again);

        if(try_again == 0)
        {
            break;
        }
    }
    return(0);
}
