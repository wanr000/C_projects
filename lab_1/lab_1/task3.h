// Составить программу, которая бы по значению переменной Х, означающему некоторую длину в следующих единицах измерения: дециметр, километр, метр, миллиметр, сантиметр, выдавала бы эту длину в метрах
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

