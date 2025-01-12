#include <stdio.h>
#include <math.h>
#include "functions.h"

int main(void){
    int n;
    start();
    
    printf("\nЗакрыть программу?\n");
    printf("1-Да\n2-Нет\n");
    
    n = choice_task(n);
    
    while (1) {
        if (n == 1){
            return 0;
        }
        if (n == 2){
            start();
            printf("\nЗакрыть программу?\n");
            printf("1-Да\n2-Нет\n");
            n = choice_task(n);
            
        }
        else{
            printf("Неверный номер задания. Попробуйте еще раз: ");
            n = choice_task(n);
        }
    }
}
