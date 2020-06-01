#include <stdio.h>

/*counts # of bits set in an integer*/

unsigned int int_to_count = 0; 
char user_input[100];

int main()
{
    while (1)
    {
        int bit_count = 0;
        printf("Enter an integer whose set bits you would like to count: ");
        fgets(user_input,sizeof(user_input),stdin);
        sscanf(user_input,"%d",&int_to_count);
        //printf("%d\n",(int_to_count>>1));

        for (unsigned int counter=int_to_count; counter != 0; counter = (counter>>1)) 
        //right shift by 1 every loop. Can't do counter>>1 - that only gives the value 
        //of the shifted counter. NEED AN ASSIGNMENT AS SHOWN. What a trip...
        {
            if(counter &1 == 1)
            { 
                bit_count++;
            }
        }
    
    // WHILE LOOP ALSO WORKS
   /*
        unsigned int counter = int_to_count;
        while(counter)
        {
            if(counter &1 == 1)
            {
                bit_count++;
            }
            counter>>=1;
        }
        */
        printf("There are %d bits asserted in %d. \n", bit_count, int_to_count);

        printf("enter 0 to quit or hit enter to try again");
        fgets(user_input,sizeof(user_input),stdin);
        sscanf(user_input,"%d",&int_to_count);
        if (int_to_count==0)
        {
            break;
        }
        
    }
    return(0);
    
}