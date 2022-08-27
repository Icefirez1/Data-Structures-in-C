#include <stdio.h> 
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>


unsigned int roll_die(unsigned int sides)
{
    unsigned int diff = (RAND_MAX +1) % sides;
    unsigned int roll;
    do{
        roll = rand();
    } while (roll  - diff>= RAND_MAX); 

    return roll % sides + 1;

}