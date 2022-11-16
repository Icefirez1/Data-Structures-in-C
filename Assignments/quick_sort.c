#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>



void quick_sort(int * arr, size_t length);
size_t partition_arr(int* arr, size_t length); 
void pivot_p(int* arr, size_t length);
void printarr(int* arr, size_t length);
int * random_arr(size_t length);

int main(int argc, char **argv)
{

    //initialize
    size_t length = 10;
    int *arr = random_arr(length);

    //unsorted
    printarr(arr, length);

    //sorting
    quick_sort(arr, length);

    //sorted
    printarr(arr, length);

    return 0;
}


void quick_sort(int * arr, size_t length)
{
    pivot_p(arr, length);
    if(length <= 1)
        {return;}
    size_t partition = partition_arr(arr, length);
    quick_sort(arr, partition);
    quick_sort(arr+partition, length-partition);
}


size_t partition_arr(int* arr, size_t length)
{

    if(length <= 1)
        {return 0;}

    int pivot = arr[length/2];
    size_t i = -1; 
    size_t j = length;
    int tmp;

    while(true)
    {
        do{++i;}while(arr[i] < pivot);
        do{--j;}while(arr[j] > pivot);

        if(i>= j)
            {return i;}
        
        tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    } 

}   


void pivot_p(int* arr, size_t length)
{
    int temp;
    if(arr[0] > arr[length/2])
    {
        temp = arr[0];
        arr[0] = arr[length/2];
        arr[length/2] = temp;
    }
    if(arr[length/2] > arr[length-1])
    {
        temp = arr[length-1];
        arr[length-1] = arr[length/2];
        arr[length/2] = temp;
    }
}


void printarr(int* arr, size_t length)
{
    for(size_t i = 0; i < length; ++i)
        {
            printf("%d,", arr[i]);
        }
    puts("");
}

int * random_arr(size_t length)
{
    srand(52);
    int * out = calloc(length, sizeof(int));
    for(int i = 0; i < length; ++i)
    {
        out[i] = rand()%10;
    }
    return out;
}