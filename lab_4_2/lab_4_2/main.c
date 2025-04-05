/*
Задание:
 1. Создать стек для целых чисел. Максимальный размер стека вводится с экрана. Найти самый часто повторяющийся элемент стека.
 2. Создать два стека для целых чисел. Первый стек – организовать ввод по возрастанию, второй стек – организовать ввод по возрастанию. Без сортировок и переворачивания исходных стеков сформировать третий стек упорядоченный по возрастанию.
 3. В текстовом файле записаны строки – арифметические выражения. Числа – вещественные, знаки действий - -, +, *, / и скобки (). Используя работу со стеками найти значение каждого выражения и записать в файл результатов. Если в исходном файле в строке есть ошибка – найти ее предполагаемую позицию (позицию первой ошибки) и в выходной файл записать сообщение «Ошибка в позиции N»
 
Студент: Свирид Роман Сергеевич
Дата: 28.03.2025
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include "functions.h"

#define MAX_SIZE 100
#define MAX_EXPR_LEN 256


void frequent_stack_element() {
    printf("\nЗадание 1:\n");
    
    int capacity;
    printf("Введите размер стека: ");
    capacity = correct_choice(capacity);

    IntStack stack;
    initIntStack(&stack, capacity);

    printf("Введите элементы стека (целые числа):\n");
    for (int i = 0; i < capacity; i++) {
        int num;
        printf("Элемент %d: ", i+1);
        num = correct_choice(num);
        pushInt(&stack, num);
    }

    int most_frequent = findMostFrequentElement(&stack);
    
    if (most_frequent != INT_MIN) {
        printf("Самый часто повторяющийся элемент: %d\n", most_frequent);
    } else {
        printf("Стек пуст!\n");
    }

    freeIntStack(&stack);
}


void Merging_two_stacks() {
    printf("\nЗадание 2:\n");

    int capacity;
    printf("Введите размер стеков: ");
    capacity = correct_choice(0);

    if (capacity <= 0) {
        printf("Ошибка: размер стека должен быть положительным.\n");
        return;
    }

    IntStack stack1, stack2, result;
    initIntStack(&stack1, capacity);
    initIntStack(&stack2, capacity);
    initIntStack(&result, capacity * 2); // result может быть вдвое больше

    
    printf("Заполните первый стек из %d элементов, строго по возрастанию:\n\n", capacity);
    int prev = INT_MIN;
    for (int i = 0; i < capacity; ) {
        printf("Элемент %d: ", i+1);
        int num = correct_choice(0);
        if (i > 0 && num <= prev) {
            printf("Ошибка: элементы должны быть в строго возрастающем порядке (предыдущий был %d)!\n", prev);
            continue;
        }
        pushInt(&stack1, num);
        prev = num;
        i++;
    }

    printf("\nЗаполните второй стек (%d элементов, строго по возрастанию):\n", capacity);
    prev = INT_MIN;
    for (int i = 0; i < capacity; ) {
         int num = correct_choice(0);
         if (i > 0 && num <= prev) {
             printf("Ошибка: элементы должны быть в строго возрастающем порядке (предыдущий был %d)!\n", prev);
             continue;
         }
         pushInt(&stack2, num);
         prev = num;
         i++;
    }

    mergeAscendingStacks(&stack1, &stack2, &result);
    printf("\nРезультат объединения (по возрастанию):\n");
    while (!isIntStackEmpty(&result)) {
        printf("%d ", popInt(&result));
    }
    printf("\n");

    freeIntStack(&stack1);
    freeIntStack(&stack2);
    freeIntStack(&result);
}


void Evaluating_expressions_from_file() {
    printf("\nЗадание 3\n");
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
        printf("\n========================= Меню ========================\n");
        printf("|1| Задание 1 (Самый часто повторяющийся элемент стека)\n");
        printf("|2| Задание 2 (Объединение двух стеков)\n");
        printf("|3| Задание 3 (Вычисление выражений из файла)\n");
        printf("|4| Выход\n");
        printf("\nВыберите задание: ");
        choice = correct_choice(choice);

        switch (choice) {
            case 1: frequent_stack_element(); break;
            case 2: Merging_two_stacks(); break;
            case 3: Evaluating_expressions_from_file(); break;
            case 4: printf("Выход...\n"); break;
            default: printf("Неверный выбор!\n");
        }
        printf("\n");
    } while (choice != 4);
    return 0;
}
