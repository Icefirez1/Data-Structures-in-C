 #include <stdio.h> //these include modules btw
#include <stdlib.h>
#include <stdbool.h>



void bubblesort(int a[], int n) // c can't see the len of arr
{
  int i,j, tmp; 
  
  bool sorted;
  for (int i = 0, sorted = false; !sorted && i < n-1; ++i)
    {
      sorted = true;
      for(int j = 0; j < n-1 -i; ++j)
        {
          if (a[j] > a[j+1])
          {
            tmp = a[j];
            a[j] = a[j+1];
            a[j+1] = tmp;
            sorted = false;
          }
        }
    }
  //printf("%d\n", i);
}

void insertionsort(int a[], int n) //prolly not insertions sort but it sort
{
  int i,j, tmp; 
  
  for (int i = 0;i < n-1; ++i)
    {
      for(int j = n-1 ; j > i; --j)
        {
          if (a[j] < a[j-1])
          {
           tmp = a[j];
           a[j] = a[j-1];
           a[j-1] = tmp;
          }
        }
    }
}





void selectionsort(int a[], int n) 
{
  int i,j, tmp, min;
  for(int i = 0; i < n-1; ++i, min =i)
    {
      // finds min
      for (int j = i; j < n-1; j++)
        {
          if(a[min] > a[j])
          {
            min = j;
          }
        }

      //swaps em out
      tmp = a[i];
      a[i] = a[min];
      a[min] = tmp;
    }
}

void kleiner_insertionsort(int a[], int n)
{
  int i, j, value; 
  for(i = 1; i < n; ++i)
    {
      value = a[i];
      for(j =i; i > 0 && a[j-1] > value; --j)
        {
          a[j] = a[j-1];
        }
      a[j] = value;
    }
}