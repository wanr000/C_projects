#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "functions.h"

// Задание 1
void task1(){
    char b = start_1(b);
    int n = start_2(n);
    int * a = malloc(n * sizeof(int));
    int a_1;

    if(b == 'a'){
        FILE *file = fopen("array.txt", "w");
        srand(time(NULL));
        for(int k=0;k<n; k++){
            a[k]= (-50 + rand()%100);
            fprintf(file, "%d  ", a[k]);
        }
        fclose(file);
    }
    else if(b == 'b'){
        FILE *file = fopen("array.txt", "w");
        int nms;
        for(int k=0;k<n;k++){
            while (1) {
                nms = scanf("%d", &a_1);
                if (nms == 1) {
                    break;
                }
                else {
                    printf("Введен некорректный символ, введите еще раз: ");
                    while (getchar() != '\n');
                }
            }
            a[k] = a_1;
            fprintf(file, "%d  ", a[k]);
            }
            fclose(file);
    }
    else if(b == 'c'){
        FILE *file = fopen("array.txt", "r");
        for(int k=0;k<n; k++){
            fscanf(file, "%d", &a[k]);
        }
        fclose(file);
    }

    printf("Исходный массив: ");
    print_arr(a, n);

    bubble_sort(a, n);

    printf("Измененный массив: ");
    print_arr(a, n);
    free(a);

}

// Задание 2
void task2(){
    char b = start_1(b);
    int n = start_22(n);
    int m = start_23(m);
    
    int ** array = (int**) calloc(n, sizeof(int*));
    for (int i = 0; i < n; i++) {
        array[i] = (int*) calloc(m, sizeof(int));
    }
    

    if(b == 'a'){
        FILE *file = fopen("array.txt", "w");
        srand(time(NULL));
        for(int k=0;k<n; k++){
            for(int j=0;j<m; j++){
                array[k][j] = (-20 + rand()%100);
                fprintf(file, "%d  ", array[k][j]);
            }
            fprintf(file, "\n");
        }
        fclose(file);
    }
    else if(b == 'b'){
        FILE *file = fopen("array.txt", "w");
        int nms;
        for(int k=0;k<n;k++){
            for(int j=0;j<m;j++){
                while (1) {
                    nms = scanf("%d", &array[k][j]);
                    if (nms == 1) {
                        break;
                    }
                    else {
                        printf("Введен некорректный символ, введите еще раз: ");
                        while (getchar() != '\n');
                    }
                }
                fprintf(file, "%d  ", array[k][j]);
            }
            fprintf(file, "\n");
        }
        fclose(file);
    }
    else if(b == 'c'){
        FILE *file = fopen("array.txt", "r");
        for(int k=0;k<n; k++){
            for(int j=0;j<m; j++){
                fscanf(file, "%d", &array[k][j]);
            }
            fprintf(file, "\n");
        }
        fclose(file);
    }
    
    printf("Исходный массив: \n");
    print_arr3(n, m, array);
    
    shell_sort_columns(array, n, m);
    printf("\nИзмененный массив: \n");
    print_arr3(n, m, array);
    
    for(int i = 0; i < n; i++) {
        free(array[i]);
    }
    free(array);
}


int main(){
    printf("Выберите задание: ");
    int task = choice_task(task);
    
    while (1) {
        if (task == 1){
            task1();
            break;;
        }
        if (task == 2){
            task2();
            break;
        }
        else{
            printf("Неверный номер задания. Попробуйте еще раз: ");
            task = choice_task(task);
        }
    }
}

