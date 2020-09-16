#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int numk[4];
    int i, j = 0, number;

    while (j < 4) {
        number = rand() % 10; //генерируем случайную цифру от 0 до 9
        for (i = 0; i <= j; i++)
            if (numk[i] == number) //если цифра где-то повторилась - выход
                break;
        if (i == j + 1) //если цифра не повторилась - записываем ее в массив
        {
            numk[i - 1] = number;
            ++j; //заполнили еще одну ячейку
        }
    }
    for (int i = 0; i < 4; i++) { //вывод массива для проверки
        printf("%d", numk[i]);
    }
}