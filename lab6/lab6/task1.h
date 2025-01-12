// В одномерном массиве выполнить сортировку нечетных отрицательных элементов методом пузырька
void task1(){
    char b = start_1(b);
    int n = start_2(n);
    int * a = malloc(n * sizeof(int));
    int a_1;

    if(b == 'a'){
        FILE *file = fopen("array.txt", "w");
        srand(time(NULL));
        for(int k=0;k<n; k++){
            a[k]= (-50 + rand()%100);
            fprintf(file, "%d  ", a[k]);
        }
        fclose(file);
    }
    else if(b == 'b'){
        FILE *file = fopen("array.txt", "w");
        int nms;
        for(int k=0;k<n;k++){
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
            a[k] = a_1;
            fprintf(file, "%d  ", a[k]);
            }
            fclose(file);
    }
    else if(b == 'c'){
        FILE *file = fopen("array.txt", "r");
        for(int k=0;k<n; k++){
            fscanf(file, "%d", &a[k]);
        }
        fclose(file);
    }

    printf("Исходный массив: ");
    print_arr(a, n);

    bubble_sort(a, n);

    printf("Измененный массив: ");
    print_arr(a, n);
    free(a);

}
