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
    while (bulls < 4)
    {
        int g = get_g();
        bulls_cows(numk, g);  
    }
    
    int g = get_g();
    bulls_cows(numk, g);
    
    printf("Продолжить игру ? (Y/N): ");
	    scanf("%s", &key);
            switch (key) {
                case 'Y': case 'y':
                    clearScreen(); 
		    break;
                case 'N': case 'n':
                    return -1;
		    break;
                default:
                    printf("Ошибка");
		    return 0;
            }
        
}