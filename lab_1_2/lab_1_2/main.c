// С клавиатуры заполнить файл целыми числами
#include <stdio.h>

int main(void){
    int x;
    scanf("%d", &x);
    FILE *f = fopen("file.txt", "wb");
    fwrite(&x, sizeof(x), 1, f);
    fclose(f);
    
    
    f = fopen("file.txt", "rb");
    
    fread(&x, sizeof(x), 1, f);
    fclose(f);
    
    printf("Считано из файла: %d\n", x);
    
    return 0;
}
