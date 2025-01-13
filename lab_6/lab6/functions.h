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
    printf("Введите количество элементов массива: ");
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

int start_22(int numm){
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

int start_23(int column){
    int n=0;
    printf("Введите количество столбцев матрицы: ");
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

void print_arr(int * a, int n){
    for(int i = 0; i < n; i++)
        printf("%d  ", a[i]);
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

void print_arr3(int n, int m, int ** a){
    for(int i =0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%d  ", a[i][j]);
        }
        printf("\n");
    }
}

void bubble_sort(int * a, int size){
    int count = 0;
    for(int i=0; i<size;i++){
        if(a[i]<0 && a[i]%2!=0){
            count++;
        }
    }
    
    int index=0;
    int * new_a = (int*)malloc(count*sizeof(int));
    for(int i=0; i<size; i++){
        if(a[i]<0 && a[i]%2!=0){
            new_a[index] = a[i];
            index++;
        }
    }
    
    for(int i=0; i<count - 1; i++){
        for(int k=0; k<count - i - 1;k++){
            if(new_a[k] > new_a[k+1]){
                int temp = new_a[k];
                new_a[k] = new_a[k+1];
                new_a[k+1] = temp;
            }
        }
    }
    
    index=0;
    for(int i=0; i<size; i++){
        if(a[i] < 0 && a[i]%2 != 0){
            a[i] = new_a[index];
            index++;
        }
    }
    
    free(new_a);
}


int find_max_in_column(int **matrix, int rows, int col) {
    int max = matrix[0][col];
    for (int i = 1; i < rows; i++) {
        if (matrix[i][col] > max) {
            max = matrix[i][col];
        }
    }
    return max;
}

void shell_sort_columns(int **matrix, int rows, int cols) {
    int *max_values = (int*)malloc(cols * sizeof(int));
    for (int j = 0; j < cols; j++) {
        max_values[j] = find_max_in_column(matrix, rows, j);
    }

    for (int gap = cols / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < cols; i++) {
            int temp_max = max_values[i];
            int *temp_col = (int*)malloc(rows * sizeof(int));
            for (int k = 0; k < rows; k++) {
                temp_col[k] = matrix[k][i];
            }
            
            int j;
            for (j = i; j >= gap && max_values[j - gap] < temp_max; j -= gap) {
                max_values[j] = max_values[j - gap];
                for (int k = 0; k < rows; k++) {
                    matrix[k][j] = matrix[k][j - gap];
                }
            }
            
            max_values[j] = temp_max;
            for (int k = 0; k < rows; k++) {
                matrix[k][j] = temp_col[k];
            }
            free(temp_col);
        }
    }
    free(max_values);
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
