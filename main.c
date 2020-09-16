#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "display.h"

int main()
{
    while (1) {
        int num = 0;
        int b = 0;
        int
        try = 0;
        srand(time(NULL));
        clearScreen();
        int numk[4];
        int guess[4];
        generate(numk);
        char ans;
        printf("Показать ответ сразу? (Y/N)\n");
        scanf("%s", &ans);
        switch (ans) {
        case 'Y':
        case 'y':
            printf("Ответ :");
            for (int i = 0; i < 4; i++) {
                printf("%d", numk[i]);
            }
            printf("\n");
            break;
        case 'N':
        case 'n':
            clearScreen();
        } /*for (int i = 0; i < 4; i++)
             printf("%d", numk[i]);*/
        while (b != 4) {
            printf(" Введите 4-х значное число ");
            scanf("%d", &num);
            convertNumber(num, guess);
            b = bulls_cows(numk, guess);
            cows(numk, guess, b);
            try++;
        }
        printf("\n\tПОЗДРАВЛЯЮ С ПОБЕДОЙ!\n");
        if (try < 5)
            printf("\tВы победили за %d попытки\n", try);
        else {
            printf("Вы победили за %d попыток", try);
        }

        char key;
        printf("Начать игру заново ? (Y/N): ");
        scanf("%s", &key);
        switch (key) {
        case 'Y':
        case 'y':
            clearScreen();
            break;
        case 'N':
        case 'n':
            return 0;
        default:
            printf("Ошибка");
            return -1;
        }
    }
}