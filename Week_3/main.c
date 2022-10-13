#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#include <stdbool.h>
#include <string.h>
//#include "9_7.h"s
//#include "9_8.h"
#include "9_9.h"
#include "9_14.h"
#include "9_15.h"

int main(int argc, char **argv)
{
    //printf("Hello World\n");

    // main_9_15(argc, argv)[];
    int test = 0;
    int *ptr = &test; 
    printf("%d\n", *&ptr);
    printf("%d\n", &*ptr);\
    int arr[] = {1,2,3,4,5};
    printf("%d\n", arr+1);
    char str[] = "yuh";
    printf("%c", str[3]);

    int i = 0;
    for(;;)
    {
        printf("%d\n", 3);
    }
    printf("akjdsl");
    return 0; 
}
