#include <stdlib.h> 

unsigned int factorial_recursive(unsigned int n)
{
    if (n < 2)
    {return 1;}
    return n * factorial_recursive(n-1);
}

unsigned int factorial_iterative(unsigned int n)
{
    unsigned int i; 
    for(i = 1; n > 1; i *=n--);
    return i;
}

unsigned int fibonacci_recursive(unsigned int n)
{
    if(n < 2)
    {return n;}
    return fibonacci_recursive(n-1) + fibonacci_recursive(n-2);
}

unsigned int fibonacci_iterative(unsigned int n)
{
    // if (n < 2)
    // {return n;}

    unsigned int i;
    unsigned int last = 1;
    for(i = 1; i < n;)
        i = i + last;
        last = i; 

    return i;

}

int main_8_31(void)
{

    printf("%u\n", factorial_recursive(1));
    printf("%u\n", factorial_iterative(1));
    

    printf("%u\n", fibonacci_recursive(1));
    printf("%u\n", fibonacci_recursive(1));

    return 0;
}


/*
Storage classes : 
static - lifetime of the program 
auto - lifetime of scope 
extern - available outside of file 
register - stored on processor

static variables will be used alot 
lots of recursion rip 

*/





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