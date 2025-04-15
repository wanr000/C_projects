#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "functions.h"

int main() {
    TreeNode* root = NULL;
    int choice, value;

    printf("Создание бинарного дерева:\n");
    do {
        printf("\nМеню:\n");
        printf("1. Добавить узел\n");
        printf("2. Удалить узел\n");
        printf("3. Показать дерево\n");
        printf("4. Преобразовать в строго бинарное\n");
        printf("5. Выход\n");
        printf("Выберите действие: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Введите значение для добавления: ");
                scanf("%d", &value);
                root = insertNode(root, value);
                break;
            case 2:
                printf("Введите значение для удаления: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                break;
            case 3:
                printf("\nТекущее дерево:\n");
                printTree(root, 0);
                printf("\n");
                break;
            case 4:
                printf("\nПреобразование дерева в строго бинарное...\n");
                root = makeStrictBinary(root);
                printf("Дерево после преобразования:\n");
                printTree(root, 0);
                printf("\n");
                if (isStrictBinary(root)) {
                    printf("Дерево теперь строго бинарное.\n");
                } else {
                    printf("Не удалось сделать дерево строго бинарным.\n");
                }
                break;
            case 5:
                printf("Выход...\n");
                break;
            default:
                printf("Неверный выбор. Попробуйте снова.\n");
        }
    } while (choice != 5);

    freeTree(root);
    return 0;
}
