/*
Задание:
 1. Создать очередь для символов. Максимальный размер очереди вводится с экрана. Создать функции для ввода и вывода элементов очереди. Вводить символы с экрана в очередь. В случае совпадения вводимого символа с последним элементом очереди выводить первый элемент очереди.
 2. Создать дек для символов. Максимальный размер дека вводится с экрана. Создать функции для ввода и вывода элементов дека. Добавлять символы в дек поочередно справа и слева. В случае совпадения добавляемого символа с элементом на другом конце дека выводить его на экран.
 3. Используя очередь, проверьте, какие строки являются симметричными. Решение в программе оформляйте через подпрограммы.
 
Студент: Свирид Роман Сергеевич
Дата: 15.04.2025
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "functions.h"


int main() {
    int choice, size;
    char ch;
    char inputStr[100];

    printf("Выберите задание (1-3): ");
    choice = correct_choice(choice);

    switch (choice) {
        case 1: {
            // Задание 1: Очередь символов
            printf("Введите максимальный размер очереди: ");
            size = correct_choice(size);
            while (getchar() != '\n'); // Очистка буфера

            CharQueue queue;
            initQueue(&queue, size);

            while (true) {
                printf("Введите символ (или '-' для выхода): ");
                scanf("%c", &ch);
                while (getchar() != '\n'); // Очистка буфера

                if (ch == '-') break;

                if (!isQueueFull(&queue)) {
                    // Проверка на совпадение с последним элементом
                    if (!isQueueEmpty(&queue) && ch == peekRear(&queue)) {
                        printf("Первый элемент очереди: %c\n", peekFront(&queue));
                    }
                    enqueue(&queue, ch);
                    displayQueue(&queue);
                } else {
                    printf("Очередь переполнена!\n");
                }
            }
            break;
        }
        case 2: {
            // Задание 2: Дек символов
            printf("Введите максимальный размер дека: ");
            size = correct_choice(size);
            while (getchar() != '\n'); // Очистка буфера

            CharDeque deque;
            initDeque(&deque, size);
            bool insertAtFront = true; // Флаг для чередования вставки

            while (true) {
                printf("Введите символ (или '-' для выхода): ");
                scanf("%c", &ch);
                while (getchar() != '\n'); // Очистка буфера

                if (ch == '-') break;

                if (!isDequeFull(&deque)) {
                    if (insertAtFront) {
                        // Проверка на совпадение с противоположным концом
                        if (!isDequeEmpty(&deque) && ch == getRear(&deque)) {
                            printf("Элемент на другом конце: %c\n", getRear(&deque));
                        }
                        insertFront(&deque, ch);
                    } else {
                        // Проверка на совпадение с противоположным концом
                        if (!isDequeEmpty(&deque) && ch == getFront(&deque)) {
                            printf("Элемент на другом конце: %c\n", getFront(&deque));
                        }
                        insertRear(&deque, ch);
                    }
                    insertAtFront = !insertAtFront; // Переключение флага
                    displayDeque(&deque);
                } else {
                    printf("Дек переполнен!\n");
                }
            }
            break;
        }
        case 3: {
            // Задание 3: Проверка симметричности строк
            printf("Введите строку для проверки на симметричность: ");
            fgets(inputStr, sizeof(inputStr), stdin);
            inputStr[strcspn(inputStr, "\n")] = '\0'; // Удаление символа новой строки

            if (isSymmetricString(inputStr)) {
                printf("Строка симметрична.\n");
            } else {
                printf("Строка не симметрична.\n");
            }
            break;
        }
        default:
            printf("Неверный выбор.\n");
    }

    return 0;
}

