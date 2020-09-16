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
        number = rand() % 10; //генерируем случайную цифру от 0 до 9
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

    if (num % 1000 == 0) {
        guess[0] = 0;
    }

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

void bulls_cows(int* numk, int* guess)
{
    int bulls, cows = 0;
    for (int i = 0; i < 4; i++) { //тест на быка
        if (numk[i] == guess[i]) {
            bulls++;
        } else
            for (int j = 0; j < 4;j++) { //подбор под соответствие (нахождение коров)
                for (int p = 0; p < 4; p++) {
                    if (numk[j] == guess[p]) {
                        cows++;
                    }
                }
            }
    }
    printf("%d быка, %d коров  \n" , bulls ,cows);
}
