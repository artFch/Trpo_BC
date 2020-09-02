#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate(int numk[])
{
    int number;
    int i, j = 0;
    srand(time(NULL));
    while (j < 4) {
        number = rand() % 10; //генерируем случайную цифру от 0 до 9
        for (int i = 0; i <= j; i++) {
            if (numk[i] == number) { //если цифра где-то повторилась - выход
                break;
            }
            if (i == j + 1) //если цифра не повторилась - записываем ее в массив
            {
                numk[i - 1] = number;
                ++j; //заполнили еще одну ячейку
            }
        }
    }
}

int convertNumber(int number, int numk[])
{
    // Проверка на количество символов
    if (number < 1000 || number > 9999)
        return 0;

    if (number % 1000 == 0) {
        numk[0] = 0;
    }

    for (int i = 3; i >= 0; i--) { // Преобразование числа в массив цифр
        numk[i] = number % 10;
        number /= 10;
    }
    // Проверка на повторяющиеся цифры
    for (int i = 0; i < 4; i++)
        for (int j = i + 1; j < 4; j++)
            if (numk[i] == numk[j])
                return 0;
    return 1;
}

void bulls_cows(int numk[], int guess[])
{
    int bulls, cows = 0;
    for (int i = 0; i < 4; i++) { //тест на быка
        if (numk[i] == guess[i]) {
            bulls++;
        } else
            for (int j = 0; j < 4;
                 j++) { //подбор под соответствие (нахождение коров)
                for (i = 0; i < 4; i++) {
                    if (numk[j] == guess[i]) {
                        cows++;
                    }
                }
            }
    }
    printf("%d,%d", bulls, cows);
}
