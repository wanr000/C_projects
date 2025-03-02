// 1 С клавиатуры заполнить файл символами. Вывести содержимое файла на экран.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"


void start(const char *filename){
    int x, n;
    
    char *str = NULL;
    size_t size = 0;

    printf("Введите строку: ");
    getline(&str, &size, stdin);
    
    // 1 Заполнение файла
    FILE *f = fopen(filename, "wt");

    fputs(str, f);
    fclose(f);
    
    
    // Чтение файла
    printf("\n1| Элементы в файле: ");
    f = fopen(filename, "rt");
    fgets(str, &size, f);
    printf("%s", str);
    fclose(f);

    
    // 2 Найти наиболее длинную последовательность повторяющихся символов.
    find_longest_sequence(str);
    
    
    // 3 Заменить все слова заданной длины пробелами.
    printf("\n3| Введите длину слов, которые нужно заменить пробелами: ");
    int word_length;
    scanf("%d", &word_length);
    replace_words_of_length(str, word_length);
    
    // Запись измененной строки обратно в файл
    f = fopen(filename, "wt");
    if (f == NULL) {
        perror("Ошибка открытия файла");
        free(str);
        return;
    }
    fputs(str, f);
    fclose(f);
    
    // Вывод измененного содержимого файла
    printf("3| Файл после замены всех слов длиной %d пробелами: ", word_length);
    f = fopen(filename, "rt");
    if (f == NULL) {
        perror("Ошибка открытия файла");
        free(str);
        return;
    }
    fgets(str, size, f);
    printf("%s\n", str);
    fclose(f);
    
    free(str);
    
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
            printf("1-Да\n2-Нет\n");
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

