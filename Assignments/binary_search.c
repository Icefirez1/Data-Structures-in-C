#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#include <stdbool.h>
#include <string.h>

//arr is sorted
int bin_search(int arr[], int size, int value)
{
    //something like this
    int val_index;
    if (size < 2 || arr[size/2] == value)
    {
        return 0;
    }
    else if(value > arr[size/2])
    {
        val_index = bin_search(arr, size - (size/2), value) + 1; 
    }
    else if(value < arr[size/2])
    {
        val_index = bin_search(arr + (size/2), size - (size/2), value) + 1;
    
    }

    return val_index;
}

int main(int argc, char **argv)
{
    int arr[] = {1,2,3,4,5};
    printf("%d", bin_search(arr, 5, 3));
    return 0; 
}
