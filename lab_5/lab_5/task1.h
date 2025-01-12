// Заполнить массив с клавиатуры вещественными числами. Удалить все целые числа
void task1(void){
    char b = start_1(b);
    int n = start_2(n);
    double * a = malloc(n * sizeof(double));
    double a_1;
    
    if(b == 'a'){
        FILE *file = fopen("array.txt", "w");
        srand(time(NULL));
        for(int k=0;k<n; k++){
            int r = (0 + rand()%2);
            if (r==1){
                a[k]= (-20 + rand()%100);
                fprintf(file, "%.2lf  ", a[k]);
            }
            else{
                a[k]= (-20.3 + rand()%100);
                fprintf(file, "%.2lf  ", a[k]);
            }
        }
        fclose(file);
    }
    else if(b == 'b'){
        FILE *file = fopen("array.txt", "w");
        int nms;
        for(int k=0;k<n;k++){
            while (1) {
                nms = scanf("%lf", &a_1);
                if (nms == 1) {
                    break;
                }
                else {
                    printf("Введен некорректный символ, введите еще раз: ");
                    while (getchar() != '\n');
                }
            }
            a[k] = a_1;
            fprintf(file, "%.2lf  ", a[k]);
        }
        fclose(file);
    }
    else if(b == 'c'){
        FILE *file = fopen("array.txt", "r");
        for(int k=0;k<n; k++){
            fscanf(file, "%lf", &a[k]);
        }
        fclose(file);
    }
    
    printf("Исходный массив: ");
    print_arr(a, n);
    for (int i = 0; i < n; i++) {
        if (a[i] == (int)a[i]) {
            for (int j = i; j < n - 1; j++) {
                a[j] = a[j + 1];
            }
            n--;
            i--;
        }
    }
    
    printf("Измененный массив: ");
    print_arr(a, n);
    free(a);
    
}
