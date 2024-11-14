#include <stdio.h>
#include <stdlib.h>

void print_arr(int a[], int n)
{
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}


int main(){
    int n;
    printf("Введите n количество элеметов массива: ");
    scanf("%d", &n);                        // прочитали n
    int * a = malloc(n * sizeof(int));      /* сами выделили динамическую                                           /*для*/
                                            // для n * sizeof(int) байт,
                                            // на эту память указывает переменная a
    
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    
    printf("%d\n", a[1]);
    print_arr(a, n);

    free(a);
    
    return 0;
}
