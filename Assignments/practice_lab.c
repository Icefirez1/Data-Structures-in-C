#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>



/*
Questions
1. Seed the RNG with 42. Write a function that flips a coin (0 or 1) n times and returns the number of 0s rolled.

2. Seed the RNG with 42. Write a function that rolls n 6-sided dice and returns the number of rolls required until they all match.

3. Write a recursive function that determines if a string is a palindrome and returns True or False.

4. Write a function that determines the lowest possible base of an input string from 2 to 36, all uppercase, e.g., "1010" should return 2 and "Z5" should return 36.

5. Write a function that takes in a string of lowercase letters (no numbers, punctuation, or whitespace) and a number from 0 to 25. It performs a Caesar Shift on each letter by that amount and returns an uppercase string, e.g., "xyz", 1 returns "YZA".
*/

int coin(int flips);
int all_dice(int num_dice);
unsigned int roll_die(unsigned int sides);
char *caeser_cipher(char *string, int shift);
int lowest_base(char string[]);
bool palindrome(char string[], int start, int end);


int main(int argc, char **argv)
{
    srand(42);
    //number 1
    int flips = 5;
    printf("Coin flips %d times and 0 was flipeed %d times\n", flips, coin(flips));

    //number 2
    int die_num = 4;
    printf("Times it took for %d die to be da same is %d rolls\n", die_num, all_dice(die_num));

    //number 3
    char test_string[] = "Z";
    printf("Lowest base is: %d\n", lowest_base(test_string));
    

    //number 4; 
    char palingdrom[] = "tacocat";
    char notpal[] = "slay";
    printf("palindrom? 1 = true 0 = false: %d\n", palindrome(palingdrom, 0, 6));
    printf("palindrom? 1 = true 0 = false: %d\n", palindrome(notpal, 0, 3));
    printf("palindrom? 1 = true 0 = false: %d\n", palindrome("", 0, 0));
    
    //number 5
    char string[] = "z";
    printf("Shifted word: %s\n", caeser_cipher(string, 1));


}


int coin(int flips)
{
    int zero_flip = 0;
    int flip;
    for(size_t i = 0; i < flips; ++i)
    {
        flip = rand() % 2;
        if(flip == 0)
        {++zero_flip;}
    }
    return zero_flip;
}

unsigned int roll_die(unsigned int sides)
{
    unsigned int diff = (RAND_MAX +1) % sides;
    unsigned int roll;
    do{
        roll = rand();
    } while (roll  - diff>= RAND_MAX); 

    return roll % sides + 1;

}

int all_dice(int num_dice)
{
    int rolls = 0;
    bool same = false; 
    unsigned lastroll;

    while (!same)
    {
        lastroll = roll_die(6);
        if(num_dice == 1)
        {same = true;}

        int num_same = 1;
        for(int i = 0; i < num_dice-1; ++i)
        {
            unsigned int currentroll = roll_die(6);
            if(currentroll == lastroll)
            {++num_same;}
            lastroll = currentroll;
        }
        if(num_same == num_dice)
        {same = true;}
        ++rolls;
    }
    return rolls;
}


char *caeser_cipher(char *string, int shift)
{
    char *new_string = (char *)malloc(strlen(string));
    for(int i = 0; string[i] != '\0'; ++i)
    {
        char ch = string[i];
        if(ch >= 'a' && ch <= 'z')
        {ch = ch + shift;}
        if(ch > 'z')
        {ch = ch - 'z' + 'a' - 1;}
        new_string[i] = ch - 32;
    }
    return new_string;

}


int lowest_base(char string[])
{
    char max_char = string[0];
    for(int i = 0; i < strlen(string); ++i)
    {
        if(string[i] > max_char)
        {max_char = string[i];}
    }
    int num = (int)(max_char);
    if(num > 47 && num < 58)
    {return num - 47;}
    else
    {return num -54;}
}


bool palindrome(char string[], int start, int end)
{
    if (start == end)
    {return true;}
    if(string[start] != string[end])
    {return false;}
    if(start < end + 1)
    {return palindrome(string, start + 1, end -1);}
    return true;
}
