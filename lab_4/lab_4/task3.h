void task3(void){
    int a[100][100]={0},  a_1=0, numm=0, column=0;
    char b;
    
    b = start_1(b);
    numm = start_2(numm);
    column = start_3(column);
    
    if(b == 'a'){
        FILE *file = fopen("array.txt", "w");
        srand(time(NULL));
        for(int k=0;k<numm; k++){
            for (int j=0; j<column; j++){
                a[k][j] = -50 + rand()%150;
                fprintf(file, "%d  ", a[k][j]);
            }
            fprintf(file, "\n");
        }
        fclose(file);
    }
    
    else if(b == 'b'){
        // Задаем свои элементы массива
        FILE *file = fopen("array.txt", "w");
        int nms;
        for(int k=0;k<numm;k++){
            for (int j=0; j<column; j++){
                while (1) {
                    nms = scanf("%d", &a_1);
                    if (nms == 1) {
                        break;
                    }
                    else {
                        printf("Введен некорректный символ, введите еще раз: ");
                        while (getchar() != '\n');
                    }
                }
                a[k][j] = a_1;
                fprintf(file, "%d  ", a[k][j]);
            }
            fprintf(file, "\n");
        }
        fclose(file);
    }
    
    else if(b == 'c'){
        FILE *file = fopen("array.txt", "r");
        for(int k=0;k<numm; k++){
            for (int j=0; j<column; j++){
                fscanf(file, "%d", &a[k][j]);
            }
        }
        fclose(file);
    }
    
    print_matrix(numm, column, a);
    printf("При подсчете суммы учитывать элементы на диагоналях матрицы(a) или нет(b): ");
    while (1) {
        char t;
        if ((scanf(" %c%c", &b,&t) && t=='\n') &&(b == 'a' || b == 'b')) {
            break;
        }
        else {
            printf("Введен некорректный символ, введите еще раз: ");
            while (getchar() != '\n');
        }
    }

    if(b=='a'){
        printf("Cумма элементов в четвертой области равна: %d\n", sum_matrix(numm, column, 1, numm, a));
    }
    if(b=='b'){
        printf("Cумма элементов в четвертой области равна: %d\n", sum_matrix(numm, column, 0, numm-1, a));
    }
}
