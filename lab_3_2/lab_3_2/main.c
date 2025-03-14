#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Структура для жанра фильма
typedef struct {
    char genre[20]; // Жанр фильма (строка фиксированной длины)
} Genre;

// Структура для фильма
typedef struct {
    int duration;       // Длительность фильма в минутах
    char *title;        // Название фильма (указатель на строку)
    Genre genre;        // Жанр фильма (вложенная структура)
    int year;           // Год выпуска фильма
} Movie;

// Функция для определения знака числа без сравнения с 0
void determine_sign() {
    int number;
    printf("Введите число: ");
    scanf("%d", &number);

    if ((number >> (sizeof(int) * 8 - 1)) & 1) {
        printf("Число отрицательное.\n");
    } else {
        printf("Число положительное.\n");
    }
}

// Функция для ввода данных о фильме
void input_movie(Movie *movie) {
    printf("Введите длительность фильма (в минутах): ");
    scanf("%d", &movie->duration);
    getchar(); // Очистка буфера после scanf

    printf("Введите название фильма: ");
    char buffer[100];
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0'; // Удаление символа новой строки
    movie->title = (char *)malloc((strlen(buffer) + 1) * sizeof(char));
    if (movie->title == NULL) {
        printf("Ошибка выделения памяти!\n");
        exit(1);
    }
    strcpy(movie->title, buffer);

    printf("Введите жанр фильма: ");
    fgets(movie->genre.genre, sizeof(movie->genre.genre), stdin);
    movie->genre.genre[strcspn(movie->genre.genre, "\n")] = '\0'; // Удаление символа новой строки

    printf("Введите год выпуска фильма: ");
    scanf("%d", &movie->year);
    getchar(); // Очистка буфера после scanf
}

// Функция для вывода данных о фильме
void print_movie(const Movie *movie) {
    printf("Название: %s\n", movie->title);
    printf("Длительность: %d минут\n", movie->duration);
    printf("Жанр: %s\n", movie->genre.genre);
    printf("Год выпуска: %d\n", movie->year);
}

// Функция для поиска фильмов по названию
void find_movies_by_title(Movie *movies, int count, const char *title) {
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(movies[i].title, title) == 0) {
            printf("Найден фильм:\n");
            print_movie(&movies[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("Фильмы с названием '%s' не найдены.\n", title);
    }
}

// Функция для удаления фильмов с длительностью больше заданной
void delete_movies_by_duration(Movie *movies, int *count, int max_duration) {
    int deleted = 0;
    for (int i = 0; i < *count; i++) {
        if (movies[i].duration > max_duration) {
            free(movies[i].title); // Освобождаем память, выделенную под название
            for (int j = i; j < *count - 1; j++) {
                movies[j] = movies[j + 1];
            }
            (*count)--;
            i--;
            deleted++;
        }
    }
    printf("Удалено %d фильмов.\n", deleted);
}

// Основная функция
int main() {
    int choice;
    printf("Выберите задание (1 или 2): ");
    scanf("%d", &choice);
    getchar(); // Очистка буфера после scanf

    if (choice == 1) {
        // Задание 1: Определение знака числа
        determine_sign();
    } else if (choice == 2) {
        // Задание 2: Работа с фильмами
        int count;
        printf("Введите количество фильмов: ");
        scanf("%d", &count);
        getchar(); // Очистка буфера после scanf

        Movie *movies = (Movie *)malloc(count * sizeof(Movie));
        if (movies == NULL) {
            printf("Ошибка выделения памяти!\n");
            return 1;
        }

        // Ввод данных о фильмах
        for (int i = 0; i < count; i++) {
            printf("\nВвод данных для фильма %d:\n", i + 1);
            input_movie(&movies[i]);
        }

        // Меню для работы с фильмами
        int action;
        do {
            printf("\nМеню:\n");
            printf("1. Вывести все фильмы\n");
            printf("2. Найти фильмы по названию\n");
            printf("3. Удалить фильмы с длительностью больше заданной\n");
            printf("4. Выйти\n");
            printf("Выберите действие: ");
            scanf("%d", &action);
            getchar(); // Очистка буфера после scanf

            switch (action) {
                case 1: {
                    for (int i = 0; i < count; i++) {
                        printf("\nДанные о фильме %d:\n", i + 1);
                        print_movie(&movies[i]);
                    }
                    break;
                }
                case 2: {
                    char title[100];
                    printf("Введите название фильма для поиска: ");
                    fgets(title, sizeof(title), stdin);
                    title[strcspn(title, "\n")] = '\0'; // Удаление символа новой строки
                    find_movies_by_title(movies, count, title);
                    break;
                }
                case 3: {
                    int max_duration;
                    printf("Введите максимальную длительность для удаления: ");
                    scanf("%d", &max_duration);
                    getchar(); // Очистка буфера после scanf
                    delete_movies_by_duration(movies, &count, max_duration);
                    break;
                }
                case 4: {
                    printf("Выход из программы.\n");
                    break;
                }
                default: {
                    printf("Неверный выбор. Попробуйте снова.\n");
                    break;
                }
            }
        } while (action != 4);

        // Освобождение памяти
        for (int i = 0; i < count; i++) {
            free(movies[i].title);
        }
        free(movies);
    } else {
        printf("Неверный выбор задания.\n");
    }

    return 0;
}
