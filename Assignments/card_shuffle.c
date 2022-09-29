#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct card
{
    char *face; 
    char *suit;
    int num;
} Card;


static int FACES = 13, SUITS = 4; 


void fillDeck(Card deck[], char *faces[], char *suits[]); 
void deal(Card deck[]);
void shuffle(Card deck[]);

int main(int argc, char **argv)
{
    printf("Hello World\n");

    Card deck[FACES * SUITS]; 
    char *suits[] = {"Diamonds", "Clubs", "Hearts", "Spades"};
    char *faces[] = {"Deuce", "Crab", "Sharptop", "Nickel", "Sax", "Fishhook", "Snowman", "Niner", "Dime", "Boy", "Stenographer", "Cowboy", "Seed"};

    fillDeck(deck, faces, suits);
    deal(deck);
    shuffle(deck);
    printf("----------------------------\n");
    deal(deck);
    printf("Done\n");
    return 0; 
}

void fillDeck(Card deck[], char *faces[], char *suits[])
{
    for(int i = 0; i < SUITS*FACES; ++i)
    {
        Card add = {faces[i%FACES], suits[i/ FACES], i};
        deck[i] = add;
    }
}

void shuffle(Card deck[])
{
    srand(42);
    for (int i = 51; i > 1; --i)
    {
        int j = rand() % (i+1);
        Card tmp = deck[i];
        deck[i] = deck[j];
        deck[j] = tmp;
    }
    printf("%s of %s\n", deck[0].face, deck[0].suit);
}

void deal(Card deck[])
{
    for(int i = 0; i < SUITS*FACES; ++i)
    {
        printf("%s of %s\n", deck[i].face, deck[i].suit);
    }
}