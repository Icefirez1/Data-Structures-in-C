#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
    int value;
    struct node *next;
} Node;

typedef Node *NodePtr; 
// Node create_node

//Function HEaders

void insert_ll (int value, NodePtr *listPtr);
void destroy_ll (NodePtr *list);
void print_ll( NodePtr list);
void delete_ll(int value, NodePtr *istPtr);
// deletes all copies of teh value
void purge_ll (int value, NodePtr *listPtr);

int main_ll(int argc, char **argv)
{
    // // NULL only applies to pointers
    // // means: does not point to anything
    // // if list points to NULL, is empty
    // Node *list = NULL;
    // Node node = {42, NULL};
    // Node node2 = {12, NULL};
    // // node.next POINTS TO node2
    // // list POINTS TO node
    // node.next = &node2;
    // list = &node;

    //everytime you allocate memory you must free it at some point 

    NodePtr list = NULL;
    NodePtr *listPtr = &list; 
    insert_ll(42, listPtr);
    insert_ll(111, listPtr);
    insert_ll(6, listPtr);
    delete_ll(6, listPtr);
    print_ll(list);
    destroy_ll(&list);
    return 0; 
}

void print_ll (NodePtr list)
{
    if(list != NULL)
    {
        printf("%d->", list->value);
        print_ll(list->next);
    }
    else
    {
        printf("%s\n", list);
    }
}

void insert_ll (int value, NodePtr *list_pointer)
{
    NodePtr list = *list_pointer;
    if(list == NULL || value <= list->value)
    {
        NodePtr new = malloc(sizeof(Node));
        new-> value = value;
        new->next = list; 
        *list_pointer = new;
    }
    else
        insert_ll( value, &(list->next));
}

void delete_ll(int value, NodePtr *listPtr)
{
    NodePtr list = *listPtr;
    if (list != NULL)
    {
        
        if(value == list->value)
        {
            *listPtr = list->next;
            free(list);
        }
        else if(list != NULL)
            delete_ll(value, &(list->next));
    }
}

//I now officially hate C 
void destroy_ll (NodePtr *list_pointer)
{
    NodePtr list = *list_pointer;
    if (list != NULL)
    {
        destroy_ll(&(list -> next));
        free (list);
        *list_pointer = NULL;
    }
}

void purge_ll (int value, NodePtr *listPtr)
{
    NodePtr list = *listPtr;
    if (list != NULL)
    {
        if(value == list->value)
        {
            *listPtr = list->next;
            free(list);
            purge_ll(value, &(list->next));
        }
        else if(list != NULL)
            purge_ll(value, &(list->next));
    }

}