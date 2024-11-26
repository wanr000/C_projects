#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "functions.h"

//// Задание 1
//int main(){
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
//    }
//    else if(b == 'b'){
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
//    }
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


//// Задание 2
//int main(){
//    char b = start_1(b);
//    int n = start_22(n);
//    int m = start_23(m);
//
//    double **array = (double **)calloc(n, sizeof(double *));
//    int *cols = (int *)malloc(n * sizeof(int));
//    for (int i = 0; i < n; i++) {
//        array[i] = (double *)calloc(m, sizeof(double));
//        cols[i] = m;
//    }
//
//    if (b == 'a') {
//        FILE *file = fopen("array.txt", "w");
//        srand(time(NULL));
//        for (int k = 0; k < n; k++) {
//            for (int j = 0; j < m; j++) {
//                int r = rand() % 2;
//                if (r == 1) {
//                    array[k][j] = -20 + rand() % 100;
//                    fprintf(file, "%.2lf  ", array[k][j]);
//                } else {
//                    array[k][j] = -20.3 + rand() % 100;
//                    fprintf(file, "%.2lf  ", array[k][j]);
//                }
//            }
//            fprintf(file, "\n");
//        }
//        fclose(file);
//    }
//    else if (b == 'b') {
//        FILE *file = fopen("array.txt", "w");
//        for (int k = 0; k < n; k++) {
//            for (int j = 0; j < m; j++) {
//                while (scanf("%lf", &array[k][j]) != 1) {
//                    printf("Введен некорректный символ, введите еще раз: ");
//                    while (getchar() != '\n');
//                }
//                fprintf(file, "%.2lf  ", array[k][j]);
//            }
//            fprintf(file, "\n");
//        }
//        fclose(file);
//    }
//    else if (b == 'c') {
//        FILE *file = fopen("array.txt", "r");
//        for (int k = 0; k < n; k++) {
//            for (int j = 0; j < m; j++) {
//                fscanf(file, "%lf", &array[k][j]);
//            }
//        }
//        fclose(file);
//    }
//
//    printf("Исходный массив:\n");
//    print_arr2(n, cols, array);
//
//    for (int i = 0; i < n; i++) {
//        int diagIndex = m - 1 - i;
//        if (diagIndex >= 0 && diagIndex < m) {
//            for (int j = diagIndex; j < cols[i] - 1; j++) {
//                array[i][j] = array[i][j + 1];
//            }
//            cols[i]--;
//            array[i] = (double *)realloc(array[i], cols[i] * sizeof(double));
//        }
//    }
//
//    printf("\nИзмененный массив:\n");
//    print_arr2(n, cols, array);
//
//    for (int i = 0; i < n; i++) {
//        free(array[i]);
//    }
//    free(array);
//    free(cols);
//
//    return 0;
//}



//// Задание 3
//int main(){
//    char b = start_1(b);
//    int n = start_22(n);
//    int m = start_23(m);
//    
//    int ** array = (int**) calloc(n, sizeof(int*));
//    int * cols = (int*)malloc(n * sizeof(int));
//    for (int i = 0; i < n; i++) {
//        array[i] = (int*) calloc(m, sizeof(int));
//        cols[i] = m;
//    }
//    
//
//    if(b == 'a'){
//        FILE *file = fopen("array.txt", "w");
//        srand(time(NULL));
//        for(int k=0;k<n; k++){
//            for(int j=0;j<m; j++){
//                array[k][j] = (-20 + rand()%100);
//                fprintf(file, "%d  ", array[k][j]);
//                array[k][m-1]=-100;
//            }
//            fprintf(file, "\n");
//        }
//        fclose(file);
//    }
//    else if(b == 'b'){
//        FILE *file = fopen("array.txt", "w");
//        int nms;
//        for(int k=0;k<n;k++){
//            for(int j=0;j<m;j++){
//                while (1) {
//                    nms = scanf("%d", &array[k][j]);
//                    if (nms == 1) {
//                        break;
//                    }
//                    else {
//                        printf("Введен некорректный символ, введите еще раз: ");
//                        while (getchar() != '\n');
//                    }
//                }
//                array[k][m-1]=-100;
//                fprintf(file, "%d  ", array[k][j]);
//            }
//            fprintf(file, "\n");
//        }
//        fclose(file);
//    }
//    else if(b == 'c'){
//        FILE *file = fopen("array.txt", "r");
//        for(int k=0;k<n; k++){
//            for(int j=0;j<m; j++){
//                fscanf(file, "%d", &array[k][j]);
//                array[k][m-1]=-100;
//            }
//            fprintf(file, "\n");
//        }
//        fclose(file);
//    }
//    
//    printf("Исходный массив: \n");
//    print_arr3(n, cols, array);
//    
//    
//    for(int i = 0; i < n; i++) {
//        if((i+1)%2==0){
//            for(int j = 0; j < cols[i]; j++){
//                if(array[i][j]%2!=0){
//                    cols[i]++;
//                    array[i] = (int *)realloc(array[i], cols[i] * sizeof(int));
//                    
//                    for(int k=cols[i]-1; k > j; k--){
//                        array[i][k] = array[i][k-1];
//                    }
//                    
//                    array[i][j+1] = array[i][j];
//                    j++;
//                }
//            }
//        }
//    }
//
//    
//    printf("\nИзмененный массив: \n");
//    print_arr3(n, cols, array);
//    
//    for(int i = 0; i < n; i++) {
//        free(array[i]);
//    }
//    free(array);
//    free(cols);
//    
//    return 0;
//}
