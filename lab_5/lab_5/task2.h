void task2(void){
    char b = start_1(b);
    int n = start_22(n);
    int m = start_23(m);

    double **array = (double **)calloc(n, sizeof(double *));
    int *cols = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        array[i] = (double *)calloc(m, sizeof(double));
        cols[i] = m;
    }

    if (b == 'a') {
        FILE *file = fopen("array.txt", "w");
        srand(time(NULL));
        for (int k = 0; k < n; k++) {
            for (int j = 0; j < m; j++) {
                int r = rand() % 2;
                if (r == 1) {
                    array[k][j] = -20 + rand() % 100;
                    fprintf(file, "%.2lf  ", array[k][j]);
                } else {
                    array[k][j] = -20.3 + rand() % 100;
                    fprintf(file, "%.2lf  ", array[k][j]);
                }
            }
            fprintf(file, "\n");
        }
        fclose(file);
    }
    else if (b == 'b') {
        FILE *file = fopen("array.txt", "w");
        for (int k = 0; k < n; k++) {
            for (int j = 0; j < m; j++) {
                while (scanf("%lf", &array[k][j]) != 1) {
                    printf("Введен некорректный символ, введите еще раз: ");
                    while (getchar() != '\n');
                }
                fprintf(file, "%.2lf  ", array[k][j]);
            }
            fprintf(file, "\n");
        }
        fclose(file);
    }
    else if (b == 'c') {
        FILE *file = fopen("array.txt", "r");
        for (int k = 0; k < n; k++) {
            for (int j = 0; j < m; j++) {
                fscanf(file, "%lf", &array[k][j]);
            }
        }
        fclose(file);
    }

    printf("Исходный массив:\n");
    print_arr2(n, cols, array);

    for (int i = 0; i < n; i++) {
        int diagIndex = m - 1 - i;
        if (diagIndex >= 0 && diagIndex < m) {
            for (int j = diagIndex; j < cols[i] - 1; j++) {
                array[i][j] = array[i][j + 1];
            }
            cols[i]--;
            array[i] = (double *)realloc(array[i], cols[i] * sizeof(double));
        }
    }

    printf("\nИзмененный массив:\n");
    print_arr2(n, cols, array);

    for (int i = 0; i < n; i++) {
        free(array[i]);
    }
    free(array);
    free(cols);


}
