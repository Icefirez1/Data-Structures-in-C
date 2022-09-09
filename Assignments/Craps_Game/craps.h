#include <stdio.h> 
#include <stdbool.h>
#include <stdlib.h>


enum Status {CONTINUE, WON, LOST};

enum Status craps(int *ptr)
{
    //initilaize stuff
    enum Status game_time = CONTINUE;
    unsigned int start_sum = roll_die(6) + roll_die(6);
    *ptr = 1;

    switch(start_sum)
    {
        case 7:
        case 11:
        {
            // printf("You rolled a %d\n", start_sum);
            return WON; 
        }
        case 2:
        case 3: 
        case 12: 
        {
            // printf("You rolled a %d\n", start_sum);
            return LOST;   
        }
    }

    unsigned int check_sum = roll_die(6) + roll_die(6);
    for (enum Status check = game_time; check == game_time; ++*ptr)  
    {
        if(check_sum ==7)
            game_time = LOST;
        else if (check_sum == start_sum)
            game_time = WON;
        
        // printf("You rolled a %d\n", check_sum);
        check_sum = roll_die(6) + roll_die(6);
    }

    return game_time;
}