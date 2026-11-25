#include <stdio.h>
#include <string.h>


int main(){

    FILE *arquivo; // espaço disponível para a memória.

    char buffer[1024]; // quantidade de caracteres presentes nesse array.
    char mensagem[1024] , adiçao[1024]; // Mensagem: parte do arquivo,  resposta nova mensagem a ser escrita
    
    arquivo = fopen("teste.txt", "a");

    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo.\n");
        return 1;
    }
    // Ler a mensagem e copia o texto em uma outra variável
    while (fgets(buffer, sizeof(buffer), arquivo) != NULL) {

        strcpy(mensagem, buffer); // copia o buffer na variável mensagem

        printf("Mensagem armazenada: %s", mensagem);
        //strcmp(mensagem, mensagem1); // comparação de strings

    }
    // adição de um texto : 
    printf("%s","\n Digite a informação que deseja acrescentar : \n");
    scanf("%s" , &adiçao);

    // Adição no arquivo presente.
    fprintf(arquivo , adiçao);
    fclose(arquivo);

    return 0;
}

