#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "functions.h"

// Задание 1
void task1(void){
    char *str = NULL;
    size_t size = 0;

    printf("Введите строку: ");
    getline(&str, &size, stdin);

    char *result = NULL;

    printf("Исходная строка: \"%s\"\n", str);
    
    remove_extra_spaces(str, &result);
    printf("Обработанная строка: \"%s\"\n", result);

    free(result);
    free(str);
}

// Задание 2
void task2(void){
    // Ввод строк
    char *S = NULL;
    char *S0 = NULL;
    size_t size_S = 0;
    size_t size_S0 = 0;

    printf("Введите строку S: ");
    //Передаем указатель на буфер, указатель на переменную которая хранит размер массива из потока ввода
    getline(&S, &size_S, stdin);

    printf("Введите строку S0: ");
    getline(&S0, &size_S0, stdin);

    // Удаление символа новой строки строк
    if (S[string_length(S) - 1] == '\n') {
        S[string_length(S) - 1] = '\0';
    }
    if (S0[string_length(S0) - 1] == '\n') {
        S0[string_length(S0) - 1] = '\0';
    }

    char *result = NULL;
    int a, b;
    printf("Введите значение a: ");
    char t;
    while (1) {
        if ((scanf("%d%c", &a, &t)==2) && t=='\n'){
            break;
        }
        else{
            printf("Некорректный ввод. Попробуйте еще раз: ");
            while (getchar() != '\n');
        }
    }
    printf("Введите значение b: ");
    char v;
    while (1) {
        if ((scanf("%d%c", &b, &v)==2) && v=='\n'){
            break;
        }
        else{
            printf("Некорректный ввод. Попробуйте еще раз: ");
            while (getchar() != '\n');
        }
    }


    insert_chars(S, S0, &result, a, b);

    printf("Исходная строка S: \"%s\"\n", S);
    printf("Исходная строка S0: \"%s\"\n", S0);
    printf("Обработанная строка: \"%s\"\n", result);

    free(result);
    free(S);
    free(S0);
}


int main(void){
    printf("Выберите задание: ");
    int task = 0;
    task = choice_task(task);
    
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
