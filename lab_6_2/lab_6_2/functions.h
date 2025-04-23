typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

int correct_choice(int task) {
    while (1) {
        char b;
        if (scanf("%d%c", &task, &b) == 2 && b == '\n') {
            break;
        } else {
            printf("Некорректный ввод. Повторите еще раз: ");
            while (getchar() != '\n');
        }
    }
    return task;
}

char correct_choice_char(char task) {
    while (1) {
        char b;
        if (scanf("%c", &task) == 1 && (task == 'l' || task == 'r')) {
            break;
        } else {
            printf("Некорректный ввод. Повторите еще раз: ");
            while (getchar() != '\n');
        }
    }
    return task;
}


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

TreeNode* insertNode(TreeNode* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    printf("Куда вставить %d? (l - лево, r - право от %d): ", value, root->data);
    char choice;
    choice = correct_choice_char(choice);

    if (choice == 'l') {
        root->left = insertNode(root->left, value);
    } else if (choice == 'r') {
        root->right = insertNode(root->right, value);
    } else {
        printf("Некорректный выбор. Используйте 'l' или 'r'.\n");
    }

    return root;
}

TreeNode* findMinNode(TreeNode* node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

TreeNode* deleteNode(TreeNode* root, int value) {
    if (root == NULL) {
        return root;
    }

    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {
        if (root->left == NULL) {
            TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            TreeNode* temp = root->left;
            free(root);
            return temp;
        }

        TreeNode* temp = findMinNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

bool isStrictBinary(TreeNode* root) {
    if (root == NULL) {
        return true;
    }

    if (root->left == NULL && root->right == NULL) {
        return true;
    }

    if (root->left != NULL && root->right != NULL) {
        return isStrictBinary(root->left) && isStrictBinary(root->right);
    }

    return false;
}

TreeNode* makeStrictBinary(TreeNode* root) {
    if (root == NULL) {
        return NULL;
    }

    root->left = makeStrictBinary(root->left);
    root->right = makeStrictBinary(root->right);

    if ((root->left == NULL && root->right != NULL) ||
        (root->left != NULL && root->right == NULL)) {
        
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

void freeTree(TreeNode* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}


void add_tree_node(TreeNode** root, int value){
    printf("Введите значение для добавления: ");
    value = correct_choice(value);
    *root = insertNode(*root, value);
}

void delete_tree_node(TreeNode** root, int value){
    printf("Введите значение для удаления: ");
    value = correct_choice(value);
    *root = insertNode(*root, value);
}

void show_tree(TreeNode** root, int value){
    printf("\nТекущее дерево:\n");
    printTree(*root, 0);
    printf("\n");
}

void сonvert_tree_to_strict_binary(TreeNode** root, int value){
    printf("\nПреобразование дерева в строго бинарное...\n");
    *root = makeStrictBinary(*root);
    printf("Дерево после преобразования:\n");
    printTree(*root, 0);
    printf("\n");
    if (isStrictBinary(*root)) {
        printf("Дерево теперь строго бинарное.\n");
    } else {
        printf("Не удалось сделать дерево строго бинарным.\n");
    }
}
