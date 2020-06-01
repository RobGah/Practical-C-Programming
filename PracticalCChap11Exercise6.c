#include <stdio.h>
#include <string.h>

/* 
takes the bits in a number (integer?) and shifts them all to the left i.e. 001010 becomes 110000
*/

char user_input[100];

int main()
{
    while(1)
    {
        char bin_to_shift[33]; //takes up to 4 bytes
        char bit_string[33];
        char shifted_bin[33];
        printf("Enter up to a 32-bit binary number to bit shift: \n");
        fgets(user_input,sizeof(user_input),stdin);
        sscanf(user_input, "%s",&bin_to_shift);
    
        strcpy(shifted_bin, bin_to_shift);

       int count = 0;
       while(count < sizeof(bin_to_shift)) //count< index of terminating char on string
       //loop 32x to get LSB totally left on a 32 bit word. 
       {
        for(int i = sizeof(bin_to_shift); i >= 0; i--)
        //this uses array indexing, not MSB LSB indexing. i.e. leftmost bit ("MSB") is at index 0 
        //on a char array
        {
                if((shifted_bin[i] == '1') && (shifted_bin[i-1]=='0')) //evals false on terminating char
                //if the current bit is 1 and the next bit is 0...
                {
                    shifted_bin[i-1] = '1'; //left shift the asserted bit
                    shifted_bin[i] = '0';   //set bit that was shifted left to 0. 
                   // printf("%s\n",shifted_bin);
                }
        }
        count++; //increment and repeat on string until all bits shifted
       }
        
        printf("%s is now %s.\n", bin_to_shift, shifted_bin);
        printf("Hit enter to do it again or q to quit: ");
        fgets(user_input,sizeof(user_input),stdin);
        sscanf(user_input,"%c",&bin_to_shift[0]);

        if (bin_to_shift[0] == 'q')
        {
            break;
        }

    }
}