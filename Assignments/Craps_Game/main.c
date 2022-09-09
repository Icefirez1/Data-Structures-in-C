#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include "dice.h"
#include "craps.h"


//enum Status {CONTINUE, WON, LOST};

unsigned int roll_die(unsigned int sides);
enum Status craps(int *ptr);

int main(void)
{
    static int game_length = 1;
    int *game_point = &game_length;
    srand(42);
    enum Status game_status;

    unsigned int wons = 0;
    int n = 1000; 
    unsigned int count = 0;

    for(int i = 0; i < n; i++)
    {
        game_status = craps(game_point);
        if(game_status == WON){++wons;}
        count += game_length;
    }

    float avg_win = ((float)wons/n) *100 ; 
    float avg_len = (float)count/n; 

    //printf("won: %d\n", wons);
    printf("Chance of winning: %.2f\n", avg_win);
    printf("Game length average: %.2f\n", avg_len);

    // clean up code but mostly there

    return 0;
}