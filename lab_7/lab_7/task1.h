// Дана строка. Удалить из нее все лишние пробелы. Между словами оставить только по одному пробелу
void task1(void){
    char *str = NULL;
    size_t size = 0;

    printf("Введите строку: ");
    getline(&str, &size, stdin);

    char *result = NULL;

    printf("Исходная строка: \"%s\"\n", str);
    
    remove_spaces(str, &result);
    printf("Обработанная строка: \"%s\"\n", result);

    free(result);
    free(str);
}
