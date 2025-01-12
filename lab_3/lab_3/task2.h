// В массиве из n элементов удалить элемент до каждого нечетного.
void task2(void) {
    double a[100], a_1;
    int n;
    char b, sym;

    printf("Массив заполняется случайными числами(a) или вводимыми(b): ");
    while (1) {
        if ((scanf("%c%c", &b, &sym)==2) && (b == 'a' || b == 'b' ) && sym=='\n') {
            break;
        }
        else {
            printf("Введен некоретный символ, введите еще раз: ");
            while (getchar() != '\n');
        }
    }

    int numm = 0;
    printf("Введите количество элементов массива: ");
    while (1) {
        char t;
        if (scanf("%d%c", &numm, &t)==2 && numm >= 1 && t == '\n') {
            break;
        }
        else {
            printf("Введен некоретный символ, введите еще раз: ");
            while (getchar() != '\n');
        }
    }
    
    if(b == 'a'){
        for(int k=0;k<numm; k++){
            a[k] = -50 + rand()%150;
        }
    }
    else if(b == 'b'){
        // Задаем свои элементы массива
        double nms;
        for(int k=0;k<numm;k++){
            while (1) {
                char y;
                if (scanf("%lf%c", &a_1, &y) == 2 && y=='\n') {
                    break;
                }
                else {
                    printf("Введен некоретный символ, введите еще раз: ");
                    while (getchar() != '\n');
                }
            }
            a[k] = a_1;
        }
    }

    // Выводим элементы массива
    printf("Введенный массив: ");
    for(int k=0;k<numm; k++){
        printf("%.1lf", a[k]);
        printf(" ");
    }

    // Удаляем элементы
    printf("\n");
    for(int k=0;k<numm; k++){
        if (fmod(a[k], 2)!= 0){
            a[k-1]=0;
        }
    }
    printf("Измененный массив: ");
    for(int k=0;k<numm; k++){
        if (a[k]!=0){
            printf("%.1lf", a[k]);
            printf(" ");
        }
    }
    printf("\n");
}
