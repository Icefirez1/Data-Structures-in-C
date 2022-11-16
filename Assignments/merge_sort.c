#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>


void merge_sort(int *arr, size_t length);
void CopyArray(int* og, int* copy, size_t length);
void printarr(int* arr, size_t length);
void merge_helper(int* arrA, int* arrB, size_t length);
int * random_arr(size_t length);

int main(int argc, char **argv)
{
    //initialize
    size_t length = 11;
    int *arr = random_arr(length);

    //unsorted
    printarr(arr, length);

    //sorting
    merge_sort(arr, length);

    //sorted
    printarr(arr, length);

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

void merge_sort(int *arrA, size_t length)
{
    int * arrB = calloc(length, sizeof(int));
    CopyArray(arrA, arrB, length);
    merge_helper(arrA, arrB, length);

}

void CopyArray(int* og, int* copy, size_t length)
{
    for(size_t i = 0; i < length; ++i)
    {
        copy[i] = og[i];
    }
}


void merge_helper(int* arrA, int* arrB, size_t length)
{
    if(length == 1)
        {return;}

    merge_helper(arrB, arrA, length/2);
    merge_helper(arrB+(length/2), arrA+(length/2),length/2 + (length%2));
    //merge B into A

    //a is merged list 
    int *listA = arrB; 
    size_t sizeA = length/2; 
    int *listB = arrB +(length/2);
    size_t sizeB = length/2 + (length%2); 

    size_t indexA = 0, indexB = 0;

    while (indexA < sizeA && indexB < sizeB)
    {
        if (listA[indexA] < listB[indexB])
            {
                arrA[indexA + indexB] = listA[indexA];
                ++indexA;
            }
        else
            {
                arrA[indexA + indexB] = listB[indexB];
                ++indexB;
            }
    }
    for (; indexA < sizeA; indexA++)
        arrA[indexA + indexB] = listA[indexA];
    for (; indexB < sizeB; indexB++)
        arrA[indexA + indexB] = listB[indexB];
}




void printarr(int* arr, size_t length)
{
    for(size_t i = 0; i < length; ++i)
        {
            printf("%d,", arr[i]);
        }
    puts("");
}