// Определить количество строк, не содержащих ни одного нулевого элемента; максимальное из чисел, встречающихся в заданной матрице более одного раза
void task1(){
    int a[100][100]={0}, c[100]={0}, m_r = -1, a_1=0, numm=0, column=0;
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
    
    int count2=0;
    for (int i = 0; i < numm; i++){
        if(first_str(a[i], column)){
            count2++;
        }
    }
    for(int k=0;k<numm; k++){
        for (int j=0; j<column; j++){
            c[a[k][j]]++;
        }
    }
    for(int k=0;k<100; k++){
        if(c[k] > 1){
            if(m_r == -1 || k > m_r){
                m_r = k;
            }
        }
    }
    
    printf("Количество строк, матрицы не содержащих ни одного нулевого элемента: %d\n", count2);
    
    if(m_r != -1){
        printf("Максимальное из чисел, встречающихся в заданной матрице более одного раза: %d\n", m_r);
    }
    else{
        printf("Не найдено чисел встречающихся в матрице больше одного раза\n");
    }
}
