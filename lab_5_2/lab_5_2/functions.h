// Структура для узла очереди
typedef struct QueueNode {
    char data;
    struct QueueNode* next;
} QueueNode;

// Структура для очереди
typedef struct {
    QueueNode* front;
    QueueNode* rear;
    int maxSize;
    int currentSize;
} CharQueue;

// Инициализация очереди
void initQueue(CharQueue* q, int size) {
    q->front = q->rear = NULL;
    q->maxSize = size;
    q->currentSize = 0;
}

// Проверка на пустоту очереди
bool isQueueEmpty(CharQueue* q) {
    return q->currentSize == 0;
}

// Проверка на переполнение очереди
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

// Добавление элемента в очередь
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

// Удаление элемента из очереди
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

// Получение первого элемента очереди
char peekFront(CharQueue* q) {
    if (isQueueEmpty(q)) {
        return '\0';
    }
    return q->front->data;
}

// Получение последнего элемента очереди
char peekRear(CharQueue* q) {
    if (isQueueEmpty(q)) {
        return '\0';
    }
    return q->rear->data;
}

// Вывод содержимого очереди
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

// Структура для узла дека
typedef struct DequeNode {
    char data;
    struct DequeNode* next;
    struct DequeNode* prev;
} DequeNode;

// Структура для дека
typedef struct {
    DequeNode* front;
    DequeNode* rear;
    int maxSize;
    int currentSize;
} CharDeque;

// Инициализация дека
void initDeque(CharDeque* dq, int size) {
    dq->front = dq->rear = NULL;
    dq->maxSize = size;
    dq->currentSize = 0;
}

// Проверка на пустоту дека
bool isDequeEmpty(CharDeque* dq) {
    return dq->currentSize == 0;
}

// Проверка на переполнение дека
bool isDequeFull(CharDeque* dq) {
    return dq->currentSize == dq->maxSize;
}

// Добавление элемента в начало дека
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

// Добавление элемента в конец дека
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

// Удаление элемента из начала дека
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

// Удаление элемента из конца дека
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

// Получение первого элемента дека
char getFront(CharDeque* dq) {
    if (isDequeEmpty(dq)) {
        return '\0';
    }
    return dq->front->data;
}

// Получение последнего элемента дека
char getRear(CharDeque* dq) {
    if (isDequeEmpty(dq)) {
        return '\0';
    }
    return dq->rear->data;
}

// Вывод содержимого дека
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

// Функция для проверки симметричности строки с использованием очереди
bool isSymmetricString(const char* str) {
    int len = strlen(str);
    CharQueue q;
    initQueue(&q, len);

    // Помещаем все символы в очередь
    for (int i = 0; i < len; i++) {
        enqueue(&q, str[i]);
    }

    // Сравниваем символы с начала и конца
    for (int i = 0; i < len / 2; i++) {
        char front = dequeue(&q);
        if (front != str[len - 1 - i]) {
            return false;
        }
    }

    return true;
}
