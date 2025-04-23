typedef struct QueueNode {
    char data;
    struct QueueNode* next;
} QueueNode;

typedef struct {
    QueueNode* front;
    QueueNode* rear;
    int maxSize;
    int currentSize;
} CharQueue;

void initQueue(CharQueue* q, int size) {
    q->front = q->rear = NULL;
    q->maxSize = size;
    q->currentSize = 0;
}

bool isQueueEmpty(CharQueue* q) {
    return q->currentSize == 0;
}

bool isQueueFull(CharQueue* q) {
    return q->currentSize == q->maxSize;
}

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

void enqueue(CharQueue* q, char ch) {
    if (isQueueFull(q)) {
        printf("Очередь переполнена!\n");
        return;
    }

    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->data = ch;
    newNode->next = NULL;

    if (isQueueEmpty(q)) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->currentSize++;
}

char dequeue(CharQueue* q) {
    if (isQueueEmpty(q)) {
        printf("Очередь пуста!\n");
        return '\0';
    }

    QueueNode* temp = q->front;
    char ch = temp->data;

    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    q->currentSize--;
    return ch;
}

char peekFront(CharQueue* q) {
    if (isQueueEmpty(q)) {
        return '\0';
    }
    return q->front->data;
}

char peekRear(CharQueue* q) {
    if (isQueueEmpty(q)) {
        return '\0';
    }
    return q->rear->data;
}

void displayQueue(CharQueue* q) {
    if (isQueueEmpty(q)) {
        printf("Очередь пуста.\n");
        return;
    }

    QueueNode* temp = q->front;
    printf("Содержимое очереди: ");
    while (temp != NULL) {
        printf("%c ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

typedef struct DequeNode {
    char data;
    struct DequeNode* next;
    struct DequeNode* prev;
} DequeNode;

typedef struct {
    DequeNode* front;
    DequeNode* rear;
    int maxSize;
    int currentSize;
} CharDeque;

void initDeque(CharDeque* dq, int size) {
    dq->front = dq->rear = NULL;
    dq->maxSize = size;
    dq->currentSize = 0;
}

bool isDequeEmpty(CharDeque* dq) {
    return dq->currentSize == 0;
}

bool isDequeFull(CharDeque* dq) {
    return dq->currentSize == dq->maxSize;
}

void insertFront(CharDeque* dq, char ch) {
    if (isDequeFull(dq)) {
        printf("Дек переполнен!\n");
        return;
    }

    DequeNode* newNode = (DequeNode*)malloc(sizeof(DequeNode));
    newNode->data = ch;
    newNode->prev = NULL;
    newNode->next = dq->front;

    if (isDequeEmpty(dq)) {
        dq->rear = newNode;
    } else {
        dq->front->prev = newNode;
    }

    dq->front = newNode;
    dq->currentSize++;
}

void insertRear(CharDeque* dq, char ch) {
    if (isDequeFull(dq)) {
        printf("Дек переполнен!\n");
        return;
    }

    DequeNode* newNode = (DequeNode*)malloc(sizeof(DequeNode));
    newNode->data = ch;
    newNode->next = NULL;
    newNode->prev = dq->rear;

    if (isDequeEmpty(dq)) {
        dq->front = newNode;
    } else {
        dq->rear->next = newNode;
    }

    dq->rear = newNode;
    dq->currentSize++;
}

char deleteFront(CharDeque* dq) {
    if (isDequeEmpty(dq)) {
        printf("Дек пуст!\n");
        return '\0';
    }

    DequeNode* temp = dq->front;
    char ch = temp->data;

    dq->front = dq->front->next;
    if (dq->front == NULL) {
        dq->rear = NULL;
    } else {
        dq->front->prev = NULL;
    }

    free(temp);
    dq->currentSize--;
    return ch;
}

char deleteRear(CharDeque* dq) {
    if (isDequeEmpty(dq)) {
        printf("Дек пуст!\n");
        return '\0';
    }

    DequeNode* temp = dq->rear;
    char ch = temp->data;

    dq->rear = dq->rear->prev;
    if (dq->rear == NULL) {
        dq->front = NULL;
    } else {
        dq->rear->next = NULL;
    }

    free(temp);
    dq->currentSize--;
    return ch;
}

char getFront(CharDeque* dq) {
    if (isDequeEmpty(dq)) {
        return '\0';
    }
    return dq->front->data;
}

char getRear(CharDeque* dq) {
    if (isDequeEmpty(dq)) {
        return '\0';
    }
    return dq->rear->data;
}

void displayDeque(CharDeque* dq) {
    if (isDequeEmpty(dq)) {
        printf("Дек пуст.\n");
        return;
    }

    DequeNode* temp = dq->front;
    printf("Содержимое дека: ");
    while (temp != NULL) {
        printf("%c ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

bool isSymmetricString(const char* str) {
    int len = strlen(str);
    CharQueue q;
    initQueue(&q, len);

    for (int i = 0; i < len; i++) {
        enqueue(&q, str[i]);
    }

    for (int i = 0; i < len / 2; i++) {
        char front = dequeue(&q);
        if (front != str[len - 1 - i]) {
            return false;
        }
    }

    return true;
}

void queue_for_char() {
    int size;
    char ch;
    printf("Введите максимальный размер очереди: ");
    size = correct_choice(size);

    CharQueue queue;
    initQueue(&queue, size);

    while (true) {
        printf("\nВведите символ (или '-' для выхода): ");
        scanf("%c", &ch);
        while (getchar() != '\n');

        if (ch == '-') break;

        if (!isQueueFull(&queue)) {
            if (!isQueueEmpty(&queue) && ch == peekRear(&queue)) {
                printf("\nПервый элемент очереди: %c\n", peekFront(&queue));
            }
            enqueue(&queue, ch);
            displayQueue(&queue);
        } else {
            printf("Очередь переполнена!\n");
        }
    }
}

void dec_for_char() {
    int size;
    char ch;
    printf("Введите максимальный размер дека: ");
    size = correct_choice(size);

    CharDeque deque;
    initDeque(&deque, size);
    bool insertAtFront = true;

    while (true) {
        printf("\nВведите символ (или '-' для выхода): ");
        scanf("%c", &ch);
        while (getchar() != '\n');

        if (ch == '-') break;

        if (!isDequeFull(&deque)) {
            if (insertAtFront) {
                if (!isDequeEmpty(&deque) && ch == getRear(&deque)) {
                    printf("Элемент на другом конце: %c\n", getRear(&deque));
                }
                insertFront(&deque, ch);
            } else {
                if (!isDequeEmpty(&deque) && ch == getFront(&deque)) {
                    printf("Элемент на другом конце: %c\n", getFront(&deque));
                }
                insertRear(&deque, ch);
            }


            insertAtFront = !insertAtFront;
            displayDeque(&deque);
        } else {
            printf("Дек переполнен!\n");
        }
    }
}


void which_lines_are_symmetrical() {
    char inputStr[100];
    printf("Введите строку для проверки на симметричность: ");
    fgets(inputStr, sizeof(inputStr), stdin);
    inputStr[strcspn(inputStr, "\n")] = '\0';

    if (isSymmetricString(inputStr)) {
        printf("Строка симметрична.\n");
    } else {
        printf("Строка не симметрична.\n");
    }
}
