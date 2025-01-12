void task2(void){
    int a[100][100]={0}, a_1=0, numm=0, column=0;
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
    
    int count2=0; int count3 = 0;
    for (int i = 0; i < numm; i++){
        if(first_str_1(a[i], column)){
            count2=i;
            count3 = 1;
            break;
        }
    }
    
    printf("\n");
    if (count3==0){
        printf("Не найдено строки с элементами, упорядоченными по убыванию\n");
    }
    else{
        int temp;
        for(int i = 0; i < numm; i++) {
            for(int j = 0; j < column ; j++) {
                for(int k = count2; k < numm; k++){
                    for(int n = 0; n < column - 1 ; n++){
                        if(a[k][n] > a[k][n+1]){
                            temp = a[k][n];
                            a[k][n] = a[k][n+1];
                            a[k][n+1] = temp;
                        }
                    }
                    break;
                }
            }
        }
        
        printf("Матрица в которой элементы %d строки упорядочены по возрастанию:\n", count2+1);
        print_matrix(numm, column, a);
    }
}
