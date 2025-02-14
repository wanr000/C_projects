// С клавиатуры заполнить файл целыми числами
#include <stdio.h>
#include "functions.h"


void start(void){
    int x, n;
    
    // Имя файла
    printf("Введите имя создаваемого бинарного файла: ");
    
    
    
    // Количество элементов в файле
    printf("\nВведите количество элементов содержащихся в бинарном файле: ");
    n = correct_choice(n);
    
    
    // Заполнение файла
    FILE *f = fopen("/Users/roman/Projects/C /lab_4/lab_1_2/lab_1_2/file.txt", "wb");
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
    f = fopen("/Users/roman/Projects/C /lab_4/lab_1_2/lab_1_2/file.txt", "rb");
    for(int k=0;k<n;k++){
        fread(&x, sizeof(x), 1, f);
        printf("%d ", x);
    }
    printf("\n");
    fclose(f);
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
