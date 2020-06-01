#include "stdio.h"
#include "string.h"

//exercise 5.1 Centigrade to Farenheit
float farenheit,centigrade;
char user_line[50];

int main()
{
    printf("enter a temperature in centigrade: ");
    fgets(user_line, sizeof(user_line), stdin);
    sscanf(user_line,"%f",&centigrade);
    farenheit = (9.0/5.0)*centigrade + 32;
    printf("%f centigrade is %f farenheit\n", centigrade, farenheit);
    return 0;
}