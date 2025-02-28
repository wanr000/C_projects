// 1 С клавиатуры заполнить файл целыми числами
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"


void start(const char *filename){
    int x, n;
    
    // Количество элементов в файле
    printf("Введите количество целых чисел содержащихся в бинарном файле: ");
    n = correct_choice(n);
    printf("\n");
    
    
    // 1 Заполнение файла
    FILE *f = fopen(filename, "wt");
    for(int k=0;k<n;k++){
        while (1) {
            char b;
            if(scanf("%d%c",&x, &b) == 2 && b=='\n'){
                break;
            }
            else {
                printf("Некорректный ввод. Повторите еще раз: ");
                while (getchar() != '\n');
            }
        }
        fwrite(&x, sizeof(x), 1, f);
    }
    fclose(f);
    
    
    // Чтение файла
    printf("\n1| Элементы в файле: ");
    int min=0, max=0, sum_nx;
    
    f = fopen(filename, "rt");
    fread(&min, sizeof(x), 1, f);
    // Перемещение курсора в начало файла
    fseek(f, 0, SEEK_SET);
    
    for(int k=0;k<n;k++){
        fread(&x, sizeof(x), 1, f);
        printf("%d ", x);
        if (x > max){
            max = x;
        }
        if (x < min){
            min = x;
        }
    }
    printf("\n");
    fclose(f);

    
    // 2 Найти сумму минимального и максимального элементов
    sum_nx = max + min;
    printf("2| Сумма минимального и максимально элемента в бинарном файле: %d", sum_nx);
    
    
    // 3 Занулить элементы по принципу
    printf("\n3| Файл после зануления элементов: ");
    int count, not_zeros = 0;
    f = fopen(filename, "rt+");
    for(int k=0;k<n;k++){
        long int pos = ftell(f); // Сохраняем текущую позицию
        fread(&x, sizeof(x), 1, f);
        if (k==0){
            count = x;
            x = 0;
            fseek(f, pos, SEEK_SET);
            fwrite(&x, sizeof(x), 1, f);
        }
        if (k==count){
            count = x + k;
            x=0;
            fseek(f, pos, SEEK_SET);
            fwrite(&x, sizeof(x), 1, f);
        }
    }
    
    fseek(f, 0, SEEK_SET);
    for(int k=0;k<n;k++){
        fread(&x, sizeof(x), 1, f);
        printf("%d ", x);
    }
    printf("\n");
    fclose(f);
    
    
    // 4 Удалить все нули
    f = fopen(filename, "rt+");
    FILE *temp = fopen("temp.txt", "wt");
    while (fread(&x, sizeof(x), 1, f)) {
        if (x != 0) {
            fwrite(&x, sizeof(x), 1, temp);
            not_zeros++;
        }
    }
    fclose(f);
    fclose(temp);
    
    temp = fopen("temp.txt", "rt");
    f = fopen(filename, "w+t");
    while (fread(&x, sizeof(x), 1, temp)) {
        if (x != 0) {
            fwrite(&x, sizeof(x), 1, f);
        }
    }
    fclose(temp);
    
    printf("4| Файл после удаления нулей: ");
    fseek(f, 0, SEEK_SET);
    for(int k=0;k<not_zeros;k++){
        fread(&x, sizeof(x), 1, f);
        printf("%d ", x);
    }

    printf("\n");
    fclose(f);
}


int main(int argc, char *argv[]){
    if (argc < 2) {
         printf("Необходимо указать имя файла.\n");
         return 1;
     }
    
    int n=2;
    while (1) {
        if(n==2){
            start(argv[1]);
            printf("\nЗакрыть программу?\n");
            printf("1-Да👍\n2-Нет☠️\n");
            n = correct_choice(n);
        }
        if (n == 1){
            return 0;
        }
        if (n == 2){
            continue;
        }
        else{
            printf("Данного варианта ответа не существует. Повторите ввод: ");
            n = correct_choice(n);
        }
    }
    
    return 0;
}
