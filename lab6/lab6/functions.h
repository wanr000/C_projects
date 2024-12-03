#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int isValidInput(const char *input){
    while (*input){
        if (!isdigit(*input)){
            return 0;
        }
        input++;
    }
    return 1;
}
int isValidInput_1(const char *input){
    while (*input){
        if (!isalpha(*input)){
            return 0;
        }
        input++;
    }
    return 1;
}

int start_1(char b){
    printf("Матрица заполняется случайными числами(a), вводимыми(b) или из файла(c): ");
    while (1) {
        char input[100];
//        scanf("%s", &input);
        // Указываем массив в который считывается строка, максимальное количество символов, поток из которого читаются данные
        fgets(input, sizeof(input), stdin);
        // Вместо символа новой строки, ставим символ конца строки
        input[strcspn(input, "\n")] = '\0';
        if (isValidInput_1(input) && (strcmp(input, "a") == 0 || strcmp(input, "b") == 0 || strcmp(input, "c") == 0)){
            sscanf(input, "%s", &b);
            break;
        }
        else{
            printf("Некорректный ввод. Попробуйте еще раз: ");
        }
    }
    return b;
}

int start_2(int numm){
    char input[100];
    printf("Введите количество элементов массива: ");
    while (1) {
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';
        if (isValidInput(input) && atoi(input) > 0){
            sscanf(input, "%d", &numm);
            break;
        }
        else{
            printf("Некорректный ввод. Попробуйте еще раз: ");
        }
    }
    return numm;
}

int start_22(int numm){
    char input[100];
    printf("Введите количество строк матрицы: ");
    while (1) {
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';
        if (isValidInput(input) && atoi(input) > 0){
            sscanf(input, "%d", &numm);
            break;
        }
        else{
            printf("Некорректный ввод. Попробуйте еще раз: ");
        }
    }
    return numm;
}

int start_23(int column){
    char input[100];
    printf("Введите количество столбцев матрицы: ");
    while (1) {
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';
        if (isValidInput(input) && atoi(input) > 0){
            sscanf(input, "%d", &column);
            break;
        }
        else{
            printf("Некорректный ввод. Попробуйте еще раз: ");
        }
    }
    return column;
}

void print_arr(int * a, int n){
    for(int i = 0; i < n; i++)
        printf("%d  ", a[i]);
    printf("\n");
}

void print_arr2(int n, int *m, double ** a){
    for(int i =0; i < n; i++){
        for(int j = 0; j < m[i]; j++){
            printf("%.1lf  ", a[i][j]);
        }
        printf("\n");
    }
}

void print_arr3(int n, int *m, int ** a){
    for(int i =0; i < n; i++){
        for(int j = 0; j < m[i]; j++){
            printf("%d  ", a[i][j]);
        }
        printf("\n");
    }
}

void bubble_sort(int * a, int size){
    int count = 0;
    for(int i=0; i<size;i++){
        if(a[i]<0 && a[i]%2!=0){
            count++;
        }
    }
    
    int index=0;
    int * new_a = (int*)malloc(count*sizeof(int));
    for(int i=0; i<size; i++){
        if(a[i]<0 && a[i]%2!=0){
            new_a[index] = a[i];
            index++;
        }
    }
    
    for(int i=0; i<count - 1; i++){
        for(int k=0; k<count - i - 1;k++){
            if(new_a[k] > new_a[k+1]){
                int temp = new_a[k];
                new_a[k] = new_a[k+1];
                new_a[k+1] = temp;
            }
        }
    }
    
    index=0;
    for(int i=0; i<size; i++){
        if(a[i] < 0 && a[i]%2 != 0){
            a[i] = new_a[index];
            index++;
        }
    }
    
    free(new_a);
}

