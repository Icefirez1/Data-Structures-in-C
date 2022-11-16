#include <stdio.h>
#include <string.h> 

//should I mod length? 
size_t hash(char *key)
{
    size_t value = 0;
    for(size_t i = strlen(key) + 1; i > 0; --i)
        {value = value*32 + key[i-1];}
    return value;
}