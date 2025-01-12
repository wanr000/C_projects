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
    printf("Введите количество строк матрицы: ");
    while (1) {
        char t;
        if (scanf("%d%c", &numm, &t) == 2 && t == '\n' && numm >= 1 && numm <100
            ) {
            break;
        }
        else {
            printf("Введен некорректный символ, введите еще раз: ");
            while (getchar() != '\n');
        }
    }
    return numm;
}
int start_3(int column){
    printf("Введите количество столбцев матрицы: ");
    while (1) {
        char t;
        if (scanf("%d%c", &column, &t) == 2 && t == '\n' && column >= 1 && column < 100) {
            break;
        }
        else {
            printf("Введен некорректный символ, введите еще раз: ");
            while (getchar() != '\n');
        }
    }
    return column;
}
void print_matrix(int numm, int column, int a[][100]){
    for(int i = 0; i < numm; i++) {
        printf("| ");
        for(int j = 0; j < column ; j++) {
            printf("%d ", a[i][j]);
        }
        printf("|\n");
    }
}
int first_str(int a[], int columns){
    for (int i = 1; i < columns; i++){
        if (a[i] == 0){
            return 0;
        }
    }
    return 1;
}
int first_str_1(int a[], int columns){
    for (int i = 1; i < columns; i++){
        if (a[i] > a[i-1]){
            return 0;
        }
    }
    return 1;
}
int sum_matrix(int numm, int column, int n1, int n2, int a[][100]){
    int sum = 0;
    for(int i = 0; i < numm; i++) {
        for(int j = 0; j < column ; j++){
            if(i-j==n1 || i+j == n2){
                break;
            }
            else{
                sum += a[i][j];
            }
        }
    }
    return sum;
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
