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
    s->top = -1;
    s->capacity = 0;
}


size_t strlen(const char *s) {
    size_t len = 0;
    // Проверяем на NULL на всякий случай, хотя стандартный strlen этого не делает
    if (s == NULL) {
        return 0;
    }
    while (s[len] != '\0') {
        len++;
    }
    return len;
}

int isspace(int c) {
    return (c == ' ' || c == '\f' || c == '\n' || c == '\r' || c == '\t' || c == '\v');
}

int isdigit(int c) {
    return (c >= '0' && c <= '9');
}

size_t strcspn(const char *s1, const char *s2) {
    size_t len = 0;
    const char *p1, *p2;

    if (s1 == NULL || s2 == NULL) {
        return 0; // Обработка NULL-указателей
    }

    for (p1 = s1; *p1 != '\0'; ++p1) {
        // Проверяем, есть ли символ *p1 в строке s2
        for (p2 = s2; *p2 != '\0'; ++p2) {
            if (*p1 == *p2) {
                // Найден символ из s2 в s1, возвращаем текущую длину сегмента
                return len;
            }
        }
        // Символ *p1 не найден в s2, увеличиваем длину сегмента
        len++;
    }

    // Дошли до конца s1, не найдя ни одного символа из s2
    return len;
}

int strcmp(const char *s1, const char *s2) {
     if (s1 == NULL && s2 == NULL) return 0;
     if (s1 == NULL) return -1; // NULL считается меньше любой строки
     if (s2 == NULL) return 1;  // Любая строка считается больше NULL

    // Идем по строкам, пока символы совпадают и не достигнут конец одной из строк
    while (*s1 != '\0' && *s1 == *s2) {
        s1++;
        s2++;
    }
    // Возвращаем разницу кодов первых несовпадающих символов (или 0, если строки равны).
    // Важно использовать unsigned char для корректного сравнения кодов > 127.
    return *(const unsigned char*)s1 - *(const unsigned char*)s2;
}


// Задание 1
int findMostFrequentElement(IntStack *s) {
    if (isIntStackEmpty(s)) {
        return INT_MIN;
    }

    int max_count = 1;
    int most_frequent = s->data[0];
    
    // Проходим по всем элементам стека
    for (int i = 0; i <= s->top; i++) {
        int count = 1;
        // Считаем количество вхождений текущего элемента
        for (int j = i + 1; j <= s->top; j++) {
            if (s->data[i] == s->data[j]) {
                count++;
            }
        }
        // Если нашли более частый элемент, или такой же частый, но больше по значению
        if (count > max_count || (count == max_count && s->data[i] > most_frequent)) {
            max_count = count;
            most_frequent = s->data[i];
        }
    }

    return most_frequent;
}

// Задание 2
void CopyStack(IntStack *dest, const IntStack *src) { // src теперь const
    IntStack temp1, temp2;
    // Проверяем src->capacity, чтобы избежать выделения 0 или отрицательной памяти
    if (src->capacity <= 0) {
         // Обработка ошибки или инициализация dest пустым
         initIntStack(dest, 0); // Например, инициализируем пустым
         fprintf(stderr, "Предупреждение: Попытка копировать стек с невалидной вместимостью.\n");
         return;
     }

    initIntStack(&temp1, src->capacity);
    initIntStack(&temp2, src->capacity);

    // 1. Скопировать данные из массива src->data в temp1
    // Порядок в temp1 будет как в массиве: [дно ... вершина]
    for (int i = 0; i <= src->top; i++) {
        pushInt(&temp1, src->data[i]);
    }

    // 2. Переложить из temp1 в temp2 (переворачивает порядок)
    // Порядок в temp2 будет: [вершина ... дно]
    while (!isIntStackEmpty(&temp1)) {
        pushInt(&temp2, popInt(&temp1));
    }

    // 3. Переложить из temp2 в dest (снова переворачивает)
    // Порядок в dest будет: [дно ... вершина] - точная копия src
    while (!isIntStackEmpty(&temp2)) {
        pushInt(dest, popInt(&temp2));
    }

    freeIntStack(&temp1);
    freeIntStack(&temp2);
}

void mergeAscendingStacks(IntStack *s1, IntStack *s2, IntStack *result) {
    IntStack temp1, temp2;
    initIntStack(&temp1, s1->capacity); // Используем оригинальные capacity
    initIntStack(&temp2, s2->capacity);

    // Создаем копии исходных стеков
    // Если s1 = [1, 3, 5] (5 - вершина), то temp1 = [1, 3, 5] (5 - вершина)
    // Если s2 = [2, 4, 6] (6 - вершина), то temp2 = [2, 4, 6] (6 - вершина)
    CopyStack(&temp1, s1);
    CopyStack(&temp2, s2);

    // Сливаем стеки, сравнивая вершины (самые большие доступные элементы)
    // Помещаем БОЛЬШИЙ из них в result.
    // Это строит result в порядке [6, 5, 4, 3, 2, 1] (1 - вершина)
    while (!isIntStackEmpty(&temp1) && !isIntStackEmpty(&temp2)) {
        if (peekInt(&temp1) > peekInt(&temp2)) {
            pushInt(result, popInt(&temp1)); // Кладем больший в result
        } else {
            pushInt(result, popInt(&temp2)); // Кладем больший (или равный) в result
        }
    }

    // Добавляем оставшиеся элементы из одного из стеков
    while (!isIntStackEmpty(&temp1)) {
        pushInt(result, popInt(&temp1));
    }
    while (!isIntStackEmpty(&temp2)) {
        pushInt(result, popInt(&temp2));
    }

    // Теперь result содержит элементы в порядке [max, ..., min], min на вершине.
    // При печати через popInt порядок будет возрастающим.

    freeIntStack(&temp1);
    freeIntStack(&temp2);
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
