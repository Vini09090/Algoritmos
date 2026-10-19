#include <stdio.h>
#include <string.h>

#define Tam_Palavra 50
#define Tam_classe 10
#define caminho 80
#define linha 8    // de 0 a 7 (8 linhas)
#define coluna 1
// gcc fist.c -o fist

/* A tradução de uma palavra começa com a palavra, 
    depois a classe e por último seria a palavra em português. 
   */ 


// Estrutura base :
struct estrutura
{
    char palavra[Tam_Palavra];
    char classe [Tam_classe];
    char traducao[Tam_Palavra];
};
// 1- 2- 3- 4- 5- 6- 7- 8- 

/* Preenche a matriz com os caracteres da palavra (uma letra por linha).
   Retorna a quantidade de linhas realmente usadas. */


int montar_matriz(const char *palavra, char matriz[linha][coluna]) {
    int i, j;
    int tamanho = strlen(palavra);
    int usadas = (tamanho < linha) ? tamanho : linha;

    for (i = 0; i < linha; i++) {
        for (j = 0; j < coluna; j++) {
            if (i < usadas) {
                matriz[i][j] = palavra[i];
            } else {
                matriz[i][j] = '\0';   // posição vazia, sem lixo de memória
            }
        }
    }

    return usadas;
}

/* Mostra só as linhas que têm letra. */
void mostrar_matriz(char matriz[linha][coluna], int usadas) {
    int i, j;

    printf("\nMatriz (%d caracteres):\n", usadas);
    for (i = 0; i < usadas; i++) {
        for (j = 0; j < coluna; j++) {
            printf("[%d][%d] = '%c'\n", i, j, matriz[i][j]);
        }
    }
}

int main() {
    char matriz[linha][coluna];
    char palavra[Tam_Palavra] = {0};

    // Recebendo a palavra: 

    printf("\n Palavra em inglês: \n");
    scanf("%49s", palavra);

    int usadas = montar_matriz(palavra, matriz);

    if ((int)strlen(palavra) > linha) {
        printf("\nAviso: a palavra tem %d letras e a matriz só comporta %d. As demais foram ignoradas.\n",
               (int)strlen(palavra), linha);
    }

    mostrar_matriz(matriz, usadas);

    return 0;
}
