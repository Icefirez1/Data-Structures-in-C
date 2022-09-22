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

