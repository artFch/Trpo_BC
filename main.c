#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int bulls;
    srand(time(NULL));
    printf("\e[1;1H\e[2J");
    int numk[4];
    generate(numk);
    printf(" Input 4 digits: ");
    while (bulls < 4) {
        bulls_cows(numk, get_g());
    }

    int key;
    printf("Продолжить игру ? (Y/N): ");
    scanf("%s", &key);
    switch (key) {
    case 'Y':
    case 'y':
        printf("\e[1;1H\e[2J");
        break;
    case 'N':
    case 'n':
        return -1;
        break;
    default:
        printf("Ошибка");
        return 0;
    }
}