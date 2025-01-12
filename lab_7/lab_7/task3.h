// Отсортировать методом Хоара массив строк по убыванию длины строки
void task3(void){
    int n;
    printf("Введите количество строк: ");
    char t;
    while (1) {
        if ((scanf("%d%c", &n, &t)==2) && t=='\n'){
            break;
        }
        else{
            printf("Некорректный ввод. Попробуйте еще раз: ");
            while (getchar() != '\n');
        }
    }

    char **arr = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        arr[i] = (char *)malloc(100 * sizeof(char));
        printf("Введите строку %d: ", i + 1);
        scanf("%s", arr[i]);
    }

    quicksort(arr, 0, n - 1, compare_length);

    printf("Отсортированные строки по убыванию длины:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", arr[i]);
        free(arr[i]);
    }
    free(arr);
}
