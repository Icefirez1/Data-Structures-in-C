#include <stdio.h>

void slay(int []);

void slay(int arr[5])
{
    printf("%zu\n", sizeof(arr));

}

int main_9_9(void)
{
    int arr[5] = {1,2,3,4,5};
    slay(arr);
    return 0;
}