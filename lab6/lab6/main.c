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
//    int * a = malloc(n * sizeof(int));
//    int a_1;
//
//    if(b == 'a'){
//        FILE *file = fopen("array.txt", "w");
//        srand(time(NULL));
//        for(int k=0;k<n; k++){
//            a[k]= (-50 + rand()%100);
//            fprintf(file, "%d  ", a[k]);
//        }
//        fclose(file);
//    }
//    else if(b == 'b'){
//        FILE *file = fopen("array.txt", "w");
//        int nms;
//        for(int k=0;k<n;k++){
//            while (1) {
//                nms = scanf("%d", &a_1);
//                if (nms == 1) {
//                    break;
//                }
//                else {
//                    printf("Введен некорректный символ, введите еще раз: ");
//                    while (getchar() != '\n');
//                }
//            }
//            a[k] = a_1;
//            fprintf(file, "%d  ", a[k]);
//            }
//            fclose(file);
//    }
//    else if(b == 'c'){
//        FILE *file = fopen("array.txt", "r");
//        for(int k=0;k<n; k++){
//            fscanf(file, "%d", &a[k]);
//        }
//        fclose(file);
//    }
//
//    printf("Исходный массив: ");
//    print_arr(a, n);
//
//    bubble_sort(a, n);
//
//    printf("Измененный массив: ");
//    print_arr(a, n);
//    free(a);
//
//    return 0;
//}



// Задание 2
int main(){
    char b = start_1(b);
    int n = start_22(n);
    int m = start_23(m);
    
    int ** array = (int**) calloc(n, sizeof(int*));
    int * cols = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        array[i] = (int*) calloc(m, sizeof(int));
        cols[i] = m;
    }
    

    if(b == 'a'){
        FILE *file = fopen("array.txt", "w");
        srand(time(NULL));
        for(int k=0;k<n; k++){
            for(int j=0;j<m; j++){
                array[k][j] = (-20 + rand()%100);
                fprintf(file, "%d  ", array[k][j]);
                array[k][m-1]=-100;
            }
            fprintf(file, "\n");
        }
        fclose(file);
    }
    else if(b == 'b'){
        FILE *file = fopen("array.txt", "w");
        int nms;
        for(int k=0;k<n;k++){
            for(int j=0;j<m;j++){
                while (1) {
                    nms = scanf("%d", &array[k][j]);
                    if (nms == 1) {
                        break;
                    }
                    else {
                        printf("Введен некорректный символ, введите еще раз: ");
                        while (getchar() != '\n');
                    }
                }
                array[k][m-1]=-100;
                fprintf(file, "%d  ", array[k][j]);
            }
            fprintf(file, "\n");
        }
        fclose(file);
    }
    else if(b == 'c'){
        FILE *file = fopen("array.txt", "r");
        for(int k=0;k<n; k++){
            for(int j=0;j<m; j++){
                fscanf(file, "%d", &array[k][j]);
                array[k][m-1]=-100;
            }
            fprintf(file, "\n");
        }
        fclose(file);
    }
    
    printf("Исходный массив: \n");
    print_arr3(n, cols, array);
    
    

    printf("\nИзмененный массив: \n");
    print_arr3(n, cols, array);
    
    for(int i = 0; i < n; i++) {
        free(array[i]);
    }
    free(array);
    free(cols);
    
    return 0;
}

