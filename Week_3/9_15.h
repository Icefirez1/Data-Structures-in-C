#include <stdio.h>
#include <stdlib.h>



// making our own type
struct test
{
    int x; 
    char y;
} Test;

struct test2
{ 
    long long k;
    // char a;
    // char b;
} Test2;



int main_9_15(int arc, char *argv[])
{
    
    char *suits[] = {"Diamonds", "Clubs", "Hearts", "Spades"};
    char *faces[] = {"Deuce", "Crab", "Sharptop", "Nickel", "Sax", "Fishhook", "Snowman", "Niner", "Dime", "Boy", "Stenographer", "Cowboy", "Seed"};
    int FACES = 13, SUITS = 4; 

    // i mod face to cycle throuh and i / faces (integer divisioni) to go from 1 -4 
    // for(int i = 0; i < SUITS*FACES; ++i)
    // {
    //     printf("%s of %s\n", faces[i%FACES], suits[i/ FACES]);
    // }
    // return 0;

    /*
    We also gotta implement fisher yates shuffle
    https://www.geeksforgeeks.org/shuffle-a-given-array-using-fisher-yates-shuffle-algorithm/
    */


   struct test var = {42, 'K'};
   struct test var2;
   var2.x = var.x;
   printf("%d %c\n", var.x, var.y);
   struct test *varPtr = &var;
    printf("%d %c\n", varPtr -> x, varPtr -> y);
    printf("%zu\n", sizeof(var));

    struct test2 var3;

    printf("%zu\n", sizeof(var3));

   return 0;
}