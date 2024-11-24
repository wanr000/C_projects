#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "functions.h"

//// Задание 1
//int main(){
//    // Удалить целые числа в одномерном массиве
//    char b = start_1(b);
//    int n = start_2(n);
//    double * a = malloc(n * sizeof(double));
//    double a_1;
//    
//    if(b == 'a'){
//        FILE *file = fopen("array.txt", "w");
//        srand(time(NULL));
//        for(int k=0;k<n; k++){
//            int r = (0 + rand()%2);
//            if (r==1){
//                a[k]= (-20 + rand()%100);
//                fprintf(file, "%.2lf  ", a[k]);
//            }
//            else{
//                a[k]= (-20.3 + rand()%100);
//                fprintf(file, "%.2lf  ", a[k]);
//            }
//        }
//        fclose(file);
//        }
//    else if(b == 'b'){
//        // Задаем свои элементы массива
//        FILE *file = fopen("array.txt", "w");
//        int nms;
//        for(int k=0;k<n;k++){
//            while (1) {
//                nms = scanf("%lf", &a_1);
//                if (nms == 1) {
//                    break;
//                }
//                else {
//                    printf("Введен некорректный символ, введите еще раз: ");
//                    while (getchar() != '\n');
//                }
//            }
//            a[k] = a_1;
//            fprintf(file, "%.2lf  ", a[k]);
//            }
//            fclose(file);
//        }
//    else if(b == 'c'){
//        FILE *file = fopen("array.txt", "r");
//        for(int k=0;k<n; k++){
//            fscanf(file, "%lf", &a[k]);
//        }
//        fclose(file);
//    }
//    
//    printf("Исходный массив: ");
//    print_arr(a, n);
//    for (int i = 0; i < n; i++) {
//        if (a[i] == (int)a[i]) {
//            for (int j = i; j < n - 1; j++) {
//                a[j] = a[j + 1];
//            }
//            n--;
//            i--;
//        }
//    }
//    
//    printf("Измененный массив: ");
//    print_arr(a, n);
//    free(a);
//            
//    return 0;
//}

// Задание 2
int main(){
    // Удалить элементы на побочной диагонали в матрице
    char b = start_1(b);
    int n = start_22(n);
    int m = start_23(m);
    
    double ** array = (double**) malloc(sizeof(double*) * n);
    for (int i = 0; i < n; i++) {
        array [i] = (double*) malloc(sizeof(double) * m);
    }
    

    
    if(b == 'a'){
        FILE *file = fopen("array.txt", "w");
        srand(time(NULL));
        for(int k=0;k<n; k++){
            for(int j=0;j<m; j++){
                int r = (0 + rand()%2);
                if (r==1){
                    array[k][j] = (-20 + rand()%100);
                    fprintf(file, "%.2lf  ", array[k][j]);
                }
                else{
                    array[k][j]= (-20.3 + rand()%100);
                    fprintf(file, "%.2lf  ", array[k][j]);
                }
            }
            fprintf(file, "\n");
        }
        fclose(file);
    }
    else if(b == 'b'){
        // Задаем свои элементы массива
        FILE *file = fopen("array.txt", "w");
        int nms;
        for(int k=0;k<n;k++){
            for(int j=0;j<m;j++){
                while (1) {
                    nms = scanf("%lf", &array[k][j]);
                    if (nms == 1) {
                        break;
                    }
                    else {
                        printf("Введен некорректный символ, введите еще раз: ");
                        while (getchar() != '\n');
                    }
                }
                fprintf(file, "%.2lf  ", array[k][j]);
            }
            fprintf(file, "\n");
        }
        fclose(file);
    }
    else if(b == 'c'){
        FILE *file = fopen("array.txt", "r");
        for(int k=0;k<n; k++){
            for(int j=0;j<m; j++){
                fscanf(file, "%lf", &array[k][j]);
            }
            fprintf(file, "\n");
        }
        fclose(file);
    }
    
    printf("Исходный массив: \n");
    print_arr2(n, m, array);
    
    
    
    for(int i = 0; i < n; i++) {
        free(array[i]);
    }
    free(array);
    
    return 0;
}
