// В двумерном массиве (количество чисел в строке может быть различным, последнее число - -100.) в каждой четной строке продублировать нечетный элемент
void task3(void){
    char b = start_1(b);
    int n = start_22(n);
    int m = start_23(m);
    
    int ** array = (int**) calloc(n, sizeof(int*));
    int * cols = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        array[i] = (int*) calloc(m, sizeof(int));
        cols[i] = m;
    }
    
    if(b == 'a'){
        FILE *file = fopen("array.txt", "w");
        srand(time(NULL));
        for(int k=0;k<n; k++){
            for(int j=0;j<m; j++){
                array[k][j] = (-20 + rand()%100);
                fprintf(file, "%d  ", array[k][j]);
                array[k][m-1]=-100;
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
                array[k][m-1]=-100;
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
                array[k][m-1]=-100;
            }
            fprintf(file, "\n");
        }
        fclose(file);
    }
    
    printf("Исходный массив: \n");
    print_arr3(n, cols, array);
    
    
    for(int i = 0; i < n; i++) {
        if((i+1)%2==0){
            for(int j = 0; j < cols[i]; j++){
                if(array[i][j]%2!=0){
                    cols[i]++;
                    array[i] = (int *)realloc(array[i], cols[i] * sizeof(int));
                    
                    for(int k=cols[i]-1; k > j; k--){
                        array[i][k] = array[i][k-1];
                    }
                    
                    array[i][j+1] = array[i][j];
                    j++;
                }
            }
        }
    }
    printf("\nИзмененный массив: \n");
    print_arr3(n, cols, array);
    
    for(int i = 0; i < n; i++) {
        free(array[i]);
    }
    free(array);
    free(cols);
    
}
