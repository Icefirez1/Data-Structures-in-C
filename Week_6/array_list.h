#include <stdio.h>
#include <stdlib.h>

typedef struct arraylist
{
    int *array; 
    size_t capacity; 
    size_t size;
} ArrayList;


ArrayList *create_al ();
void destroy_al(ArrayList *listPtr);
void print_al(ArrayList list);
void insert_al(int value, ArrayList *listPtr);
void print_al(ArrayList list);

int main_al(int argc, char *argv[])
{
    ArrayList *listPtr = create_al();
    ArrayList list = *listPtr;
    //printf("%zu, %zu, %p\n", list.size, list.capacity, list.array);
    destroy_al(listPtr);
    return 0;
}

ArrayList *create_al ()
{
    ArrayList *newPtr = malloc(sizeof(ArrayList));
    newPtr ->size = 0; 
    newPtr ->capacity = 8; 
    // new_list.array = malloc(new_list.capacity * sizeof(int));
    newPtr->array = calloc(newPtr->capacity, sizeof(int));
}

void destroy_al(ArrayList *listPtr)
{
    free(listPtr->array);
    free(listPtr);

}

void print_al(ArrayList list)
{
    for(size_t i = 0; i <list.size; i++)
    {
        printf("%d,", list.array[i]);
    }
    puts("")
}

void insert_al(int value, ArrayList *listPtr)
{
  
    size_t i;
    for (i = (listPtr->size)++; i != 0 && listPtr->array[i-1] >= value; --i)
    {
        listPtr->array[i] = listPtr->[i-1];
    }
    listPtr->array[i] = value;

}

void resizeiffulle(ArrayList *listPtr)
{
    if(listPtr -> size == listPtr -> capacity)
    {
        listPtr->capacity *=2; 
        listPtr-> = realloc(listPtr->array,listPtr->capacity*sizeof(int));
    }
}


