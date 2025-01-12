// Составить программу, выполняющую сложение 20-значных чисел.
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
