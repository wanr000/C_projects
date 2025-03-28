/*
Задание:
 1. Создать стек для целых чисел. Максимальный размер стека вводится с экрана. Найти сумму после максимального элемента стека.
 2. Создать два стека для целых чисел. Первый стек – организовать ввод по убыванию, второй cтек – организовать ввод по возрастанию. Без сортировок и переворачивания исходных стеков сформировать третий стек упорядоченный по убыванию
 3. В текстовом файле записаны строки – арифметические выражения. Числа – вещественные, знаки действий - -, +, *, / и скобки (). Используя работу со стеками найти значение каждого выражения и записать в файл результатов. Если в исходном файле в строке есть ошибка – найти ее предполагаемую позицию (позицию первой ошибки) и в выходной файл записать сообщение «Ошибка в позиции N»
 
Студент: Свирид Роман Сергеевич
Дата: 28.03.2025
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "functions.h"

#define MAX_SIZE 100
#define MAX_EXPR_LEN 256


void task1() {
    printf("\n=== Задание 1 ===\n");
    int capacity;
    printf("Введите размер стека: ");
    scanf("%d", &capacity);

    IntStack s;
    initIntStack(&s, capacity);

    printf("Введите элементы стека (целые числа):\n");
    for (int i = 0; i < capacity; i++) {
        int num;
        scanf("%d", &num);
        pushInt(&s, num);
    }

    int sum = findSumAfterMax(&s);
    printf("Сумма элементов после максимального: %d\n", sum);

    freeIntStack(&s);
}


void task2() {
    printf("\n=== Задание 2 ===\n");
    int capacity;
    printf("Введите размер стеков: ");
    scanf("%d", &capacity);

    IntStack s1, s2;
    initIntStack(&s1, capacity);
    initIntStack(&s2, capacity);

    fillStack(&s1, true);  // Убывающий
    fillStack(&s2, false); // Возрастающий

    IntStack merged = mergeStacks(&s1, &s2);

    printf("Объединенный стек (убывающий):\n");
    while (!isIntStackEmpty(&merged)) {
        printf("%d ", popInt(&merged));
    }
    printf("\n");

    freeIntStack(&s1);
    freeIntStack(&s2);
    freeIntStack(&merged);
}


void task3() {
    printf("\n=== Задание 3 ===\n");
    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");

    if (!input || !output) {
        printf("Ошибка открытия файлов!\n");
        return;
    }

    char expr[MAX_EXPR_LEN];
    while (fgets(expr, MAX_EXPR_LEN, input)) {
        expr[strcspn(expr, "\n")] = '\0';

        int error_pos;
        if (!validateExpression(expr, &error_pos)) {
            fprintf(output, "Ошибка в позиции %d\n", error_pos);
        } else {
            double result = evaluateExpression(expr);
            fprintf(output, "%.2f\n", result);
        }
    }

    fclose(input);
    fclose(output);
    printf("Результаты записаны в output.txt\n");
}


int main() {
    int choice;
    do {
        printf("\n=================== Меню ===================\n");
        printf("1. Задание 1 (Сумма после максимума в стеке)\n");
        printf("2. Задание 2 (Объединение двух стеков)\n");
        printf("3. Задание 3 (Вычисление выражений из файла)\n");
        printf("4. Выход\n");
        printf("Выберите задание: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: task1(); break;
            case 2: task2(); break;
            case 3: task3(); break;
            case 4: printf("Выход...\n"); break;
            default: printf("Неверный выбор!\n");
        }
    } while (choice != 4);

    return 0;
}
