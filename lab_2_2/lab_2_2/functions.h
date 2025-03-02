int correct_choice(int task){
    while (1) {
        char b;
        if(scanf("%d%c",&task, &b) == 2 && b=='\n'){
            break;
        }
        else {
            printf("Некорректный ввод. Повторите еще раз: ");
            while (getchar() != '\n');
        }
    }
    return task;
}


void fill_file_from_input(const char *filename) {
    char *str = NULL;
    size_t size = 0;

    printf("Введите строку: ");
    getline(&str, &size, stdin);

    // Удаляем символ новой строки, добавленный getline
    str[strcspn(str, "\n")] = '\0';

    // Запись строки в файл
    FILE *f = fopen(filename, "wt");
    if (f == NULL) {
        perror("Ошибка открытия файла");
        free(str);
        return;
    }
    fputs(str, f);
    fclose(f);

    free(str);
}


void print_file_content(const char *filename) {
    char *str = NULL;
    size_t size = 0;

    FILE *f = fopen(filename, "rt");
    if (f == NULL) {
        perror("Ошибка открытия файла");
        return;
    }

    // Чтение строки из файла
    getline(&str, &size, f);
    printf("\n1| Элементы в файле: %s\n", str);

    fclose(f);
    free(str);
}


// Функция для поиска самой длинной последовательности повторяющихся символов
void find_longest_sequence(const char *str) {
    int max_length = 1, current_length = 1;
    char max_char = str[0];
    
    for (int i = 1; str[i] != '\0'; i++) {
        if (str[i] == str[i - 1]) {
            current_length++;
        } else {
            if (current_length > max_length) {
                max_length = current_length;
                max_char = str[i - 1];
            }
            current_length = 1;
        }
    }
    
    if (current_length > max_length) {
        max_length = current_length;
        max_char = str[strlen(str) - 1];
    }
    
    printf("\n2| Самая длинная последовательность: '");
    for (int i = 0; i < max_length; i++) {
        printf("%c", max_char);
    }
    printf("' (длина: %d)\n", max_length);
}


void find_and_print_longest_sequence(const char *filename) {
    char *str = NULL;
    size_t size = 0;

    FILE *f = fopen(filename, "rt");
    if (f == NULL) {
        perror("Ошибка открытия файла");
        return;
    }

    // Чтение строки из файла
    getline(&str, &size, f);
    fclose(f);

    // Поиск и вывод самой длинной последовательности
    find_longest_sequence(str);

    free(str);
}


// Функция для замены слов заданной длины пробелами
void replace_words_of_length(char *str, int length) {
    int i = 0, j = 0;
    while (str[i] != '\0') {
        // Пропускаем пробелы
        if (str[i] == ' ') {
            i++;
            continue;
        }
        
        // Находим начало слова
        int start = i;
        while (str[i] != ' ' && str[i] != '\0') {
            i++;
        }
        int end = i;
        
        // Проверяем длину слова
        if (end - start == length) {
            // Заменяем слово пробелами
            for (int k = start; k < end; k++) {
                str[k] = ' ';
            }
        }
    }
    
    // Удаляем лишние пробелы
    i = 0, j = 0;
    while (str[i] != '\0') {
        // Пропускаем лишние пробелы
        if (str[i] == ' ' && (i == 0 || str[i - 1] == ' ')) {
            i++;
            continue;
        }
        // Копируем символ
        str[j++] = str[i++];
    }
    str[j] = '\0'; // Завершаем строку
}

void replace_words_and_save(const char *filename, int word_length) {
    char *str = NULL;
    size_t size = 0;

    FILE *f = fopen(filename, "rt");
    if (f == NULL) {
        perror("Ошибка открытия файла");
        return;
    }

    // Чтение строки из файла
    getline(&str, &size, f);
    fclose(f);

    // Замена слов заданной длины пробелами
    replace_words_of_length(str, word_length);

    // Запись измененной строки обратно в файл
    f = fopen(filename, "wt");
    if (f == NULL) {
        perror("Ошибка открытия файла");
        free(str);
        return;
    }
    fputs(str, f);
    fclose(f);

    // Вывод измененного содержимого файла
    printf(" | Файл после замены всех слов длиной %d пробелами: %s\n", word_length, str);

    free(str);
}
