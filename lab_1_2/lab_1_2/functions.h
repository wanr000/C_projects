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

void insert_chars(const char *S, const char *S0, char **result, int a, int b) {
    
    int len_S = strlen(S);
    int len_S0 = strlen(S0);

    
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
