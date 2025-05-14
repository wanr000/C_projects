#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define TABLE_SIZE 100
#define DEBUG_MODE 1  // 1 - вывод дополнительной информации, 0 - только сумма

// Хэш-функция
uint32_t simple_hash(const char *str) {
    uint32_t hash = 5381;
    int c;
    
    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }
    
    return hash;
}

// Структура пользователя
typedef struct User {
    char login[50];
    uint32_t login_hash;
    uint32_t password_hash;
    uint32_t combined_hash; // Новое поле для суммы хэшей
    struct User* next;
} User;

User* user_table[TABLE_SIZE];

// Инициализация таблицы
void init_table() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        user_table[i] = NULL;
    }
}

// Добавление пользователя
void add_user(const char* login, uint32_t pwd_hash) {
    uint32_t index = simple_hash(login) % TABLE_SIZE;
    
    User* new_user = (User*)malloc(sizeof(User));
    strncpy(new_user->login, login, 49);
    new_user->login[49] = '\0';
    new_user->login_hash = simple_hash(login);
    new_user->password_hash = pwd_hash;
    new_user->combined_hash = new_user->login_hash + new_user->password_hash; // Сумма хэшей
    new_user->next = NULL;
    
    if (user_table[index] == NULL) {
        user_table[index] = new_user;
    } else {
        User* current = user_table[index];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_user;
    }

    #if DEBUG_MODE
    printf("Добавлен пользователь:\n");
    printf("Логин: %s\n", login);
    #endif
    printf("Хэш-сумма логина и пароля: %u\n\n", new_user->combined_hash);
}

// Поиск пользователя
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

// Регистрация
void register_user() {
    char login[50];
    char password[50];
    
    printf("\n--- Регистрация ---\n");
    printf("Введите логин: ");
    scanf("%49s", login);
    
    if (find_user(login) != NULL) {
        printf("Ошибка: логин уже занят!\n");
        return;
    }
    
    printf("Введите пароль: ");
    scanf("%49s", password);
    
    uint32_t pwd_hash = simple_hash(password);
    add_user(login, pwd_hash);
    printf("Регистрация завершена!\n");
}

// Авторизация
void authenticate() {
    char login[50];
    char password[50];
    
    printf("\n--- Авторизация ---\n");
    printf("Введите логин: ");
    scanf("%49s", login);
    
    User* user = find_user(login);
    if (user == NULL) {
        printf("Ошибка: пользователь не найден!\n");
        return;
    }
    
    printf("Введите пароль: ");
    scanf("%49s", password);
    
    uint32_t input_login_hash = simple_hash(login);
    uint32_t input_pwd_hash = simple_hash(password);
    uint32_t input_combined_hash = input_login_hash + input_pwd_hash;
    
    #if DEBUG_MODE
    printf("\nОтладочная информация:\n");
    #endif
    printf("Хэш-сумма логина и пароля: %u\n", input_combined_hash);
    printf("Ожидаемая сумма: %u\n", user->combined_hash);
    
    if (user->password_hash == input_pwd_hash) {
        printf("\nУспешная авторизация! Добро пожаловать, %s!\n", user->login);
    } else {
        printf("\nОшибка: неверный пароль!\n");
    }
}

// Просмотр всех пользователей (для отладки)
void show_all_users() {
    printf("\n--- Список пользователей ---\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        User* current = user_table[i];
        while (current != NULL) {
            printf("Логин: %s\n", current->login);
            #if DEBUG_MODE
            #endif
            printf("Хэш-сумма логина и пароля: %u\n", current->combined_hash);
            printf("-----------------\n");
            current = current->next;
        }
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
        printf("\n=== Меню ===\n");
        printf("1. Регистрация\n");
        printf("2. Авторизация\n");
        printf("3. Показать всех пользователей (отладка)\n");
        printf("4. Выход\n");
        printf("Выберите: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                register_user();
                break;
            case 2:
                authenticate();
                break;
            case 3:
                show_all_users();
                break;
            case 4:
                printf("Завершение работы...\n");
                break;
            default:
                printf("Неверный выбор!\n");
        }
    } while (choice != 4);
    
    free_table();
    return 0;
}
