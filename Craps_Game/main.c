#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include "dice.h"
#include "craps.h"


//enum Status {CONTINUE, WON, LOST};

unsigned int roll_die(unsigned int sides);
enum Status craps(void);

int main(void)
{

    srand(42);
    enum Status game_status = craps();

    if(game_status == WON)
    {
        printf("YOU WON!\n");
    }
    else
    {printf("loser\n");}

    return 0;
}