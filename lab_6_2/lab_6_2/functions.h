// Структура узла бинарного дерева
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Функция для создания нового узла
TreeNode* createNode(int value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (newNode == NULL) {
        printf("Ошибка выделения памяти!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Функция для вставки узла в дерево
TreeNode* insertNode(TreeNode* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    printf("Куда вставить %d? (l - лево, r - право от %d): ", value, root->data);
    char choice;
    scanf(" %c", &choice);

    if (choice == 'l') {
        root->left = insertNode(root->left, value);
    } else if (choice == 'r') {
        root->right = insertNode(root->right, value);
    } else {
        printf("Некорректный выбор. Используйте 'l' или 'r'.\n");
    }

    return root;
}

// Функция для поиска узла с минимальным значением
TreeNode* findMinNode(TreeNode* node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

// Функция для удаления узла из дерева
TreeNode* deleteNode(TreeNode* root, int value) {
    if (root == NULL) {
        return root;
    }

    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {
        // Узел с одним или без детей
        if (root->left == NULL) {
            TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            TreeNode* temp = root->left;
            free(root);
            return temp;
        }

        // Узел с двумя детьми
        TreeNode* temp = findMinNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Функция для проверки, является ли дерево строго бинарным
bool isStrictBinary(TreeNode* root) {
    if (root == NULL) {
        return true;
    }

    // Если у узла нет детей - строго бинарное
    if (root->left == NULL && root->right == NULL) {
        return true;
    }

    // Если у узла оба ребенка - проверяем их рекурсивно
    if (root->left != NULL && root->right != NULL) {
        return isStrictBinary(root->left) && isStrictBinary(root->right);
    }

    // Если только один ребенок - не строго бинарное
    return false;
}

// Функция для преобразования дерева в строго бинарное (удаление минимального количества узлов)
TreeNode* makeStrictBinary(TreeNode* root) {
    if (root == NULL) {
        return NULL;
    }

    // Рекурсивно обрабатываем детей
    root->left = makeStrictBinary(root->left);
    root->right = makeStrictBinary(root->right);

    // Если у узла только один ребенок
    if ((root->left == NULL && root->right != NULL) ||
        (root->left != NULL && root->right == NULL)) {
        
        // Удаляем текущий узел и возвращаем его единственного ребенка
        TreeNode* temp;
        if (root->left != NULL) {
            temp = root->left;
        } else {
            temp = root->right;
        }
        free(root);
        return makeStrictBinary(temp);
    }

    return root;
}

// Функция для визуализации дерева (вертикальный вывод)
void printTree(TreeNode* root, int space) {
    const int COUNT = 4;
    if (root == NULL) {
        return;
    }

    space += COUNT;

    printTree(root->right, space);

    printf("\n");
    for (int i = COUNT; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", root->data);

    printTree(root->left, space);
}

// Функция для освобождения памяти дерева
void freeTree(TreeNode* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}
