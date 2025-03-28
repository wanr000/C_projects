// ======================== Структуры данных ========================
typedef struct {
    int *data;
    int top;
    int capacity;
} IntStack;

typedef struct {
    double *data;
    int top;
    int capacity;
} DoubleStack;

typedef struct {
    char *data;
    int top;
    int capacity;
} CharStack;

// ======================== Общие функции для стеков ========================
void initIntStack(IntStack *s, int capacity) {
    s->data = (int*)malloc(capacity * sizeof(int));
    if (!s->data) exit(1);
    s->top = -1;
    s->capacity = capacity;
}

void initDoubleStack(DoubleStack *s, int capacity) {
    s->data = (double*)malloc(capacity * sizeof(double));
    if (!s->data) exit(1);
    s->top = -1;
    s->capacity = capacity;
}

void initCharStack(CharStack *s, int capacity) {
    s->data = (char*)malloc(capacity * sizeof(char));
    if (!s->data) exit(1);
    s->top = -1;
    s->capacity = capacity;
}

bool isIntStackFull(IntStack *s) { return s->top == s->capacity - 1; }
bool isIntStackEmpty(IntStack *s) { return s->top == -1; }

void pushInt(IntStack *s, int value) {
    if (isIntStackFull(s)) return;
    s->data[++s->top] = value;
}

int popInt(IntStack *s) {
    if (isIntStackEmpty(s)) return -1;
    return s->data[s->top--];
}

int peekInt(IntStack *s) {
    if (isIntStackEmpty(s)) return -1;
    return s->data[s->top];
}

// Добавление символа в стек
void pushChar(CharStack *s, char value) {
    if (s->top == s->capacity - 1) return;  // Проверка на переполнение
    s->data[++s->top] = value;              // Добавление элемента
}

char popChar(CharStack *s) {
    if (s->top == -1) return '\0';  // Возвращаем нулевой символ, если стек пуст
    return s->data[s->top--];       // Возвращаем верхний элемент и уменьшаем указатель вершины
}

// Проверка на пустоту стека
bool isCharStackEmpty(CharStack *s) {
    return s->top == -1;
}

// Просмотр верхнего элемента без извлечения
char peekChar(CharStack *s) {
    if (isCharStackEmpty(s)) return '\0';
    return s->data[s->top];
}

// Добавление double в стек
void pushDouble(DoubleStack *s, double value) {
    if (s->top == s->capacity - 1) return;  // Проверка на переполнение
    s->data[++s->top] = value;             // Добавление элемента
}

// Извлечение double из стека
double popDouble(DoubleStack *s) {
    if (s->top == -1) return 0.0;          // Возвращаем 0.0, если стек пуст
    return s->data[s->top--];              // Возвращаем верхний элемент
}

void freeIntStack(IntStack *s) {
    free(s->data);
}

