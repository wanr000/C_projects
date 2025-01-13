// Ввести радиус, длину ребра и высоту конуса. Найти площадь боковой поверхности, площадь полной поверхности и объем конуса. Результат вывести с точностью до трех знаков после запятой
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
