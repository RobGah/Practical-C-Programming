#include <stdio.h>
#include <stdlib.h>

/* 
Write a function that deletes an element from a double linked list.

Copied my cross-reference program from Chap17Evercise1 and added a del_node function
*/

#define ARRAYSIZE 5

char user_input[100];
int int_to_del;
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
struct linked_list *find_node_w_value(int data, struct linked_list *linked_list_entry_ptr);
void del_node(struct linked_list *node_to_del);


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
    printf("Now enter an integer to delete from the list:\n");
    fgets(user_input, sizeof(user_input), stdin);
    sscanf(user_input, "%d", &int_to_del);
    
    del_node(find_node_w_value(int_to_del, head_ptr));
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

struct linked_list *find_node_w_value(int data, struct linked_list *linked_list_entry_ptr)
{
    /* 
    A function to find the node containing a specified data value in a specified linked list.

    inputs: the integer to find and the entry-point pointer of the linked-list to search. 
    outputs: the pointer to the node in which the specified integer was found. Returns NULL if not found.
    */
    struct linked_list *search_ptr = linked_list_entry_ptr; //set search ptr to the head of the list
    while (search_ptr != NULL) //while we're on a valid node
    {
        if(search_ptr->data == data) //if we find a match
        {
            printf("Node containing %d found.\n",data);
            return(search_ptr); //tell us which node
        }
        else
        {
            search_ptr = search_ptr->next_ptr; //advance to the next element of the list
        }
    }

    if (search_ptr == NULL)
    {
        printf("No node containing %d found\n",data);
        return(search_ptr);
    }  
}

void del_node(struct linked_list *node_to_del)
{
    /*
    Deletes a node of a double-linked list with a specified data value

    input: the node to remove from the list
    output: void (deletes the node)
    */
   if(node_to_del==NULL)
   { 
       printf("Error: Node to delete is NULL.\n");
       return;
   }

   //current node's next pointer's previous pointer now points to current node's previous ptr
   node_to_del->next_ptr->previous_ptr = node_to_del->previous_ptr; 
   //current node's previous pointer's next pointer now points to current node's next pointer
   node_to_del->previous_ptr->next_ptr = node_to_del->next_ptr;

   //now to delete node
   free(node_to_del); //free memory allocated to node
   node_to_del = NULL; // set deleted node pointer to NULL to prevent out-of-bounds errors. 
   
}

