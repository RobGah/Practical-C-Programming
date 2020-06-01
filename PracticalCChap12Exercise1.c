#include <stdio.h>
#include <string.h>

#define MAX_ENTRIES 1

char user_input[100];

struct mailing 
{
    char name[60];
    char address[60];
    char city[40];
    char state[3]; //gimmie a 3rd byte to make life easy (for \0) and treat it as a string. 
    long int zip;
};

struct mailing mailing_list[MAX_ENTRIES];

int main()
{
    while(1)
    {
        int count = 0; 
        while(count<MAX_ENTRIES)
        {
            printf("Enter a name:\n");
            fgets(user_input,sizeof(user_input),stdin);
            strcpy(mailing_list[count].name,user_input);
            //sscanf(user_input,"%s",&mailing_list[count].name);

            printf("Enter an address:\n");
            fgets(user_input,sizeof(user_input),stdin);
            strcpy(mailing_list[count].address,user_input);
            //sscanf(user_input,"%s",&mailing_list[count].address);

            printf("Enter a city:\n");
            fgets(user_input,sizeof(user_input),stdin);
            sscanf(user_input,"%s",&mailing_list[count].city);

            printf("Enter a state (2 letter abbrev):\n");
            fgets(user_input,sizeof(user_input),stdin);
            sscanf(user_input,"%s",&mailing_list[count].state);

            printf("Enter a zip:\n");
            fgets(user_input,sizeof(user_input),stdin);
            sscanf(user_input,"%d",&mailing_list[count].zip);

            count++;
        }

        int printcount = 0;
    
        printf("The mailing list is as follows:\n\n");
        while (printcount<MAX_ENTRIES)
        {
            printf("%s",mailing_list[printcount].name);
            printf("%s", mailing_list[printcount].address);
            printf("%s\n",mailing_list[printcount].city);
            printf("%s\n", mailing_list[printcount].state);
            printf("%d\n",mailing_list[printcount].zip);
            printf("\n");

            printcount++;
        }         
        printf("Press enter to do again or q to quit");
        fgets(user_input,sizeof(user_input),stdin);
        sscanf(user_input,"%c",&user_input);

        if(user_input[0] == 'q')
        {
            break;
        }
    }
    return(0);
}