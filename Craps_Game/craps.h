#include <stdio.h> 
#include <stdbool.h>
#include <stdlib.h>


enum Status {CONTINUE, WON, LOST};

enum Status craps(void)
{
    enum Status game_time = CONTINUE;
    //initialize sum
    unsigned int start_sum = roll_die(6) + roll_die(6);

    //starting things
    if(start_sum == 7 || start_sum == 11)
    {   printf("You rolled a %d\n", start_sum);
        return WON;}
    else if(start_sum == 2 || start_sum == 3 || start_sum == 12)
    {   printf("You rolled a %d\n", start_sum);
        return LOST;}

    //part doesnt work
    unsigned int check_sum = roll_die(6) + roll_die(6);
    while (game_time == CONTINUE)
    {
        printf("yuh");
        if(check_sum ==7)
        {game_time = LOST;}
        else if (check_sum == start_sum)
        {game_time = WON;}
        printf("You rolled a %d\n", check_sum);
        check_sum = roll_die(6) + roll_die(6);
        }

    return game_time;
}