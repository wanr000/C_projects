// Задание 1
void task1(void) {
    double a, sum = 0.0, k;

    printf("Введите действительное число a (1 < a < 3): ");
    while (1) {
        char t;
        // Проверка успешности ввода
        if (scanf("%lf%c", &a, &t) == 2 && a > 1 && a < 3 && t=='\n') {
            // Ищем первое число, сумма до которого больше a
            for (int m = 1; m<12; m++) {
                sum = sum + 1. / m;
                if (sum > a){
                    printf("Первое число, которое больше %.2f равно: %.3lf\n", a, sum);
                    break;
                }
            }
            break;
        }
        else {
            printf("Введен некоретный символ, введите еще раз: ");
            // Очистка буфера ввода на случай неверного формата
            while (getchar() != '\n');
        }
    }
}

// Задание 2.
void task2(void) {
    // Объявляем переменные
    double res, resul = 0;
    long int n, k;
    res = 1;

    printf("Введите натуральное число: ");
    while (1) {
        char t;

        // Проверка успешности ввода
        if (scanf("%ld%c", &n, &t) == 2 && n <= 171 && n > 0 && t=='\n') {
            break; // Выход из цикла при корректном вводе
        }
        else {
            printf("Введен некоретный символ, введите ещераз: ");
            // Очистка буфера ввода на случай неверного формата
            while (getchar() != '\n');
        }
    }
    
    printf("Вы ввели число: %ld\n", n);
    
    // Вычисление по формуле
    for (int m = 1; m<n; m++) {
        res = res*m;
        resul = resul + res;
    }

    printf("Результат: D = %0.lf\n", resul);
}

//Задание 3
void task3(void) {
    double a, b, c, k1, k2, k3, number_a = 0, number_b = 0,
    square = 0;

    printf("Введите стороны A, B, C: ");
    while (1) {
        char t;
        // Проверка успешности ввода
        if (scanf("%lf%lf%lf%c", &a, &b, &c, &t)==4 && a > 0 && b > 0, c > 0 && t=='\n') {
            break; // Выход из цикла при корректном вводе
        }
        else {
            printf("Введен некоретный символ, введите еще раз: ");
            // Очистка буфера ввода на случай неверного формата
            while (getchar() != '\n');
        }
    }
    
    while(a >= c){
        a -= c;
        number_a ++;
    }
    while(b >= c){
        b -= c;
        number_b++;
    }

    for(int k = 1; k <= number_a; k++){
    square += number_b;
    }

    printf("Kоличество квадратов размещенных на прямоугольнике: %0.lf\n", square);
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

