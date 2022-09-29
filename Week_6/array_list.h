#include <stdio.h>
#include <stdlib.h>
// courtesy of chris agrella

size_t INITIAL_CAPACITY = 8;

// Sorted, dynamically sized list
typedef struct array_list
{
    int *array;
    // max capacity of array in # of elements
    size_t capacity;
    // current size of array in # of elements
    size_t length;

} ArrayList;

// create a new array list
ArrayList *create_al();
// destroy an array list
void destroy_al(ArrayList *listPtr);
// print out all elements of an array list
void print_al(ArrayList list);
// insert an element into an array list.
void insert_al(int value, ArrayList *listPtr);
// re-size array list if array list is full
void resize_if_full(ArrayList *listPtr);
// delete an element from the array list
void delete_al(int value, ArrayList *listPtr);
// remove all of an element from array list
void purge_al(int value, ArrayList *listPtr);

int main_al(int argc, char *argv[])
{
    ArrayList *listPtr = create_al();
    ArrayList list = *listPtr;
    for (int i = 10; i >= 0; --i)
    {
        insert_al(i, listPtr);
    }

    insert_al(0, listPtr);
    insert_al(5, listPtr);
    insert_al(10, listPtr);
    insert_al(10, listPtr);

    // delete_al(0, listPtr);
    // delete_al(5, listPtr);
    // delete_al(10, listPtr);

    print_al(*listPtr);
    purge_al(10, listPtr);
    print_al(*listPtr);
    destroy_al(listPtr);

    listPtr = create_al(); 
    for(int i = 0, j; i <4; ++i)
    {
        for(j = 0; j < 3; ++j)
        {
            insert_al(j, listPtr);
        }
    }
    print_al(*listPtr);

    purge_al(0, listPtr);
    print_al(*listPtr);
    purge_al(3, listPtr);
    print_al(*listPtr);
    purge_al(1, listPtr);
    print_al(*listPtr);
    purge_al(2, listPtr);
    print_al(*listPtr);
    destroy_al(listPtr);

    return 0;
}

ArrayList *create_al()
{
    ArrayList *new = malloc(sizeof(ArrayList));
    new->length = 0;
    new->capacity = INITIAL_CAPACITY;

    // new.array = malloc(new.capacity * sizeof(int));
    // calloc(length, size) for allocating array
    new->array = calloc(new->capacity, sizeof(int));

    return new;
}

void destroy_al(ArrayList *listPtr)
{
    free(listPtr->array);
    free(listPtr);
}

void insert_al(int value, ArrayList *listPtr)
{
    // re-size if full
    resize_if_full(listPtr);

    // insert
    size_t i;
    for (i = (listPtr->length)++;
         i > 0 && (listPtr->array)[i - 1] > value;
         i--)
    {
        listPtr->array[i] = listPtr->array[i - 1];
    }
    listPtr->array[i] = value;
}

void resize_if_full(ArrayList *listPtr)
{
    if (listPtr->length == listPtr->capacity)
    {
        listPtr->capacity *= 2;
        // realloc: re-allocate memory
        listPtr->array = realloc(listPtr->array, listPtr->capacity * sizeof(int));
    }
}

void print_al(ArrayList list)
{
    for (size_t i = 0; i < list.length; i++)
    {
        printf("%d,", list.array[i]);
    }
    puts("");
}

void delete_al(int value, ArrayList *listPtr)
{
    // loop to find element
    size_t i;
    for (i = listPtr->length; i > 0 && listPtr->array[i - 1] > value; --i)
        ;

    if (i == 0 || listPtr->array[i - 1] < value)
        return;

    for (; i < listPtr->length; ++i)
    {
        listPtr->array[i - 1] = listPtr->array[i];
    }

    // reduce length of list
    --listPtr->length;
}
void purge_al(int value, ArrayList *listPtr)
{
    size_t i;
    size_t count;
    for(i = 0; i < listPtr -> length && listPtr->array[i] < value; ++i);
    for(count = 0; i < listPtr->length&& listPtr->array[i]==value; ++i, ++count);
    if(count > 0)
    {
        for(; i < listPtr-> length; ++i)
        {
            listPtr->array[i-count] = listPtr->array[i];
        }
        listPtr->length -=count;    
    }

}