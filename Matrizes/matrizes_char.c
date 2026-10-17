#include <stdio.h>

int main() {
    char matriz[3][1];
    int i, j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 1; j++) {
            printf("Digite o caractere [%d][%d]: ", i, j);
            scanf(" %c", &matriz[i][j]);   // espaço antes do %c é essencial
        }
    }

    printf("\nMatriz:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 1; j++) {
            printf("%c\t", matriz[i][j]);
        }
        printf("\n");
    }


    return 0;
}
