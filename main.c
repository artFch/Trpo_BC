#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num = 0;
    int b = 0;
    int try=0;
    srand(time(NULL));
    printf("\e[1;1H\e[2J");
    int numk[4];
    int guess[4];
    generate(numk);
    /*for (int i = 0; i < 4; i++)
        printf("%d", numk[i]);*/
    while (b !=4)
    {
        printf(" Введите 4-х значное число ");
        scanf("%d", &num);
        convertNumber(num, guess);
        b = bulls_cows(numk, guess);
        cows(numk, guess, b);
        try++;
    }
    printf("ПОЗДРАВЛЯЮ С ПОБЕДОЙ!");
    if(try<5)
    printf("Вы победили за %d попытки",try);
    else
    {
       printf("Вы победили за %d попыток",try); 
    }
    

    char key;
    printf("Начать игру заново ? (Y/N): ");
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