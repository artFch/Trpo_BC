#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(time(NULL));
	int numk[4];
	int guess[4];
	int i, j, cows, bulls = 0, number;

	while (j < 4)
	{
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
	for (int i = 0; i < 4; i++)
	{ //вывод массива для проверки
		printf("%d", numk[i]);
	}

	while (bulls < 4)
	{
		int c = getchar(); //ввод с клавиатуры
		if ((c >= '0') && (c <= '9'))
		{
			guess[i++] = c;
		}
	}
    for(int i=0;i<4;i++){
        if(numk[i] == guess[i]){
            bulls++;
        }else for(int j=0;j<4;j++){
                for(i=0;i<4;i++){
                    if(numk[j] == guess[i]){
                        cows++;
                    }
                }
        }
    }
}   