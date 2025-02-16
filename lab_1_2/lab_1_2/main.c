// 1 С клавиатуры заполнить файл целыми числами
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"


void start(void){
    int x, n;
    
    // Имя файла
    char *name = "/Users/roman/Projects/C /lab_4/lab_1_2/lab_1_2/.txt";
    char *filename = NULL;
    size_t size = 0;
    printf("Введите имя бинарного файла: ");
    getline(&filename, &size, stdin);
    
    // Удаление символа новой строки строк
        if (name[strlen(name) - 1] == '\n') {
            name[strlen(name) - 1] = '\0';
        }
        if (filename[strlen(filename) - 1] == '\n') {
            filename[strlen(filename) - 1] = '\0';
        }
    
    char *result = NULL;
    int a=47, b=255;
    // Дополнение расположения файла
    insert_chars(filename, name , &result, a, b);
    free(filename);

    
    // Количество элементов в файле
    printf("Введите количество целых чисел содержащихся в бинарном файле: ");
    n = correct_choice(n);
    printf("\n");
    
    
    // Заполнение файла
    FILE *f = fopen(result, "wb");
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
    
    f = fopen(result, "rb");
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
    
    
    // Занулить элементы по принципу
    printf("\n3| Файл после зануления элементов: ");
    int count, not_zeros = 0;
    f = fopen(result, "rb+");
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
    
    
    // Удалить все нули
    f = fopen(result, "rb+");
    FILE *temp = fopen("temp.txt", "wb");
    while (fread(&x, sizeof(x), 1, f)) {
        if (x != 0) {
            fwrite(&x, sizeof(x), 1, temp);
            not_zeros++;
        }
    }
    fclose(f);
    fclose(temp);
    
    temp = fopen("temp.txt", "rb");
    f = fopen(result, "w+b");
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
    free(result);
}


int main(void){
    int n=2;
    while (1) {
        if(n==2){
            start();
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
