#define MAX_SIZE 100
#define MAX_EXPR_LEN 256

// Структуры данных
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

// Общие функции для стеков
int correct_choice(int task);

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

// Задание 1
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

// Задание 2
void fillStack(IntStack *s, bool isDescending) {
    printf("Введите элементы стека (%s):\n", isDescending ? "убывающий" : "возрастающий");
    int prev;
    prev = correct_choice(prev);
    pushInt(s, prev);

    for (int i = 1; i < s->capacity; i++) {
        int num;
        num = correct_choice(num);
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

// Задание 3
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


// Функция для проверки корректности ввода
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
