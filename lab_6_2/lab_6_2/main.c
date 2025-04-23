/*
Задание:
 1. Удалить из бинарного дерева наименьшее количество вершин таким образом, чтобы полученное дерево было строго бинарным.
 
Студент: Свирид Роман Сергеевич
Дата: 15.04.2025
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "functions.h"


int main() {
    TreeNode* root = NULL;
    int choice, value;

    printf("Создание бинарного дерева:\n");
    do {
        printf("\n========================= Меню ========================\n");
        printf("|1| Добавить узел\n");
        printf("|2| Удалить узел\n");
        printf("|3| Показать дерево\n");
        printf("|4| Преобразовать в строго бинарное\n");
        printf("|5| Выход\n");
        printf("Выберите действие: ");
        choice = correct_choice(choice);

        switch (choice) {
            case 1:
                add_tree_node(&root, value); break;
            case 2:
                delete_tree_node(&root, value); break;
            case 3:
                show_tree(&root, value); break;
            case 4:
                сonvert_tree_to_strict_binary(&root, value); break;
            case 5:
                printf("Выход...\n"); break;
            default:
                printf("Неверный выбор. Попробуйте снова.\n");
        }
    } while (choice != 5);

    freeTree(root);
    return 0;
}
