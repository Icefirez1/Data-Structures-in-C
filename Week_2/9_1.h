#include <stdio.h> 

void fun(int arr[] ,size_t n)
{
    printf("%zu\n", sizeof(arr));
    printf("%p\n", arr);
    printf("%p\n", &arr);
    printf("%p\n", &arr[0]);
    printf("%p\n", &arr[1]);
    printf("%p\n", &arr+1 ); 
}


int main_9_1(void)
{
    size_t n = 5;
    int arr[n];
    printf("%zu\n", sizeof(arr));
    printf("%p\n", arr);
    printf("%p\n", &arr);
    printf("%p\n", &arr[0]);
    printf("%p\n", &arr[1]);
    printf("%p\n", &arr+1 ); 

    puts("fun:");
    fun(arr[n]+1, n-1);
    return 0; 
}