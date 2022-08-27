#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include "sorting.h"
#include "8_25.h"

void bubblesort(int a[], int n);
void selectionsort(int a[], int n);
void insertionsort(int a[], int n);
int main_8_25(void);

int main(void)
{  
  printf("Hello World\n");
  
  main_8_25();

  // srand(42);
  // int n = 200000; 
  // int a[n];
  // for (int i = 0; i < n; ++i)
  //   {
  //     a[i] = rand() %n;
  //   }


  // int b[n];
  // memcpy(b, a, sizeof(int)*n);
  // int c[n];
  // memcpy(c, a, sizeof(int)*n);
  

  
  // // for (int j = 0; j < n; ++j)
  // //   {
  // //     printf("%d,", b[j]);
  // //   }
  // // puts("");

  // clock_t start, end; 
  // start = clock();
  // bubblesort(a,n);
  // end = clock();
  // printf("Bubble sort time: \n%f\n", (double)(end-start)/CLOCKS_PER_SEC);

  // start = clock();
  // selectionsort(b,n);
  // end = clock();
  //   printf("Selection sort time: \n%f\n", (double)(end-start)/CLOCKS_PER_SEC);

  // start = clock();
  // kleiner_insertionsort(c,n);
  // end = clock();
  //   printf("Insertion sort time: \n%f\n", (double)(end-start)/CLOCKS_PER_SEC);

  
  // // for (int j = 0; j < n; ++j)
  // //   {
  // //     printf("%d,", a[j]);
  // //   }
  // // puts("");

  // //printf("%f\n", (double)(end-start)/CLOCKS_PER_SEC);

  
  return 0;
}