#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>


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

selection_helper(subarr, size)
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

/*five steps to solve recursive problems (from yt vid)

1. What is the simplest possible input?
2. Play around with examples and visualize 
3. Relate hard cases to simpler cases 
4. Generalize the pattern 
5. Write code by combining recursive patter with base case

*/


void selection_sort_recursive(int arr[], int n);
int selection_helper(int arr[], int size);
void insertion_sort_helper(int arr[], int size, int value);
void insertion_sort_recursive(int arr[], int size);
void selection_sort_iterative(int a[], int n);
void insertion_sort_iterative(int a[], int n);
void print_array(int arr[], int n);
void fill_array(int arr[], int n, int max_num);
void copy_array(int arr1[], int arr2[], int size);
double median(int arr[], int size);
double mean(int arr[], int size);
void mode(int arr[],int n, int count_arr[], int max_num );

int main(void)
{   

    //Initializing 
    // This is how you change the parameters for how big the arrays are and the max num
    int n = 10;
    int test_arr[n];
    int og_arr[n];
    int max_num = 5;
    int count_arr[max_num];
    clock_t start, end; 

    fill_array(test_arr, n, max_num);

    printf("Original:\n");
    print_array(test_arr, n);
    copy_array(og_arr, test_arr, n);

    printf("Selection:\n");
    printf("Selection Sort Recursively\n");
    print_array(test_arr, n);
    start = clock();
    selection_sort_recursive(test_arr, n);
    end = clock();
    print_array(test_arr, n);
    printf("Selection Sort Recursively sort time: %f\n", (double)(end-start)/CLOCKS_PER_SEC);

    copy_array(test_arr, og_arr, n);

    printf("Selection Sort Recursively\n");
    print_array(test_arr, n);
    start = clock();
    selection_sort_iterative(test_arr, n);
    end = clock();
    print_array(test_arr, n);
    printf("Selection Sort Iteratively sort time: %f\n", (double)(end-start)/CLOCKS_PER_SEC);

    copy_array(test_arr, og_arr, n);
    
    printf("Inerstion:\n");
    printf("Insertion Sort Recursively\n");
    print_array(test_arr, n);
    start = clock();
    insertion_sort_recursive(test_arr, n);
    end = clock();
    print_array(test_arr, n);
    printf("Insertion Sort Recursively sort time: %f\n", (double)(end-start)/CLOCKS_PER_SEC);
    
    copy_array(test_arr, og_arr, n);
    printf("Insertion Sort Iteratively\n");
    print_array(test_arr, n);
    start = clock();
    insertion_sort_iterative(test_arr, n);
    end = clock();
    print_array(test_arr, n);
    printf("Insertion Sort Iteratively sort time: %f\n", (double)(end-start)/CLOCKS_PER_SEC);

    printf("Mean: %.1f\n", mean(test_arr, n));
    mode(test_arr, n, count_arr, max_num);
    printf("Median: %.1f\n", median(test_arr, n));

    return 0;
}

void selection_sort_recursive(int arr[], int n)
{
    if (n < 2)
        return;
    else
    {
        int min = selection_helper(arr, n);
        int tmp = arr[0];
        arr[0] = arr[min];
        arr[min] = tmp;
        selection_sort_recursive(arr + 1, n - 1);
    }

}

int selection_helper(int arr[], int size)
{
    
    if (size < 2)
    {
        return 0;
    }
    else
    {
        int min_index = selection_helper(arr + 1, --size ) + 1; 
        if(arr[0] <= arr[min_index])
        {
            min_index = 0;
        }
        return min_index;
    }
}

void insertion_sort_helper(int arr[], int size, int value)
{
    if(size < 2 || value >= arr[size - 2])
    {
        arr[size -1] = value;
        return;
    }
    else
    {
        arr[size -1] = arr[size -2];
        insertion_sort_helper(arr, size-1, value);
    }
}

void insertion_sort_recursive(int arr[], int size)
{
    if (size < 2)
    {return;}
    else
    {
        insertion_sort_recursive(arr, size -1);
        insertion_sort_helper(arr, size, arr[size -1]);
    }
}

void selection_sort_iterative(int a[], int n) 
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

void insertion_sort_iterative(int a[], int n)
{
  int i, j, value; 
  for(i = 1; i < n; ++i)
    {
      value = a[i];
      for(j =i; j > 0 && a[j-1] > value; --j)
        {
          a[j] = a[j-1];
        }
      a[j] = value;
    }
}

void print_array(int arr[], int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        printf("%d,", arr[i]);
    }
    printf("%d\n", arr[n - 1]);
}

void fill_array(int arr[], int n, int max_num)
{
    srand(42);
    for (int i = 0; i < n; ++i)
    {
        arr[i] = rand() % max_num + 1;
    }

}

void copy_array(int arr1[], int arr2[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        arr1[i] = arr2[i];
    }
}

double median(int arr[], int size)
{
    return arr[size/2];
}

double mean(int arr[], int size)
{
    double sum = 0;
    for (int i = 0; i < size; ++i)
    {
        sum = sum + arr[i];
    }
    return sum/size;
}

void mode(int arr[],int n, int count_arr[], int max_num )
{
    //Mr. Kleiner I know this implementatio of mode if absolutely disgusting
    // But hey it gets the job done lol
   int maxCount = 0;
    for (int i = 0; i < max_num; ++i)
    {count_arr[i] = 0;}
    
    printf("Mode: ");

   for (int i = 0; i < n; ++i) 
   {
      int count = 0;
      
      for (int j = 0; j < n; ++j)
      {
         if (arr[j] == arr[i])
         {++count;}
         count_arr[arr[j]] = 0;
      }
      if (count > maxCount)
      {
         maxCount = count;
      }
   }


   for (int i = 0; i < n; ++i) 
   {
      int count = 0;
      
      for (int j = 0; j < n; ++j)
      {
         if (arr[j] == arr[i])
         {++count;}
      }
      if (count == maxCount)
      {
        count_arr[arr[i]-1] = 1;
      }
   }
   for(int k = 0; k < max_num; ++k)
   {
    if(count_arr[k] == 1)
    {
        printf("%d ", k + 1);
    }
   }
   puts("");


}

