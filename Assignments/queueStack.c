#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/*
Implement a queue from a linked list and a stack from an array list. This includes creating both a Node struct and a Queue struct. 
The ArrayList struct can be used as a Stack, just alias it. For each data structure, 
create functions to pop, peek, push, print, create, and clear 
(not destroy, just remove all elements, while the data structure still exists).
Only include the necessary helper functions for a linked list and array list. Pop and peek must return an int.
*/

size_t INITIAL_CAPACITY = 8;

//Dis for queueue
typedef struct node
{
    int key; 
    struct node *next;
}Node;

typedef Node* NodePtr;

typedef struct queue
{
    NodePtr head;
    NodePtr tail;
}Queue;


//Stack
typedef struct stack
{
    int *array;
    size_t head;
    size_t capacity;
}Stack;

//Queue Functions
Queue * create_queue();
void push_q(int value, Queue * qPtr);
void print_q(Queue *qPtr);
NodePtr *second_last(NodePtr *current);
int pop_q(Queue *qPtr);
void print_ll(NodePtr list);
int peek_q(Queue *qPtr);
void destroy_list (NodePtr *list_pointer);
void clear_q(Queue *qPtr);

//Stack Functions 
void push_s(int value, Stack *listPtr);
void resize_if_full(Stack *listPtr);
void print_s(Stack list);
Stack *create_s();
void clear_s (Stack *listPtr);
int peek_s(Stack list);
int pop_s(Stack *listPtr);

int main(int argc, char **argv)
{


    //Queueue 
    Queue *queuePtr = create_queue();
    for (int i = 0; i < 10; ++i)
    {
       push_q(i, queuePtr);
    }
    print_q(queuePtr);
    printf("%d\n",pop_q(queuePtr));
    print_q(queuePtr);
    printf("%d\n", peek_q(queuePtr));
    clear_q(queuePtr);
    print_q(queuePtr);
    printf("%d\n", peek_q(queuePtr));
    
    // Node second = **second_last(&(queuePtr->head));
    // printf("%d slay\n", second.key);

    //Stack
    Stack *list_sPtr = create_s();
    for (int i = 0; i < 10; ++i)
    {
       push_s(i, list_sPtr);
    }
    print_s(*list_sPtr);
    printf("%d\n", pop_s(list_sPtr));
    print_s(*list_sPtr);
    printf("%d\n", peek_s(*list_sPtr));
    clear_s(list_sPtr);
    print_s(*list_sPtr);
    printf("%d\n", peek_s(*list_sPtr));


}

Queue * create_queue()
{
    Queue * new = malloc(sizeof(Queue));
    new->head = NULL;
    new->tail = NULL;
    return new;
}

void push_q(int value, Queue * qPtr)
{
    NodePtr nw = malloc(sizeof(Node));
    nw -> key = value;
    nw -> next = NULL;
    if(qPtr->head == NULL)
    {
        qPtr->head = nw;
        qPtr->tail = nw;
        return;
    }
    qPtr->tail->next = nw;
    qPtr->tail = qPtr->tail->next;
}

void print_q(Queue *qPtr)
{
    print_ll(qPtr->head);
}

void print_ll(NodePtr list)
{
    if(list != NULL)
    {
        printf("%d->", list->key);
        print_ll(list->next);
    }
    else
    {
        printf("%s\n", list);
    }
}

int pop_q(Queue *qPtr)
{
    int end = qPtr->tail->key;
    NodePtr *second_end = second_last(&(qPtr->head));
    qPtr->tail = *second_end;
    (*second_end)->next = NULL;
    free((*second_end)->next);

    return end;
}

NodePtr *second_last(NodePtr *current)
{
    NodePtr item = *current;
    if(item->next->next == NULL)
    {
        return current;
    }
    second_last(&((*current)->next)); //scuffed af
}

int peek_q(Queue *qPtr)
{   
    if (qPtr->head == NULL)
        {return -1;};
    int giving = qPtr->head->key;
    return giving;

}

void clear_q(Queue *qPtr)
{
    destroy_list(&(qPtr->head));
    qPtr->head = NULL; 
    qPtr->tail = NULL;
}

void destroy_list (NodePtr *list_pointer)
{
    NodePtr list = *list_pointer;
    if (list != NULL)
    {
        destroy_list(&(list -> next));
        free (list);
        *list_pointer = NULL;
    }
}

/////////////////////////////////////////////////////////////

void push_s(int value, Stack *listPtr)
{

    // re-size if full
    resize_if_full(listPtr);

    // insert
    listPtr->array[listPtr->head] = value;
    ++listPtr->head;
}

void resize_if_full(Stack *listPtr)
{
    if (listPtr->head == listPtr->capacity)
    {
        listPtr->capacity *= 2;
        listPtr->array = realloc(listPtr->array, listPtr->capacity * sizeof(int));
    }
}

void print_s(Stack list)
{
    //head first
    for (size_t i = list.head; i > 0; --i)
    {printf("%d,", list.array[i-1]);}
    puts("");
}

Stack *create_s()
{
    Stack *new = malloc(sizeof(Stack));
    new->head = 0;
    new->capacity = INITIAL_CAPACITY;
    new->array = calloc(new->capacity, sizeof(int));
   return new;
}

void clear_s (Stack *listPtr)
{
    listPtr->head = 0;
}

int peek_s(Stack list)
{
    if(list.head != 0)
        {return list.array[list.head-1];}
    else
        {return -1;}
}

int pop_s(Stack *listPtr)
{
    --listPtr->head;
    return listPtr->array[listPtr->head];
}
