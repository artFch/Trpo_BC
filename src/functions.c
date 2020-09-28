#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate(int* numk)
{
    int number;
    int i, j = 0;
    srand(time(NULL));
    while (j < 4) {
        number = rand() % 9 + 1; //генерируем случайную цифру от 0 до 9
        for (i = 0; i <= j; i++) {
            if (numk[i] == number) { //если цифра где-то повторилась - выход
                break;
            }
        }
        if (i == j + 1) //если цифра не повторилась - записываем ее в массив
        {
            numk[i - 1] = number;
            j++; //заполнили еще одну ячейку
        }
    }
}

int convertNumber(int num, int* guess)
{
    // Проверка на количество символов
    if (num < 1000 || num > 9999)
        return 0;

    for (int i = 3; i >= 0; i--) { // Преобразование числа в массив цифр
        guess[i] = num % 10;
        num /= 10;
    }
    // Проверка на повторяющиеся цифры
    for (int i = 0; i < 4; i++)
        for (int j = i + 1; j < 4; j++)
            if (guess[i] == guess[j])
                return 0;
    return 1;
}

int bulls_cows(int* numk, int* guess)
{
    int bulls = 0;
    for (int i = 0; i < 4; i++) { //тест на быка
        if (numk[i] == guess[i]) {
            bulls++;
        }
    }
    if (bulls == 0) {
        printf("%d быков ,", bulls);
    } else if (bulls == 1) {
        printf("%d бык ,", bulls);
    } else
        printf("%d быка ,", bulls);
    return bulls;
}

int cows(int* numk, int* guess, int bulls)
{
    int cows = 0;
    for (int j = 0; j < 4; j++) { //подбор под соответствие (нахождение коров)
        for (int p = 0; p < 4; p++) {
            if (numk[j] == guess[p]) {
                cows++;
            }
        }
    }
    cows = cows - bulls;
    if (cows == 0) {
        printf(" %d коров  \n",cows);
    } else if (cows == 1) {
        printf(" %d корова  \n",cows);
    } else
        printf(" %d коровы  \n",cows);
    
     return cows;
}
