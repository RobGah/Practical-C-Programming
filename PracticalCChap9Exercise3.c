#include <stdio.h>
#include <string.h>

char user_input[100];
int array[];
int number_to_count = 0;
int number_frequency = 0;

int count_number_frequency(int number,int array[],int length)
{
    /* 
    Counts number of times a number appears in an array recursively.
    
    Input: the number to be counted, the array to inspect and
    the length of the array

    Output: The number of times the number appears in the array (an integer)
    */
    if(length < 0)
    {
        return 0; //break recursion!
    }
    int number_count = 0;
    if(array[length] == number)
    {
        number_count++; 
    }
    //return number count + the result of the next array item inspection
    return number_count + count_number_frequency(number,array,length-1);
}

int main()
{
    printf("Enter an integer from 0-9:\n");
    fgets(user_input,sizeof(user_input),stdin);
    sscanf(user_input,"%d",&number_to_count);

    printf("Enter an array whose elements are ints from 0-9.\n");
    printf("Enter each number one at a time, enter q to end the array:\n");
    
    //loop setup
    int array_element;
    char array_element_char;
    int loop_count = 0;

        while(1)
        {
            fgets(user_input,sizeof(user_input),stdin);
            sscanf(user_input,"%c",&array_element_char);
           
            if(array_element_char == 'q')
            {
                break;
            }
            array_element = (int)array_element_char - 48; //cast + ASCII correction!?
            array[loop_count] = array_element;
            loop_count++;
            printf("Next number or q to quit: ");
        }
    printf("The array entered is: ");
    for (int i = 0; i <loop_count; i++)
    {
        printf("%d ",array[i]);
    }
    printf(".");
    number_frequency = count_number_frequency(number_to_count, array, loop_count);
    printf("The array has %d elements that are value %d", number_frequency,number_to_count);

}