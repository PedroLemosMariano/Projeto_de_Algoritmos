#ifndef Funcoes_h
#define Funcoes_h

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <sys/stat.h>
#include <direct.h>
#include <errno.h>

void criar_pasta(const char* caminho) {
    if (_mkdir(caminho) != 0) {
        if (errno != EEXIST) {
            perror("Erro ao criar pasta");
        } else {
            printf("Pasta já existe: %s\n", caminho);
        }
    } else {
        printf("Pasta criada: %s\n", caminho);
    }
}

void criarEstruturaPastas(const char* base_dir, const char* algoritmo) {
    char path[260];

    // Criando pasta principal
    sprintf(path, "%s\\%s", base_dir, algoritmo);
    criar_pasta(path);

    // Criando subpasta "Arquivo de Entrada"
    sprintf(path, "%s\\%s\\Arquivo de Entrada", base_dir, algoritmo);
    criar_pasta(path);

    // Criando subpastas "crescente", "decrescente" e "random" dentro de "Arquivo de Entrada"
    sprintf(path, "%s\\%s\\Arquivo de Entrada\\Crescente", base_dir, algoritmo);
    criar_pasta(path);
    sprintf(path, "%s\\%s\\Arquivo de Entrada\\Decrescente", base_dir, algoritmo);
    criar_pasta(path);
    sprintf(path, "%s\\%s\\Arquivo de Entrada\\Random", base_dir, algoritmo);
    criar_pasta(path);

    // Criando subpasta "Arquivo de Saída"
    sprintf(path, "%s\\%s\\Arquivo de Saida", base_dir, algoritmo);
    criar_pasta(path);

    // Criando subpastas "crescente", "decrescente" e "random" dentro de "Arquivo de Saída"
    sprintf(path, "%s\\%s\\Arquivo de Saida\\Crescente", base_dir, algoritmo);
    criar_pasta(path);
    sprintf(path, "%s\\%s\\Arquivo de Saida\\Decrescente", base_dir, algoritmo);
    criar_pasta(path);
    sprintf(path, "%s\\%s\\Arquivo de Saida\\Random", base_dir, algoritmo);
    criar_pasta(path);

    // Criando subpasta "Arquivo de Tempo"
    sprintf(path, "%s\\%s\\Arquivo de Tempo", base_dir, algoritmo);
    criar_pasta(path);

    // Criando subpastas "crescente", "decrescente" e "random" dentro de "Arquivo de Tempo"
    sprintf(path, "%s\\%s\\Arquivo de Tempo\\Crescente", base_dir, algoritmo);
    criar_pasta(path);
    sprintf(path, "%s\\%s\\Arquivo de Tempo\\Decrescente", base_dir, algoritmo);
    criar_pasta(path);
    sprintf(path, "%s\\%s\\Arquivo de Tempo\\Random", base_dir, algoritmo);
    criar_pasta(path);
}

void caminhoArquivos(const char* base_dir, int vetor[], int tamanho, double tempo, char tipo, const char* algoritmo, int vetor_original[]) {
    char path[260];
    char subpasta[50];

    if (tipo == 'c') {
        strcpy(subpasta, "Crescente");
    } else if (tipo == 'd') {
        strcpy(subpasta, "Decrescente");
    } else if (tipo == 'r') {
        strcpy(subpasta, "Random");
    } else {
        printf("Tipo de ordenação inválido!\n");
        return;
    }

    sprintf(path, "%s\\%s\\Arquivo de Entrada\\%s\\Entrada_%d.txt", base_dir, algoritmo, subpasta, tamanho);
    FILE *arquivo_entrada = fopen(path, "w");
    if (arquivo_entrada == NULL) {
        printf("Erro ao abrir o arquivo de entrada: %s\n", path);
        perror("Erro");
        return;
    }
    for (int i = 0; i < tamanho; i++) {
        fprintf(arquivo_entrada, "%d\n", vetor_original[i]);
    }
    fclose(arquivo_entrada);

    sprintf(path, "%s\\%s\\Arquivo de Saida\\%s\\Saida_%d.txt", base_dir, algoritmo, subpasta, tamanho);
    FILE *arquivo_saida = fopen(path, "w");
    if (arquivo_saida == NULL) {
        printf("Erro ao abrir o arquivo de saída: %s\n", path);
        perror("Erro");
        return;
    }
    for (int i = 0; i < tamanho; i++) {
        fprintf(arquivo_saida, "%d\n", vetor[i]);
    }
    fclose(arquivo_saida);

    sprintf(path, "%s\\%s\\Arquivo de Tempo\\%s\\Tempo_%d.txt", base_dir, algoritmo, subpasta, tamanho);
    FILE *arquivo_tempo = fopen(path, "a");
    if (arquivo_tempo == NULL) {
        printf("Erro ao abrir o arquivo de tempo: %s\n", path);
        perror("Erro");
        return;
    }
    fprintf(arquivo_tempo, "Tempo gasto: %f segundos\n", tempo);
    fclose(arquivo_tempo);
}

void gerarInstancias(int vetor[], int tamanho, char tipo) {
    if (tipo == 'r') {
        srand(time(NULL));
        for (int i = 0; i < tamanho; i++) {
            vetor[i] = rand() % (tamanho * 1000000);
        }
    } else if (tipo == 'c') {
        for (int i = 0; i < tamanho; i++) {
            vetor[i] = i + 1;
        }
    } else if (tipo == 'd') {
        for (int i = 0; i < tamanho; i++) {
            vetor[i] = tamanho - i;
        }
    } else {
        printf("Tipo de ordenação inválido!\n");
    }
}
#endif
