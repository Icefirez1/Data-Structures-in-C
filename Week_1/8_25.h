#include <stdio.h> 
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

unsigned int roll_dice(unsigned int size)
{
    return rand() % size;
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
int main_8_25(void)
{
    // printf("%u\n", UINT_MAX);
    // printf("%lf\n", pow(3,2));
    // printf("%zu\n", sizeof(int));
    // printf("%d\n", sizeof(size_t)); // size_t == unsigned long long
    // printf("%zu\n", sizeof(long long));

    // // Use unsigned char for characters
    // printf("%d\n", CHAR_MIN);

    // bool test  0; 
    // printf("%d\n", test);
    
    unsigned int grades[] = {0,0,0,0,0};
    char grade;
    while((grade = getchar()) != EOF) // control z to murder
    {
        // if(grade == 'A'){++grades[0];}
        // else if(grade == 'B'){++grades[1];}
        // else if(grade == 'C'){++grades[2];}
        // else if(grade == 'D'){++grades[3];}  
        // else if(grade == 'F'){++grades[4];}      

        // switch(grade)
        // {
        //     case 'A': 
        //         ++grades[0];
        //         break;
        //     case 'B': 
        //         ++grades[1];
        //         break;
        //     case 'C': 
        //         ++grades[2];
        //         break;
        //     case 'D': 
        //         ++grades[3];
        //         break;
        //     case 'F': 
        //         ++grades[4];
        //         break;
        //     default: 
        //         puts("PUT A CAPITAL LETTER DUMBASS");
        //     break;
        // }

        if(grade >= 'A' && grade <= 'E')
        {
            ++grades[grade-'A'];
        }
    }

    for(size_t i = 0; i <5; ++i)
    {
        printf("%i ", grades[i]);
    }
    printf("done\n");

    // printf("%zu\n", sizeof(grades));

    //printf("%c\n", 'a'^32);

    unsigned int yuh; 
    yuh = 123; 
    printf("%d\n", yuh);
    srand(42);
    printf("%u\n" ,roll_die(10));
    printf("%u\n" ,roll_die(10));
    
    // int runtimes = 10; 
    // unsigned int sides;
    // sides = 6
    // unsigned int a[sides] = {};
    // for(int k = 0; k < runtimes; ++k)
    // {
    //     ++a[roll_dice(sides)];
    // }


    
    return 0;
}

