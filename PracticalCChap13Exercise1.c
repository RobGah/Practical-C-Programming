#include <stdio.h>
#include <string.h>


/*
Zeros out array

input - pointer to array (aka the array lol) and its size (why make life hard?)
admittedly could do sizeof(array)/4 (4 bytes to an int!)

output - nothing, just increments the pointer and assigns the
dereferenced pointer + index to 0. 
*/
void zero_out_array(int *array_ptr, int array_size)
{
    int index;

    for(index = 0; index < array_size;++index)
    {
        *(array_ptr + index) = 0;
    }
}

char user_input[70];

int main()
{
    int array_size = 0;

    void zero_out_array(); //dunno why i'm initializing?

    printf("Enter an array size (positive integers only!): \n");
    fgets(user_input,sizeof(user_input),stdin);
    sscanf(user_input,"%d",&array_size);

    int array[array_size-1];
    printf("%d\n",sizeof(array));

    for(int i = 0; i < array_size; ++i)
    {
        printf("Enter array element %d :\n",i);
        fgets(user_input,sizeof(user_input),stdin);
        sscanf(user_input,"%d",&array[i]);
    }

    printf("your array entered is:\n");

    for(int i = 0; i<array_size; ++i)
    {
        printf("%d ",array[i]);
    }

    zero_out_array(array,array_size);
    printf("\n");
    printf("your array zero'd out is:\n");

    for(int i = 0; i<array_size; ++i)
    {
        printf("%d ",array[i]);
    }
return(0);
//could do a cute big loop but nah. 
}