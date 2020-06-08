#include <stdio.h>
#include <stdlib.h>

/* 
A cross-reference program - I was unclear as to what that was initially.
Takes an array of ints, puts them into a linked list and prints them out, but could do this with other objects I suppose.

I peeked at https://kernelthusiast.com/solutions-to-book-exercises/
to get an idea of what exactly to do as the book just says "create a cross reference program" - which is awfully vague. 
Wrote my own version independent of the answer presented, however
*/

#define ARRAYSIZE 10

char user_input[100];
struct linked_list 
{
    int data; //the data - in this case an integer
    struct linked_list *next_ptr; //pointer to next node
    struct linked_list *previous_ptr;//pointer to previous node
};

//ptrs to structs to initialize
struct linked_list *head_ptr = NULL; //enter linked list here
struct linked_list *new_item_ptr = NULL;//a new node pointer

//initialize functions
struct linked_list *create_node(int data);
void add_node(struct linked_list *new_item_ptr);
void print_linked_list(struct linked_list *ptr);

int main()
{
    //driving code for all of the functions below
    int int_array[ARRAYSIZE];
    int offset;
    printf("Enter %d integers separated by spaces \n",ARRAYSIZE);
    fgets(user_input, sizeof(user_input),stdin);
    char *data = user_input; //pointer to user_input
    for(int count = 0; count<ARRAYSIZE;++count)
    {
        sscanf(data," %d%n",&int_array[count], &offset);
        struct linked_list *new_item_ptr = create_node(int_array[count]);
        add_node(new_item_ptr);
        //printf("%d ",int_array[count]); //debugging / verification of loop
        data+=offset;
    }
    //printf("\n");
    print_linked_list(head_ptr);
    return(0);
}


struct linked_list *create_node(int item)
{
    /*
    Initializes and creates a node in a linked list

    input: 
    -data to be contained in the node

    output:
    -the pointer to the newly created node
    */
    new_item_ptr = malloc(sizeof(struct linked_list));
    new_item_ptr->data = item;
    new_item_ptr->previous_ptr = NULL;
    new_item_ptr->next_ptr = NULL;

    return(new_item_ptr);
}


void add_node(struct linked_list *new_item_ptr)
{
    /*
    Adds a node to the end of the linked list

    input: 
    -pointer to node to add
    output:
    -nothing / void
    */

    //if head_ptr is NULL set new item to head_ptr and get outta here

    //allocate memory space and initalize elements in the structure
    

    if(head_ptr==NULL)
    {
        head_ptr = new_item_ptr;
        return;
    }

    else
    {
        //lets begin insertion if the list already exists
        struct linked_list *current_node_ptr = head_ptr; //start at the head
    
        while(current_node_ptr->next_ptr != NULL) //while current node ptr's next node is not null
        {
            current_node_ptr = current_node_ptr->next_ptr; //set current node to next node
        }
    
        //set the new node's previous node to the current node
        new_item_ptr->previous_ptr = current_node_ptr;
        //set the current_node's next node from NULL to the new node
        current_node_ptr->next_ptr = new_item_ptr;
    } 
}

void print_linked_list(struct linked_list *linked_list_entry_ptr)
{
    /* Prints the elements of a linked list sequentially

    input:
    -the entrypoint pointer to the linked list

    output:
    -nothing/void (prints each node's data contents to the console)
    */

   struct linked_list *current_node_ptr = linked_list_entry_ptr; //set current pointer to the top of the list 
   printf("The linked list given contains:\n");
   while(current_node_ptr != NULL)
   {
       printf("%d\n",current_node_ptr->data);
       current_node_ptr = current_node_ptr->next_ptr;
   }
}

