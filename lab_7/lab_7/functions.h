int start_1(char b){
    char t;
    printf("Матрица заполняется случайными числами(a), вводимыми(b) или из файла(c): ");
    while (1) {
        if ((scanf("%c%c", &b, &t)==2 && t=='\n') && (b == 'a' || b=='b' || b=='c')){
            break;
        }
        else{
            printf("Некорректный ввод. Попробуйте еще раз: ");
            while (getchar() != '\n');
        }
    }
    return b;
}


int choice_task(int task){
    while (1) {
        char t;
        if (scanf("%d%c", &task, &t)==2 && t=='\n'){
            break;
        }
        else{
            printf("Некорректный ввод. Попробуйте еще раз: ");
            while (getchar() != '\n');
        }
    }
    return task;
}


void remove_spaces(const char *input, char **output) {
    int len = 0;
    int in_word = 0;
    const char *src = input;
    while (*src) {
        in_word = !isspace((unsigned char)*src) ? len++ : 0;
        in_word ? (len++, in_word=0) : 0;
        src++;
    }

    if (len > 0 && !isspace((unsigned char)input[len - 1])) {
        len--;
    }

    *output = malloc((len + 1));
    src = input;
    char *dest = *output;
    in_word = 0;
    while (*src) {
        if (!isspace(*src)) {
            *dest++ = *src;
            in_word = 1;
        } else if (in_word) {
            *dest++ = ' ';
            in_word = 0;
        }
        src++;
    }

    if (dest > *output && *(dest - 1) == ' ') {
        dest--;
    }
    *dest = '\0';
}


int string_length(const char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}


void insert_chars(const char *S, const char *S0, char **result, int a, int b) {
    
    int len_S = string_length(S);
    int len_S0 = string_length(S0);

    
    if (b > len_S) {
        b = len_S;
    }


    int new_len = len_S0 + b;
    *result = malloc((new_len + 1));

    

    // Копирование символов из S0 до a-го
    for (int i = 0; i < a+1; i++) {
        // Указатель на строку result
        (*result)[i] = S0[i];
    }

    for (int i = 0; i < b; i++) {
        (*result)[a + i] = S[i];
    }

    for (int i = a; i < len_S0; i++) {
        (*result)[i + b] = S0[i];
    }

    
    (*result)[new_len] = '\0';
}

void swap(char **a, char **b) {
    char *temp = *a;
    *a = *b;
    *b = temp;
}

int partition(char **arr, int low, int high, int (*cmp)(const char *, const char *)) {
    char *pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (cmp(arr[j], pivot) > 0) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quicksort(char **arr, int low, int high, int (*cmp)(const char *, const char *)) {
    if (low < high) {
        int pi = partition(arr, low, high, cmp);
        quicksort(arr, low, pi - 1, cmp);
        quicksort(arr, pi + 1, high, cmp);
    }
}

int compare_length(const char *a, const char *b) {
    int len_a = string_length(a);
    int len_b = string_length(b);
    return len_a - len_b;
}

