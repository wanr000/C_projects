// В матрице размером NxM выполнить сортировку столбцов по убыванию значения максимальногоэлемента методом Шелла
void task2(){
    char b = start_1(b);
    int n = start_22(n);
    int m = start_23(m);
    
    int ** array = (int**) calloc(n, sizeof(int*));
    for (int i = 0; i < n; i++) {
        array[i] = (int*) calloc(m, sizeof(int));
    }
    

    if(b == 'a'){
        FILE *file = fopen("array.txt", "w");
        srand(time(NULL));
        for(int k=0;k<n; k++){
            for(int j=0;j<m; j++){
                array[k][j] = (-20 + rand()%100);
                fprintf(file, "%d  ", array[k][j]);
            }
            fprintf(file, "\n");
        }
        fclose(file);
    }
    else if(b == 'b'){
        FILE *file = fopen("array.txt", "w");
        int nms;
        for(int k=0;k<n;k++){
            for(int j=0;j<m;j++){
                while (1) {
                    nms = scanf("%d", &array[k][j]);
                    if (nms == 1) {
                        break;
                    }
                    else {
                        printf("Введен некорректный символ, введите еще раз: ");
                        while (getchar() != '\n');
                    }
                }
                fprintf(file, "%d  ", array[k][j]);
            }
            fprintf(file, "\n");
        }
        fclose(file);
    }
    else if(b == 'c'){
        FILE *file = fopen("array.txt", "r");
        for(int k=0;k<n; k++){
            for(int j=0;j<m; j++){
                fscanf(file, "%d", &array[k][j]);
            }
            fprintf(file, "\n");
        }
        fclose(file);
    }
    
    printf("Исходный массив: \n");
    print_arr3(n, m, array);
    
    shell_sort_columns(array, n, m);
    printf("\nИзмененный массив: \n");
    print_arr3(n, m, array);
    
    for(int i = 0; i < n; i++) {
        free(array[i]);
    }
    free(array);
}
