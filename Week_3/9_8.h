#include <stdio.h>

void print_size_of(int arr[][3], size_t n)
{
    printf("%zu\n", sizeof(arr));
    printf( "%zu\n",sizeof(arr[0]));
    //printf(%d\n, arr[1][0])
}


void print_size_of_more(int **arr)
{
    printf("%zu\n", sizeof(arr));
    printf("%zu\n", sizeof(*arr));
    printf("%p, %p\n", arr, *arr); 
    printf("%p\n", *arr+3);
    
}

+654

int main_9_8(int argc, char **argv)
{
    // int a[][3] = {{1,2,3},{4,5,6}};
    // printf("%d\n", *(*a+5));
    // int *b = *a;
    // printf("%d\n", *(b+5));
    // printf("%p %p\n", a, *a);   
    // for (size_t i = 0, j;i < 2; i++)
    // {
    //     for(j = 0; j < 3; ++j)
    //     {
    //         printf("%d,", *(a+i));
    //     }
    // }

    // int x = 6;
    // printf("\n%p\n", &x);

    // int *xptr = &x; //&  assigns memory address
    // printf( "%p\n",xptr );
    // printf( "%d\n",*xptr ); // doing * to a pointer gets the stuff

    // // print_size_of(a,2);
    // // print_size_of_more(a);

    // char *strings[] = {"Keethan", "Kleiner", "Rainbow", "Valve"};
    // for (size_t i = 0; i < 4; ++i)
    // {
    //     puts(strings[i]);
    // }
    // char **s = strings;
    // for (size_t i = 0; i < 4; ++i)
    // {
    //     puts(*(s+i));
    // }
    // if (argc > 0)
    // {
    //     puts(*(argv+0));    
    // }
//     if( argc == 2 ) {
//       printf("The argument supplied is %s\n", argv[1]);
//    }
//    else if( argc > 2 ) {
//       printf("Too many arguments supplied.\n");
//    }
//    else {
//       printf("One argument expected.\n");
//    }



    return 0;
}

