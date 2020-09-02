#include "functions.c"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    printf("\e[1;1H\e[2J");
    int numk[4];
    generate(numk);
    printf(" Input 4 digits: ");
    int g = get_g();
    bulls_cows(numk, g);
