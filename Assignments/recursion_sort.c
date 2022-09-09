#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#include <stdbool.h>
#include <string.h>


/*
pseudocode algorithms for these sort recursively:) 


selection_sort(array, size)
{
    base case: end of array
    otherwise:
        selection_helper()
        swap 0 and min 
        selection_sort(array+1, size-1)
}

selection_helper(subarr, size , value)
{
    static min_index 
    base case: end of array
        return 0
    otherwise: 
        min = selection+helpter(arr+1, size-1) +1
        compare and return min_index
}


insertion 
insertion_sort(arr, size)
{
    base case: end of array 
        return end
    otherwise: 
        insertion sort(arr, size -1)
        insertion_helper(arr, size, arr[size-1])


its getting subarrays like selection array


}

insertion_sort_helper(subarr, size, value)
{
    base case: arr of size 1 or element >= arrary(size-2)
        array[size-1] = value
    otherwise:
        array[size-1] = array[size-2]
        insertion_helper(array, size-1, value)

}   
*/ 



void selection_sort(int arr[], int n)
{

}

int main(void)
{
    printf("Hello World\n");
    return 0;
}