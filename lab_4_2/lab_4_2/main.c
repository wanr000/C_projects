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


// ======================== Задание 1 ========================
int findSumAfterMax(IntStack *s) {
    if (isIntStackEmpty(s)) {
        printf("Стек пуст!\n");
        return 0;
    }

    int max_val = s->data[0];
    int max_pos = 0;

    for (int i = 1; i <= s->top; i++) {
        if (s->data[i] > max_val) {
            max_val = s->data[i];
            max_pos = i;
        }
    }

    if (max_pos == s->top) return 0;

    int sum = 0;
    for (int i = max_pos + 1; i <= s->top; i++) {
        sum += s->data[i];
    }

    return sum;
}

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

// ======================== Задание 2 ========================
void fillStack(IntStack *s, bool isDescending) {
    printf("Введите элементы стека (%s):\n", isDescending ? "убывающий" : "возрастающий");
    int prev;
    scanf("%d", &prev);
    pushInt(s, prev);

    for (int i = 1; i < s->capacity; i++) {
        int num;
        scanf("%d", &num);
        if ((isDescending && num >= prev) || (!isDescending && num <= prev)) {
            printf("Некорректный порядок! Повторите ввод.\n");
            i--;
            continue;
        }
        pushInt(s, num);
        prev = num;
    }
}

IntStack mergeStacks(IntStack *s1, IntStack *s2) {
    IntStack result;
    initIntStack(&result, s1->capacity + s2->capacity);

    while (!isIntStackEmpty(s1) && !isIntStackEmpty(s2)) {
        if (peekInt(s1) >= peekInt(s2)) {
            pushInt(&result, popInt(s1));
        } else {
            pushInt(&result, popInt(s2));
        }
    }

    while (!isIntStackEmpty(s1)) pushInt(&result, popInt(s1));
    while (!isIntStackEmpty(s2)) pushInt(&result, popInt(s2));

    return result;
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

// ======================== Задание 3 ========================
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

double applyOp(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        default: return 0;
    }
}

bool validateExpression(const char *expr, int *error_pos) {
    CharStack s;
    initCharStack(&s, MAX_EXPR_LEN);
    int len = strlen(expr);

    for (int i = 0; i < len; i++) {
        char c = expr[i];
        if (isspace(c)) continue;

        if (c == '(') {
            pushChar(&s, c);
        } else if (c == ')') {
            if (isCharStackEmpty(&s) || popChar(&s) != '(') {
                *error_pos = i;
                free(s.data);
                return false;
            }
        } else if (isOperator(c)) {
            if (i == 0 || i == len - 1 || isOperator(expr[i-1]) || expr[i-1] == '(') {
                *error_pos = i;
                free(s.data);
                return false;
            }
        } else if (!isdigit(c) && c != '.') {
            *error_pos = i;
            free(s.data);
            return false;
        }
    }

    if (!isCharStackEmpty(&s)) {
        *error_pos = len - 1;
        free(s.data);
        return false;
    }

    free(s.data);
    return true;
}

double evaluateExpression(const char *expr) {
    DoubleStack values;
    CharStack ops;
    initDoubleStack(&values, MAX_EXPR_LEN);
    initCharStack(&ops, MAX_EXPR_LEN);

    for (int i = 0; expr[i]; i++) {
        if (isspace(expr[i])) continue;

        if (expr[i] == '(') {
            pushChar(&ops, expr[i]);
        } else if (isdigit(expr[i]) || expr[i] == '.') {
            double num = 0;
            int decimal = 0;
            double fraction = 1.0;
            while (expr[i] && (isdigit(expr[i]) || expr[i] == '.')) {
                if (expr[i] == '.') {
                    decimal = 1;
                } else {
                    if (decimal) {
                        fraction *= 0.1;
                        num += (expr[i] - '0') * fraction;
                    } else {
                        num = num * 10 + (expr[i] - '0');
                    }
                }
                i++;
            }
            i--;
            pushDouble(&values, num);
        } else if (expr[i] == ')') {
            while (!isCharStackEmpty(&ops) && peekChar(&ops) != '(') {
                double b = popDouble(&values);
                double a = popDouble(&values);
                char op = popChar(&ops);
                pushDouble(&values, applyOp(a, b, op));
            }
            popChar(&ops);
        } else if (isOperator(expr[i])) {
            while (!isCharStackEmpty(&ops) && precedence(peekChar(&ops)) >= precedence(expr[i])) {
                double b = popDouble(&values);
                double a = popDouble(&values);
                char op = popChar(&ops);
                pushDouble(&values, applyOp(a, b, op));
            }
            pushChar(&ops, expr[i]);
        }
    }

    while (!isCharStackEmpty(&ops)) {
        double b = popDouble(&values);
        double a = popDouble(&values);
        char op = popChar(&ops);
        pushDouble(&values, applyOp(a, b, op));
    }

    double result = popDouble(&values);
    free(values.data);
    free(ops.data);
    return result;
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

// ======================== Главное меню ========================
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
