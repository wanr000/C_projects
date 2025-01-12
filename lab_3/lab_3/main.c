#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "functions.h"

int main(void){
    int n=2;
    while (1) {
        if(n==2){
            start();
            printf("\nЗакрыть программу?\n");
            printf("1-Да\n2-Нет\n");
            n = choice_task(n);
        }

        if (n == 1){
            return 0;
        }
        if (n == 2){
            continue;
        }
        else{
            printf("Данного варианта ответа не существует. Повторите ввод: ");
            n = choice_task(n);
        }
    }
}


