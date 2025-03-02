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
