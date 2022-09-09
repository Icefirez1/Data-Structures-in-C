#include  <stdio.h>
#include <string.h>

int main_9_7(void)
{
    char chr_arr[6] ={'h','e','l','l','o'};
    char string1[] = "hello";
    string1[0] = 'k';
    chr_arr[0] = 'k';
    
    puts(string1);
    puts(chr_arr);
    printf( "length of string1 %zu\n", sizeof(string1));
    printf( "length of chr_arr %zu\n", sizeof(chr_arr));
    printf("%d\n", string1[5]);
    printf( "%lu", strlen(string1) );
    //slay slay slay slay slay slay slay
    return 0;
}