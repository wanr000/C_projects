#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define TABLE_SIZE 100

// Простая хэш-функция (для примера)
uint32_t simple_hash(const char *str) {
    uint32_t hash = 5381;
    int c;
    
    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }
    
    return hash;
}

// Структура для хранения данных пользователя
typedef struct User {
    char login[50];
    uint32_t password_hash;
    struct User* next; // Для разрешения коллизий методом цепочек
} User;

// Хеш-таблица пользователей
User* user_table[TABLE_SIZE];

// Инициализация хеш-таблицы
void init_table() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        user_table[i] = NULL;
    }
}

// Добавление пользователя в хеш-таблицу
void add_user(const char* login, uint32_t password_hash) {
    uint32_t index = simple_hash(login) % TABLE_SIZE;
    
    User* new_user = (User*)malloc(sizeof(User));
    strncpy(new_user->login, login, 49);
    new_user->login[49] = '\0';
    new_user->password_hash = password_hash;
    new_user->next = NULL;
    
    // Если ячейка пуста
    if (user_table[index] == NULL) {
        user_table[index] = new_user;
    } else {
        // Разрешение коллизий методом цепочек
        User* current = user_table[index];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_user;
    }
}

// Поиск пользователя по логину
User* find_user(const char* login) {
    uint32_t index = simple_hash(login) % TABLE_SIZE;
    User* current = user_table[index];
    
    while (current != NULL) {
        if (strcmp(current->login, login) == 0) {
            return current;
        }
        current = current->next;
    }
    
    return NULL;
}

// Функция регистрации нового пользователя
void register_user() {
    char login[50];
    char password[50];
    
    printf("Регистрация нового пользователя\n");
    printf("Введите логин: ");
    scanf("%49s", login);
    
    // Проверка, не занят ли логин
    if (find_user(login) != NULL) {
        printf("Ошибка: пользователь с таким логином уже существует!\n");
        return;
    }
    
    printf("Введите пароль: ");
    scanf("%49s", password);
    
    // Добавляем пользователя в таблицу
    add_user(login, simple_hash(password));
    
    printf("Пользователь зарегистрирован!\n\n");
}

// Функция авторизации пользователя
void authenticate() {
    char login[50];
    char password[50];
    
    printf("Авторизация\n");
    printf("Введите логин: ");
    scanf("%49s", login);
    
    printf("Введите пароль: ");
    scanf("%49s", password);
    
    User* user = find_user(login);
    if (user == NULL) {
        printf("Ошибка авторизации: пользователь не найден\n");
        return;
    }
    
    if (user->password_hash == simple_hash(password)) {
        printf("Авторизация успешна! Добро пожаловать, %s!\n", user->login);
    } else {
        printf("Ошибка авторизации: неверный пароль\n");
    }
}

// Освобождение памяти
void free_table() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        User* current = user_table[i];
        while (current != NULL) {
            User* temp = current;
            current = current->next;
            free(temp);
        }
    }
}

int main() {
    init_table();
    int choice;
    
    do {
        printf("\n1. Регистрация\n");
        printf("2. Авторизация\n");
        printf("3. Выход\n");
        printf("Выберите действие: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                register_user();
                break;
            case 2:
                authenticate();
                break;
            case 3:
                printf("Выход из программы\n");
                break;
            default:
                printf("Неверный выбор\n");
        }
    } while (choice != 3);
    
    free_table();
    return 0;
}
