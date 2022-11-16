#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>


void star(int num);
static int myCompare(const void* a, const void* b); 
void sort(const char* arr[], int n);
bool perfect_num(int n);
double stod(const char* s);
int funInfun(int (*f)(int), int n);

bool main(int argc, char *argv[])
{
    //Number 1
    star(4);

    //Number 2
    const char* arr[] = { "slay", "kleiner", "Data Structures" };
    int n = sizeof(arr) / sizeof(arr[0]);
    int i;
 
    // Print the given names
    printf("Given array is\n");
    for (i = 0; i < n; i++)
        printf("%d: %s \n", i, arr[i]);
 
    // Sort the given names
    sort(arr, n);
    // Print the sorted names
    printf("\nSorted array is\n");
    for (i = 0; i < n; i++)
        printf("%d: %s \n", i, arr[i]);


    //Number 3
    printf(perfect_num(6) ? "true\n" : "false\n");
    printf(perfect_num(16) ? "true\n" : "false\n");

    //Number 4
    printf("%f\n", stod("-435.123"));
    

}

void star(int num)
{
    static int done = 0;
    static int sum = 0;
    
    for (int i = 1; i <num + 1; ++i)
    {printf("*");}
    if(num != 0)
    {puts("");}
    if(num + 1 == sum && done == 1)
    {
        return;}
    if(num != 0 && done == 0)
    {
        ++sum;
        star(num-1);
    }
    if(num == 0)
    {
        done = 1;
    }
    else if(done == 1 && num != sum)
    {
        star(num+1);
    }
}



static int myCompare(const void* a, const void* b)
{
    return strcmp(*(const char**)a, *(const char**)b);
}
void sort(const char* arr[], int n)
{
    qsort(arr, n, sizeof(const char*), myCompare);
}


bool perfect_num(int n)
{
    int sum = 0;
    for(int i = 1; i < n; ++i)
    {
        if(n%i == 0)
        {sum += i;}
    }
    if(n == sum)
    {return true;}
    else
    {return false;}
}

double stod(const char* s)
{   
    double rez = 0, fact = 1;
    if (*s == '-'){
        s++;
        fact = -1;
    };
    for (int point_seen = 0; *s; s++){
        if (*s == '.'){
            point_seen = 1;
            continue;
        };
        int d = *s - '0';
        if (d >= 0 && d <= 9){
            if (point_seen) fact /= 10.0f;
            rez = rez * 10.0f + (float)d;
        };
    };
    return rez * fact;
}


// didnt test my b but theoretically shoudl work
int funInfun(int (*f)(int), int n)
{
    int sum = 0;
    for(int i = 0; i < n; ++i)
    {
        int add = f(i);
        sum+= add;
    }
    return sum;
}


