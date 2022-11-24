#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/*
Write a function that takes a size and returns an array of strings. 
Initialize the array using calloc, because there should be no strings in it.

Write a function that takes a pointer to an array of strings
and a size and reassigns the pointer to reallocated memory double the size.

Write a function that takes an array of strings and a size and returns a duplicate, 
with each string being copied using strcpy, not just being pointed to.

Write a function that takes a pointer to a string, an array of 
strings, and a size and
concatenates all the strings in the array to the string 
using strcat and changes the pointer.

Create a Name struct with three string attributes: first, middle, and last.
 Write a function that takes a Name pointer and returns a 
 string with the three attributes concatenated together with a space between them.
Include only the necessary spaces for the present attributes:
 do not include a prefix space if there is no first name, 
 do not include an extra space in the middle if there is no middle name, 
 and do not included a suffix space if there is no last name.

*/

typedef struct name
{
  char* first;
  char* middle;
  char* last;
} Name;

typedef Name* NamePtr;


char ** make_str_array(size_t size);
char ** double_str(char** string_in, size_t size);
char ** copy_str(char** string_in, size_t size);
char * concat_str(char* string_out, char** arr, size_t size);
char* concatStrArr(char** string, char** arr, size_t n);
char* concatName(NamePtr x);


int main(int argc, char **argv)
{
    //Question 1
    char ** arr= make_str_array(4);
    arr[0] = "Keethen";
    arr[1] = "Kleiner";
    arr[2] = "Al";
    arr[3] = "Chris";
    for(size_t i = 0; i < 4; ++i)
        printf("%s, ", arr[i]);
    puts("");


    //Question 2
    char ** doublearr = double_str(arr, 4);

    doublearr[4] = "Ryan";
    doublearr[5] = "Helen";
    doublearr[6] = "Eric";
    doublearr[7] = "Myles";
    for(size_t j = 0; j < 8; ++j)
        printf("%s, ", doublearr[j]);
    puts("");

    //Question 3
    char * array[4] = {"slay", "slay", "slay", "slay"};
    char ** copy_arr = copy_str(array, 4);
    for(size_t i = 0; i < 4; ++i)
        printf("%s, ", copy_arr[i]);
    puts("");


    // //Question 4
    char * str = "slay";
    char * concat = concat_str(str, array, 4);
    printf("%s, ", concat);


    // // Question 5
    // Name me = {"Gimelo", "Al", "Pagar"};
    // char* out = concatName(&me);
    // printf("%s\n", out);

    





}



//right
char ** make_str_array(size_t size)
{
    char ** giving = calloc(size, sizeof(char*));
    return giving;
}


//wrong
char** double_str(char** string_in, size_t size)
{
    
    char ** double_arr = realloc(string_in, sizeof(char*)*size*2);
    return double_arr;
}

//wrong
//fixed!
char ** copy_str(char** string_in, size_t size)
{
    char ** giving = calloc(size, sizeof(char*));
    for(size_t i = 0; i < size; ++i)
    {
        char * out = malloc(sizeof(char*));
        strcpy(out, string_in[i]);
        giving[i] = out;
    }
    return giving;
}


//wrong lol
char * concat_str(char* string_out, char** arr, size_t size)
{
    char* concat = malloc(sizeof(char*));
    strcat(concat, string_out);
    for(size_t i = 0; i < size; ++i)
    {
        strcat(concat, arr[i]);
    }
    return concat;
}


//wrong
char* concatName(NamePtr x)
{
  char* concat = malloc(sizeof(char*));
  // concat = "";
  if(x -> first != NULL)
  {
    strcat(concat, x -> first);
    strcat(concat, " ");
  }
  if(x -> middle != NULL)
  {
    strcat(concat, x -> middle);
    strcat(concat, " ");
  }
  if(x -> last != 0)
  {
    strcat(concat, x -> last);
  }
  return concat;
}