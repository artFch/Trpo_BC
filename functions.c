#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void generate (int numk[])
{
    int number;
    int i,j = 0;
    srand(time(NULL));
    while (j < 4)
	{
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
}


