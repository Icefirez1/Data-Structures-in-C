#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#include <stdbool.h>
#include <string.h>

size_t bin_search(int arr[], int size, int value); 
void print_array(int arr[], int n);

int main(int argc, char **argv)
{
    size_t n = 1000;
    int arr[n];
    
    for (size_t i = 1; i < n + 1; ++i)
    {  
        arr[i-1] = ((int)i * 2);
    }
    // print_array(arr, n);

    printf("Binary Search on element inside list (300), index: %d\n", bin_search(arr,n, 300));
    printf("Binary Search on element ouside list (1), index: %d\n", bin_search(arr,n, 1));
    printf("Binary Search on element ouside list (4000), index: %d\n", bin_search(arr,n, 4000));
    printf("Binary Search on element not in list (3), index: %d\n", bin_search(arr,n, 3));


    return 0; 
}

void print_array(int arr[], int n)
{
     for (size_t i = 0; i < n-1; ++i) {
        printf("%d,", arr[i]);
    }
    printf("%d\n", arr[n - 1]);
}

//arr is sorted
size_t bin_search(int arr[], int size, int value)
{
    //something like this
    size_t mid = size/2;
    if(size == 1 && arr[size/2] != value)
    {
        return -1;
    }
    else if (arr[size/2] == value)
    {
        return mid;
    }
    else if(value < arr[size/2])
    {
        size_t index = bin_search(arr, size - mid, value);
        return index; 
    }
    else if(value > arr[size/2])
    {
        size_t index = bin_search(arr + mid, size - mid, value);
        if(index != -1)
            return mid + index;
        else if(index == -1);
            return index;
    }
}


