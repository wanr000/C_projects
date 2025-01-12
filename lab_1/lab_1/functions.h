// Задание 1
void task1(void) {
    double rad, len, height, area, area_f, vol;
    char b;
    printf("Введите радиус, длину ребра и высоту конуса: ");

    while (1) {
        if(scanf("%lf%lf%lf%c", &rad, &len, &height, &b) == 4 && b=='\n' && rad > 0 && len > 0 && height >0){
            break;
        }
        else {
            printf("Некорректный ввод. Повторите еще раз: ");
            while (getchar() != '\n');
        }
    }
    area = M_PI*rad*len;
    area_f = area + M_PI*rad*rad;
    vol = 1./3*height*M_PI*rad*rad;
    printf("Площадь боковой поверхности= %.3lf\nПлощадь полной поверхности= %.3lf\nОбъем= %.3lf\n", area, area_f, vol);
}

// Задание 2.
void task2(void) {
    double a, b, c;
    char t;
    printf("Введите длины сторон треугольника a, b и c: ");
    while (1) {
        if(scanf("%lf%lf%lf%c", &a, &b, &c, &t) == 4 && t=='\n' && a > 0 && b > 0 && c > 0){
            break;
        }
        else {
            printf("Некорректный ввод. Повторите еще раз: ");
            while (getchar() != '\n');
        }
    }
    
    if (a==b || b==c || a==c) {
        printf("Равнобедренный треугольник\n");
    }
    else{
        printf("Не равнобедренный треугольник\n");
    }
}

//Задание 3
void task3(void) {
    float X;
    int unit;
    char b, c;
    printf("Введите длину: ");
    while (1) {
        if(scanf("%f%c", &X, &b) == 2 && b=='\n' && X > 0){
            break;
        }
        else {
            printf("Некорректный ввод. Повторите еще раз: ");
            while (getchar() != '\n');
        }
    }
    printf("Выберите единицу измерения:\n1 - Дециметры\n2 -Километры\n3 - Метры\n4 - Миллиметры\n5 - Сантиметры\n");
    while (1) {
        if(scanf("%d%c", &unit, &c) == 2 && c=='\n' && unit < 6 &&  unit> 0){
            break;
        }
        else {
            printf("Некорректный ввод. Повторите еще раз: ");
            while (getchar() != '\n');
        }
    }
    
    switch(unit) {
        case 1:
            X = X / 10;
            break;
        case 2:
            X = X * 1000;
        case 3:
            break;
        case 4:
            X = X / 1000;
            break;
        case 5:
            X = X / 100;
            break;
        default:
            break;
    }
    printf("Длина в метрах: %.3f\n", X);
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
