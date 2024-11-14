#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


int start(int unit){
    printf("Введите номер задания, которое необходимо запустить: ");
    while (1) {
        int n;
        n = scanf("%d", &unit);
        if (n == 1 && unit >= 1 && unit <= 3) {
            break;
        }
        else {
            printf("Введен некорректный символ, введите еще раз: ");
            while (getchar() != '\n');
        }
    }
    return unit;
}

int start_1(char b){
    printf("Матрица заполняется случайными числами(a), вводимыми(b) или из файла(c): ");
    while (1) {
        char sym;
        sym = scanf(" %c", &b);
        if (sym == 1 && (b == 'a' || b == 'b' || b == 'c')) {
            break;
        }
        else {
            printf("Введен некорректный символ, введите еще раз: ");
            while (getchar() != '\n');
        }
    }
    return b;
}
int start_2(int numm){
    int n=0;
    printf("Введите количество строк матрицы: ");
    while (1) {
        n = scanf("%d", &numm);
        if (n == 1 && numm >= 1 && numm <100) {
            break;
        }
        else {
            printf("Введен некорректный символ, введите еще раз: ");
            while (getchar() != '\n');
        }
    }
    return numm;
}
int start_3(int column){
    int n = 0;
    printf("Введите количество столбцев матрицы: ");
    while (1) {
        n = scanf("%d", &column);
        if (n == 1 && column >= 1 && column < 100) {
            break;
        }
        else {
            printf("Введен некорректный символ, введите еще раз: ");
            while (getchar() != '\n');
        }
    }
    return column;
}

void print_matrix(int numm, int column, int a[][100]){
    for(int i = 0; i < numm; i++) {
        printf("| ");
        for(int j = 0; j < column ; j++) {
            printf("%d ", a[i][j]);
        }
        printf("|\n");
    }
}

int first_str(int a[], int columns){
    for (int i = 1; i < columns; i++){
        if (a[i] == 0){
            return 0;
        }
    }
    return 1;
}

int first_str_1(int a[], int columns){
    for (int i = 1; i < columns; i++){
        if (a[i] > a[i-1]){
            return 0;
        }
    }
    return 1;
}

int sum_matrix(int numm, int column, int n1, int n2, int a[][100]){
    int sum = 0;
    for(int i = 0; i < numm; i++) {
        for(int j = 0; j < column ; j++){
            if(i-j==n1 || i+j == n2){
                break;
            }
            else{
                sum += a[i][j];
            }
        }
    }
    return sum;
}

int main(){
    int a[100][100]={0}, c[100]={0}, m_r = -1, a_1=0, numm=0, column=0, unit=0;
    char b;
    
    
    unit = start(unit);
    b = start_1(b);
    numm = start_2(numm);
    column = start_3(column);
    
    if(b == 'a'){
        FILE *file = fopen("array.txt", "w");
        srand(time(NULL));
        for(int k=0;k<numm; k++){
            for (int j=0; j<column; j++){
                a[k][j] = -50 + rand()%150;
                fprintf(file, "%d  ", a[k][j]);
            }
            fprintf(file, "\n");
        }
        fclose(file);
    }
    
    else if(b == 'b'){
        // Задаем свои элементы массива
        FILE *file = fopen("array.txt", "w");
        int nms;
        for(int k=0;k<numm;k++){
            for (int j=0; j<column; j++){
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
                a[k][j] = a_1;
                fprintf(file, "%d  ", a[k][j]);
            }
            fprintf(file, "\n");
        }
        fclose(file);
    }
    
    else if(b == 'c'){
        FILE *file = fopen("array.txt", "r");
        for(int k=0;k<numm; k++){
            for (int j=0; j<column; j++){
                fscanf(file, "%d", &a[k][j]);
            }
        }
        fclose(file);
    }
    
    switch(unit) {
        // Задание 1
        case 1:
            print_matrix(numm, column, a);
            
            int count2=0;
            for (int i = 0; i < numm; i++){
                if(first_str(a[i], column)){
                    count2++;
                }
            }
            for(int k=0;k<numm; k++){
                for (int j=0; j<column; j++){
                    c[a[k][j]]++;
                }
            }
            for(int k=0;k<100; k++){
                if(c[k] > 1){
                    if(m_r == -1 || k > m_r){
                        m_r = k;
                    }
                }
            }
            
            printf("Количество строк, матрицы не содержащих ни одного нулевого элемента: %d\n", count2);
            
            if(m_r != -1){
                printf("Максимальное из чисел, встречающихся в заданной матрице более одного раза: %d\n", m_r);
            }
            else{
                printf("Не найдено чисел встречающихся в матрице больше одного раза\n");
            }
            break;
        
        // Задание 2
        case 2:
            print_matrix(numm, column, a);
            
            count2=0; int count3 = 0;
            for (int i = 0; i < numm; i++){
                if(first_str_1(a[i], column)){
                    count2=i;
                    count3 = 1;
                    break;
                }
            }
            
            printf("\n");
            if (count3==0){
                printf("Не найдено строки с элементами, упорядоченными по убыванию\n");
            }
            else{
                int temp;
                for(int i = 0; i < numm; i++) {
                    for(int j = 0; j < column ; j++) {
                        for(int k = count2; k < numm; k++){
                            for(int n = 0; n < column - 1 ; n++){
                                if(a[k][n] > a[k][n+1]){
                                    temp = a[k][n];
                                    a[k][n] = a[k][n+1];
                                    a[k][n+1] = temp;
                                }
                            }
                            break;
                        }
                    }
                }
                
                printf("Матрица в которой элементы %d строки упорядочены по возрастанию:\n", count2+1);
                print_matrix(numm, column, a);
            }
            break;
              
        // Задание 3
        case 3:
            print_matrix(numm, column, a);

            printf("При подсчете суммы учитывать элементы на диагоналях матрицы(a) или нет(b): ");
            while (1) {
                scanf(" %c", &b);
                if (b == 'a' || b == 'b') {
                    break;
                }
                else {
                    printf("Введен некорректный символ, введите еще раз: ");
                    while (getchar() != '\n');
                }
            }
            
            if(b=='a'){
                printf("Cумма элементов в четвертой области равна: %d\n", sum_matrix(numm, column, 1, numm, a));
            }
            if(b=='b'){
                printf("Cумма элементов в четвертой области равна: %d\n", sum_matrix(numm, column, 0, numm-1, a));
            }
        }
    return 0;
}
