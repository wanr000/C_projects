int start_1(char b){
    printf("Матрица заполняется случайными числами(a), вводимыми(b) или из файла(c): ");
    while (1) {
        char t;
        if (scanf(" %c%c", &b, &t) == 2 && t == '\n' && (b == 'a' || b == 'b' || b == 'c')) {
            break;
        }
        else {
            printf("Введен некорректный символ, введите еще раз: ");
            while (getchar() != '\n');
        }
    }
    return b;
}
int start_2(int numm){
    int n=0;
    printf("Введите количество строк массива: ");
    while (1) {
        char t;
        if (scanf("%d%c", &numm, &t) == 2 && t == '\n' && numm >= 1) {
            break;
        }
        else {
            printf("Введен некорректный символ, введите еще раз: ");
            while (getchar() != '\n');
        }
    }
    return numm;
}
int start_22(int numm){
    int n=0;
    printf("Введите количество строк матрицы: ");
    while (1) {
        char t;
        if (scanf("%d%c", &numm, &t) == 2 && t == '\n' && numm >= 1) {
            break;
        }
        else {
            printf("Введен некорректный символ, введите еще раз: ");
            while (getchar() != '\n');
        }
    }
    return numm;
}
int start_23(int column){
    int n=0;
    printf("Введите количество строк матрицы: ");
    while (1) {
        char t;
        if (scanf("%d%c", &column, &t) == 2 && t == '\n' && column >= 1) {
            break;
        }
        else {
            printf("Введен некорректный символ, введите еще раз: ");
            while (getchar() != '\n');
        }
    }
    return column;
}
void print_arr(double * a, int n){
    for(int i = 0; i < n; i++)
        printf("%.1lf  ", a[i]);
    printf("\n");
}
void print_arr2(int n, int *m, double ** a){
    for(int i =0; i < n; i++){
        for(int j = 0; j < m[i]; j++){
            printf("%.1lf  ", a[i][j]);
        }
        printf("\n");
    }
}
void print_arr3(int n, int *m, int ** a){
    for(int i =0; i < n; i++){
        for(int j = 0; j < m[i]; j++){
            printf("%d  ", a[i][j]);
        }
        printf("\n");
    }
}

int choice_task(int task){
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
