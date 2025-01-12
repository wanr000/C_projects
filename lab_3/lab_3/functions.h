// Задание 1
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


// Задание 2.
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


//Задание 3
void task3(void) {
    int a[100], a_1, a_2;
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

    if(b == 'a'){
    srand(time(NULL));
    for(int k=0;k<40; k++){
        a[k] = 0 + rand()%10;
        }
    }
    else if(b == 'b'){
        // Задаем свои элементы массива
        printf("Введите первое число: ");
        for(int k=0;k<20;k++){
            while (1) {
                char t;
                if (scanf("%d%c", &a_1)==2 && t == '\n' && a_1 >=0 && a_1 < 10) {
                    break;
                }
                else {
                    printf("Введен некоретный символ, введите еще раз: ");
                    while (getchar() != '\n');
                }
            }
            a[k] = a_1;
        }
        printf("Введите второе число: ");
        for(int k=20;k<41;k++){
            while (1) {
                char t;
                if (scanf("%d%c", &a_2)==2 && t=='\n' && a_2 >=0 && a_2 < 10){
                    break;
                }
                else {
                    printf("Введен некоретный символ, введите еще раз: ");
                    while (getchar() != '\n');
                }
            }
            a[k] = a_2;
        }
    }

    int count = 0;
    // Выводим элементы массива
    printf("Первое число:  ");
    for(int k=0;k<20; k++){
        if(count==2){
            printf(" ");
        }
        count++;
        
        if(count>2){
            count=count+3;
        }
        
        if(count%3 == 0 && k>4){
            printf(" ");
        }
        printf("%d", a[k]);
    }
    
    int count_2 = 0;
    printf("\nВторое число:  ");
    for(int k=20;k<40; k++){

        if(count_2==2){
            printf(" ");
        }
        count_2++;

        if(count>2){
            count_2=count_2+3;
        }
        if(count_2%3 == 0){
            printf(" ");
        }
        printf("%d", a[k]);
    }
    printf("\n");

    int ost;
    for(int k = 41; k>21 ;k--){
        int sum = a[k-22] + a[k-2] + ost;

        if(sum >= 10){
            a[k+40] = sum - 10;
            ost = 1;
        }
        else{
            a[k+40] = sum;
            ost = 0;
        }
    }

    a[61] = ost;

    printf("Cумма чисел :");
    int count_3 = 0;
    for(int k = 61; k<82 ;k++){
        if (count_3 % 3 == 0){
            printf(" ");
        }
        printf("%d", a[k]);
        count_3++;
    }
    printf("\n");
    
}


// Основные функции
int choice_task(int task){
    while (1) {
        char b;
        if(scanf("%d%c",&task, &b) == 2 && b=='\n'){
            break;
        }
        else {
            printf("Некорректный ввод. Повторите еще раз: ");
            while (getchar() != '\n');
        }
    }
    return task;
}

void start(void){
    int task;
    printf("Выберите задание для проверки: ");
    
    task = choice_task(task);
    
    while (1) {
        if (task == 1){
            task1();
            break;;
        }
        if (task == 2){
            task2();
            break;
        }
        if (task == 3){
            task3();
            break;
        }
        else{
            printf("Неверный номер задания. Попробуйте еще раз: ");
            task = choice_task(task);
        }
    }
    
}


