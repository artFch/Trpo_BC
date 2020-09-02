#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generate(int numk[])
{
    int numk[4];
    int number;
    int i, j = 0;
    srand(time(NULL));
    while (j < 4) {
        number = rand() % 10; //генерируем случайную цифру от 0 до 9
        for (int i = 0; i <= j; i++)
            if (numk[i] == number) //если цифра где-то повторилась - выход
                break;
        if (i == j + 1) //если цифра не повторилась - записываем ее в массив
        {
            numk[i - 1] = number;
            ++j; //заполнили еще одну ячейку
        }
    }
    return numk;
}

int get_g()
{
    int guess[4];
    int c;
    for (int i = 0; i < 4; i++) {
        scanf("%d", &c);
        if ((c >= 0) && (c <= 9)) {
            guess[i] = c;
        }
    }
    return guess;
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
	printf("%d,%d",bulls ,cows);
}
