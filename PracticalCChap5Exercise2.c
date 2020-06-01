#include "stdio.h"
#include "string.h"
#include "math.h"

const float PI = 3.14159;
float radius, volume;
char user_input[50];
int main()
{
    printf("enter a sphere radius to calculate volume: ");
    fgets(user_input, sizeof(user_input), stdin);
    sscanf(user_input,"%f",&radius);
    volume = (4.0/3.0)*PI*pow(radius,3); 
    printf("A sphere with radius %f has a volume of %f", radius, volume);
    
    return 0;
}

