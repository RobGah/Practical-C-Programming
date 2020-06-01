#include <stdio.h>
#include <string.h>

//Counts # of words in a given string, 
//Words are defined by any sequence of letters
//separated by a space on either side OR is followed by a period.

int word_count = 0;
char user_string[500];
char user_answer;

int count_words(char user_input[])
{
    int space_count = 0; 
    //handle case where nothing is entered. 
    if (strlen(user_input) == 1)
    {
        return space_count;
    }
    else 
    {
        space_count++; //always at least 1 word if not blank.
    }

    for(int char_count = 1; char_count <= strlen(user_input); ++char_count)
    {
        if(user_input[char_count] == ' ')
        {
            ++space_count;
        }
        
    }
    return(space_count);
}


int main()
{
    while(1)
    {
        printf("Enter a sentence that needs wordcount computed:\n");
        fgets(user_string,sizeof(user_string),stdin);
        word_count = count_words(user_string);
        printf("Your string has %d words.\n", word_count);
        printf("press enter to continue or q to quit: ");
        fgets(user_string,sizeof(user_string),stdin);
        sscanf(user_string,"%c",&user_answer);

        if(user_answer=='q')
        {
            break;
        }
    }
    return 0;
}



