// В одномерном массиве, состоящем из n целых элементов, вычислить:
// 1)номер максимального элемента массива;
// 2)произведение элементов массива, расположенных между первым и вторым нулевыми элементами
void task1(void) {
    double a[100], a_1, max = a[0], p = 1;
    int n, num = 0, null_1, null_2, nm, bn;
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
        srand(time(NULL));
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
    for(int k=0;k<numm; k++){
        printf("%.1lf", a[k]);
        printf(" ");
    }

    // Находим максимальный элемент массива
    for(int k=0;k<numm; k++){
        if (a[k] > max){
            max = a[k];
            num = k;
        }
    }
    printf("\nМаксимальный элемент массива %0.1lf под номером: %d\n", max, num + 1);

    // Находим произведение элементов между 1-м и 2-м нулевым элементом массива
    int count;
    for(int f=0;f<numm; f++){
        if (a[f] ==0){
            count++;
        }
    }
    if(count>=2){
        for(int f=0;f < numm; f++){
            if (a[f] == 0){
                null_1 = f;
                break;
            }
        }
        int null_3 = null_1 + 1;
        for(int j=null_3+1; j > null_3; j++){
            if (a[j] == 0){
                null_2 = j;
                break;
            }
        }
        for(int l = null_3; l < null_2; l++){
            p = p * a[l];
        }
        printf("Произведение элементов между 1-м и 2-м нулевыми элементами: %.1lf\n", p);
    }
    else{
        printf("Не найдено двух нулевых элементов\n");
    }
}
