#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
 * Estrutura que representa um vetor dinamico de palavras.
 * quantidade: numero de palavras armazenadas.
 * capacidade: numero de posicoes atualmente reservadas.
 */
typedef struct {
    char **itens;
    size_t quantidade;
    size_t capacidade;
} VetorPalavras;


/* Conta as linhas, incluindo a ultima linha sem '\n'. */
int contar_linhas(const char nome[]) {
    FILE *arquivo = fopen(nome, "r");

    if (arquivo == NULL) {
        perror("Erro ao abrir arquivo");
        return -1;
    }

    int caractere;
    int linhas = 0;
    int tem_conteudo = 0;
    int ultimo_caractere = '\0';

    while ((caractere = fgetc(arquivo)) != EOF) {
        tem_conteudo = 1;
        ultimo_caractere = caractere;

        if (caractere == '\n') {
            linhas++;
        }
    }

    if (ferror(arquivo)) {
        fclose(arquivo);
        return -1;
    }

    if (tem_conteudo && ultimo_caractere != '\n') {
        linhas++;
    }

    fclose(arquivo);
    return linhas;
}


/* Retorna o maior comprimento de linha, em bytes. */
int total_colunas(const char nome[]) {
    FILE *arquivo = fopen(nome, "r");

    if (arquivo == NULL) {
        perror("Erro ao abrir arquivo");
        return -1;
    }

    int caractere;
    int colunas = 0;
    int maior_coluna = 0;

    while ((caractere = fgetc(arquivo)) != EOF) {
        if (caractere == '\n') {
            if (colunas > maior_coluna) {
                maior_coluna = colunas;
            }
            colunas = 0;
        } else {
            colunas++;
        }
    }

    if (ferror(arquivo)) {
        fclose(arquivo);
        return -1;
    }

    if (colunas > maior_coluna) {
        maior_coluna = colunas;
    }

    fclose(arquivo);
    return maior_coluna;
}


/* Inicializa o vetor sem reservar espaço antecipadamente. */
void inicializar_vetor(VetorPalavras *vetor) {
    vetor->itens = NULL;
    vetor->quantidade = 0;
    vetor->capacidade = 0;
}


/*
 * Adiciona uma copia da palavra ao vetor.
 * O vetor aumenta de capacidade quando fica cheio.
 */
int adicionar_palavra(VetorPalavras *vetor,
                      const char *inicio,
                      size_t tamanho) {
    if (tamanho == 0) {
        return 0;
    }

    if (vetor->quantidade == vetor->capacidade) {
        size_t nova_capacidade =
            (vetor->capacidade == 0) ? 8 : vetor->capacidade * 2;

        char **novo = realloc(
            vetor->itens,
            nova_capacidade * sizeof(*vetor->itens)
        );

        if (novo == NULL) {
            return -1;
        }

        vetor->itens = novo;
        vetor->capacidade = nova_capacidade;
    }

    char *palavra = malloc(tamanho + 1);

    if (palavra == NULL) {
        return -1;
    }

    memcpy(palavra, inicio, tamanho);
    palavra[tamanho] = '\0';

    vetor->itens[vetor->quantidade] = palavra;
    vetor->quantidade++;

    return 0;
}


/*
 * Considera separadores os espaços e sinais de pontuacao ASCII.
 * Os bytes de letras acentuadas em UTF-8 sao preservados.
 */
int eh_separador(unsigned char caractere) {
    if (isspace(caractere)) {
        return 1;
    }

    if (caractere < 128 && ispunct(caractere)) {
        return 1;
    }

    return 0;
}


/* Divide uma linha em palavras e adiciona cada palavra ao vetor. */
int tokenizar_linha(VetorPalavras *vetor, const char linha[]) {
    const char *inicio = NULL; 
    size_t tamanho = 0;

    for (size_t i = 0; ; i++) {
        unsigned char atual = (unsigned char)linha[i];

        if (atual == '\0' || eh_separador(atual)) {
            if (inicio != NULL) {
                if (adicionar_palavra(vetor, inicio, tamanho) != 0) {
                    return -1;
                }

                inicio = NULL;
                tamanho = 0;
            }

            if (atual == '\0') {
                break;
            }
        } else {
            if (inicio == NULL) {
                inicio = &linha[i];
                tamanho = 0;
            }

            tamanho++;
        }
    }

    return 0;
}


/* Le o arquivo linha por linha e cria o vetor de palavras. */
int ler_e_vetorizar(const char nome[], VetorPalavras *vetor) {
    FILE *arquivo = fopen(nome, "r");

    if (arquivo == NULL) {
        perror("Erro ao abrir arquivo");
        return -1;
    }

    char *linha = NULL;
    size_t capacidade_linha = 0;
    ssize_t tamanho_linha;

    while ((tamanho_linha = getline(&linha, &capacidade_linha, arquivo)) != -1) {
        (void)tamanho_linha;

        if (tokenizar_linha(vetor, linha) != 0) {
            free(linha);
            fclose(arquivo);
            return -1;
        }
    }

    free(linha);

    if (ferror(arquivo)) {
        fclose(arquivo);
        return -1;
    }

    fclose(arquivo);
    return 0;
}


/* Mostra todas as palavras na ordem em que foram encontradas. */
void mostrar_vetor(const VetorPalavras *vetor) {
    printf("\nPalavras encontradas:\n");

    for (size_t i = 0; i < vetor->quantidade; i++) {
        printf("[%zu] %s\n", i, vetor->itens[i]);
    }

    printf("\nTotal de palavras: %zu\n", vetor->quantidade);
}


/* Mostra cada palavra uma vez e informa sua frequencia. */
void mostrar_frequencias(const VetorPalavras *vetor) {
    printf("\nFrequencia dos termos:\n");

    for (size_t i = 0; i < vetor->quantidade; i++) {
        int ja_mostrada = 0;

        for (size_t anterior = 0; anterior < i; anterior++) {
            if (strcmp(vetor->itens[i], vetor->itens[anterior]) == 0) {
                ja_mostrada = 1;
                break;
            }
        }

        if (ja_mostrada) {
            continue;
        }

        size_t frequencia = 0;

        for (size_t j = 0; j < vetor->quantidade; j++) {
            if (strcmp(vetor->itens[i], vetor->itens[j]) == 0) {
                frequencia++;
            }
        }

        printf("%-20s %zu\n", vetor->itens[i], frequencia);
    }
}


/* Libera cada palavra e, depois, o vetor de ponteiros. */
void liberar_vetor(VetorPalavras *vetor) {
    for (size_t i = 0; i < vetor->quantidade; i++) {
        free(vetor->itens[i]);
    }

    free(vetor->itens);

    vetor->itens = NULL;
    vetor->quantidade = 0;
    vetor->capacidade = 0;
}


/*
 * Mantem a funcionalidade de mensagens do programa original:
 * mostra o conteudo e acrescenta uma nova mensagem ao arquivo.
 */
int mensagens(const char nome[], const char nova_mensagem[]) {
    FILE *arquivo = fopen(nome, "a+");

    if (arquivo == NULL) {
        perror("Erro ao abrir arquivo");
        return -1;
    }

    rewind(arquivo);

    char texto[1024];

    printf("\nMensagens existentes:\n");

    while (fgets(texto, sizeof(texto), arquivo) != NULL) {
        texto[strcspn(texto, "\r\n")] = '\0';

        if (strcmp(texto, "diga ao povo que eu fico!!") == 0) {
            fclose(arquivo);
            return 1;
        }

        printf("%s\n", texto);
    }

    if (ferror(arquivo)) {
        fclose(arquivo);
        return -1;
    }

    if (fseek(arquivo, 0, SEEK_END) != 0) {
        fclose(arquivo);
        return -1;
    }

    /* Se o arquivo ja tem conteudo, garante separacao da nova mensagem. */
    long tamanho_arquivo = ftell(arquivo);

    if (tamanho_arquivo < 0) {
        fclose(arquivo);
        return -1;
    }

    if (tamanho_arquivo > 0) {
        if (fseek(arquivo, -1, SEEK_END) != 0) {
            fclose(arquivo);
            return -1;
        }

        int ultimo = fgetc(arquivo);

        if (ultimo != '\n') {
            if (fseek(arquivo, 0, SEEK_END) != 0 ||
                fputc('\n', arquivo) == EOF) {
                fclose(arquivo);
                return -1;
            }
        }
    }

    if (fseek(arquivo, 0, SEEK_END) != 0) {
        fclose(arquivo);
        return -1;
    }

    if (nova_mensagem[0] != '\0') {
        if (fprintf(arquivo, "%s", nova_mensagem) < 0) {
            fclose(arquivo);
            return -1;
        }

        size_t tamanho = strlen(nova_mensagem);

        if (nova_mensagem[tamanho - 1] != '\n') {
            if (fputc('\n', arquivo) == EOF) {
                fclose(arquivo);
                return -1;
            }
        }
    }

    if (fclose(arquivo) != 0) {
        return -1;
    }

    printf("\nNova mensagem adicionada!\n");
    return 0;
}


int main(int argc, char *argv[]) {
    const char *nome_arquivo = (argc > 1) ? argv[1] : "teste.txt";

    const char nova_mensagem[] =
        "Acho que agora compreendi sua mensagem";

    int linhas = contar_linhas(nome_arquivo);
    int colunas = total_colunas(nome_arquivo);

    if (linhas == -1 || colunas == -1) {
        printf("Nao foi possivel analisar o arquivo.\n");
        return 1;
    }

    printf("Arquivo: %s\n", nome_arquivo);
    printf("Linhas: %d\n", linhas);
    printf("Maior comprimento de linha (bytes): %d\n", colunas);

    VetorPalavras vetor;
    inicializar_vetor(&vetor);

    if (ler_e_vetorizar(nome_arquivo, &vetor) != 0) {
        printf("Erro durante a leitura ou vetorizacao.\n");
        liberar_vetor(&vetor);
        return 1;
    }

    mostrar_vetor(&vetor);
    mostrar_frequencias(&vetor);

    liberar_vetor(&vetor);

    /*
     * A mensagem e adicionada depois da leitura e da vetorizacao.
     * Portanto, ela sera processada na proxima execucao.
     */
    int resultado = mensagens(nome_arquivo, nova_mensagem);

    if (resultado == -1) {
        printf("Erro ao atualizar o arquivo.\n");
        return 1;
    }

    if (resultado == 1) {
        printf("Mensagem de controle encontrada. Nova mensagem nao adicionada.\n");
    }

    return 0;
}
