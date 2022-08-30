// # is a preprocessor directive

#include <stdlib.h> 

enum Status {CONTINUE, WON, LOST};

int max(int a, int b, int c)
{

    if (b > a)
    {a = b;}
    if (c >a)
    {a =c;}
    return a;

    // ex 1    
    //tenary operationr -> condition ? return if true : return if false
    //return a >=b && a>=c ? a : b>=c ? b : c ;
     
    // ex 3
    // if (a >= b && a >= c)
    // {return a;}
    // else if(b >= c)
    // {return b;}
    // else
    // {return c;}

    // ex 2
    // if(a > b)
    // {
    //     if(a > c)
    //     {return a;}
    //     else 
    //     {return c;}
    // }
    // else
    // {
    //     if(b >c)
    //         {return b;}
    //     else
    //     {return c;}
    // }


}

int factorial_recursive(int n)
{
    if (n < 2)
    {return 1;}
    return n * factorial_recursive(n-1);
}

int factorial_iterative(int n)
{
    end = 1;
    for(int i = n)
}

int main_8_29(void)
{
    enum Status game_state = WON;
    printf("%d\n", game_state);

    printf("%d\n", max(4,10,12));

    printf("%d\n", factorial_recursive(4));

    return 0;
}

/*
Craps
Roll 2d6 
If 7 or 11, player wins
Else if 2, 3, or 12 player loses 
Else, record the sums as the players point
Continue rolling until the player makes their "point" and wins or rolls a 7
*/