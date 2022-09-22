#include <stdio.h>


void print_in_order(int a[], size_t length);

int main_9_14(int arc, char *argv[])
{
    int a[5] = {1,2,3,4,5};
    print_in_order(a, 5);
    

    char *suits[] = {"Diamonds", "Clubs", "Hearts", "Spades"};
    char *faces[] = {""};
    return 0;
}


void print_in_order(int a[], size_t length)
{
    if(length == 0)
    {
        return;
    }
    printf("%d\n", a[0]);
    
    return print_in_order(a+1, length - 1);

}

/*
Binary Search Recursion? 
parameter are array length target
check middle value 
if not target: 
    call again on either array and length/2 or array+length/2 and length /2 

int binary_search(arr, len, target)
{
    base case: 
        target
    otherwise:
        recursive shit
}

*/