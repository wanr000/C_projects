#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"


void start(const char *filename){
    char *str = NULL;
    size_t size = 0;

    // 1 С клавиатуры заполнить файл символами. Вывести содержимое файла на экран.
    // Запись в файл
    fill_file_from_input(filename);
        
    // Чтение файла
    print_file_content(filename);
    

    // 2 Найти наиболее длинную последовательность повторяющихся символов.
    find_and_print_longest_sequence(filename);
    
    
    // 3 Заменить все слова заданной длины пробелами.
    printf("\n3| Введите длину слов, которые нужно заменить пробелами: ");
    int word_length;
    word_length = correct_choice(word_length);
    replace_words_and_save(filename, word_length);
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

