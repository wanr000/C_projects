// Задание 1.
#include <stdio.h>
#include <math.h>
void task1(void) {
    double rad, len, height, area, area_f, vol;
    printf("Введите радиус, длину ребра и высоту конуса:\n");

    scanf("%lf%lf%lf", &rad, &len, &height);
    area = M_PI*rad*len;
    area_f = area + M_PI*rad*rad;
    vol = 1./3*height*M_PI*rad*rad;
    printf("Площадь боковой поверхности= %.3lf\nПлощадь полной поверхности= %.3lf\nОбъем= %.3lf\n", area, area_f, vol);
}

// Задание 2.
void task2(void) {
    double a, b, c;
    printf("Введите длины сторон треугольника a, b и c:\n");
    scanf("%lf%lf%lf", &a, &b, &c);
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
    printf("Введите длину: ");
    scanf("%f", &X);
    printf("Выберите единицу измерения:\n1 - Дециметры\n2 -Километры\n3 - Метры\n4 - Миллиметры\n5 - Сантиметры\n");
    scanf("%d", &unit);
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
            printf("Неправильный выбор единицы измерения!\n");
            break;
    }
    printf("Длина в метрах: %.3f\n", X);
}


int main(void){
    int task;
    char b;
    
    printf("Выберите задание для проверки: ");
    
    while (1) {
        if(scanf("%d%c",&task, &b) == 2 && b=='\n' && task < 4 && task > 0){
            break;
        }
        else {
            printf("Некорректный ввод. Повторите еще раз: ");
            while (getchar() != '\n');
        }
        
    }
    
    switch(task){
        case 1:
            task1();
            break;
        case 2:
            task2();
            break;
        case 3:
            task3();
            break;
        default:
            return 0;
    }
}
