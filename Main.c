#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>
#include <shlobj.h>

#include "Funcoes.h"
#include "Algoritmos.h"

#define LIMPAR_TELA() system("cls")

void menu(const char* diretorio) {
    int algoritmo, tamanho = 0;
    char tipo;
    int opcao_tamanho;
    char nome_algoritmo[50];

    do {
        printf("\n    ================================================\n\n");
        printf("            ALGORITMOS DE ORDENACAO :\n\n");
        printf("       [1] -> InsertionSort \n");
        printf("       [2] -> SelectionSort \n");
        printf("       [3] -> ShellSort \n");
        printf("       [4] -> BubbleSort \n");
        printf("       [5] -> MergeSort \n");
        printf("       [6] -> QuickSort \n");
        printf("       [7] -> HeapSort \n");
        printf("       [0] -> Sair\n\n");
        printf("\n    ================================================\n\n");
        printf("    Selecione o algoritmo: ");
        scanf("%d", &algoritmo);

        if (algoritmo == 0) {
            break;
        }

        switch (algoritmo) {
            case 1:
                strcpy(nome_algoritmo, "InsertionSort");
                break;
            case 2:
                strcpy(nome_algoritmo, "SelectionSort");
                break;
            case 3:
                strcpy(nome_algoritmo, "ShellSort");
                break;
            case 4:
                strcpy(nome_algoritmo, "BubbleSort");
                break;
            case 5:
                strcpy(nome_algoritmo, "MergeSort");
                break;
            case 6:
                strcpy(nome_algoritmo, "QuickSort");
                break;
            case 7:
                strcpy(nome_algoritmo, "HeapSort");
                break;
            default:
                printf("Algoritmo invalido!\n");
                continue;
        }
        criarEstruturaPastas(diretorio, nome_algoritmo);

        LIMPAR_TELA();
        printf("\n    ================================================\n\n");
        printf("            TIPOS DE ORDENACAO :\n\n");
        printf("       [r] -> Randomico \n");
        printf("       [c] -> Crescente \n");
        printf("       [d] -> Decrescente\n\n");
        printf("\n    ================================================\n\n");
        printf("    Selecione o tipo: ");
        getchar();
        scanf("%c", &tipo);

        LIMPAR_TELA();
        printf("\n    ================================================\n\n");
        printf("            TAMANHO DO VETOR :\n\n");
        printf("       [1] -> 10 \n");
        printf("       [2] -> 100 \n");
        printf("       [3] -> 1.000 \n");
        printf("       [4] -> 10.000 \n");
        printf("       [5] -> 100.000 \n");
        printf("       [6] -> 1.000.000 \n\n");
        printf("\n    ================================================\n\n");
        printf("    Selecione o tamanho: ");
        scanf("%d", &opcao_tamanho);

        switch (opcao_tamanho) {
            case 1:
                tamanho = 10;
                break;
            case 2:
                tamanho = 100;
                break;
            case 3:
                tamanho = 1000;
                break;
            case 4:
                tamanho = 10000;
                break;
            case 5:
                tamanho = 100000;
                break;
            case 6:
                tamanho = 1000000;
                break;
            default:
                printf("Opcao de tamanho invalida!\n");
                continue;
        }

        int *vetor = (int *)malloc(tamanho * sizeof(int));
        int *vetor_original = (int *)malloc(tamanho * sizeof(int));
        if (vetor == NULL || vetor_original == NULL) {
            printf("Erro ao alocar memoria!\n");
            continue;
        }

        gerarInstancias(vetor, tamanho, tipo);
        memcpy(vetor_original, vetor, tamanho * sizeof(int));

        double tempo;
        switch (algoritmo) {
            case 1:
                tempo = insertion_sort(vetor, tamanho);
                break;
            case 2:
                tempo = selection_sort(vetor, tamanho);
                break;
            case 3:
                tempo = shell_sort(vetor, tamanho);
                break;
            case 4:
                tempo = bubble_sort(vetor, tamanho);
                break;
            case 5:
                tempo = merge_sort(vetor, tamanho);
                break;
            case 6:
                tempo = quick_sort(vetor, tamanho);
                break;
            case 7:
                tempo = heap_sort(vetor, tamanho);
                break;
        }

        caminhoArquivos(diretorio, vetor, tamanho, tempo, tipo, nome_algoritmo, vetor_original);

        free(vetor);
        free(vetor_original);

    } while (algoritmo != 0);

    printf("\n !! Programa encerrado !! \n");
}

int main() {
    srand(time(NULL));

    char diretorio[MAX_PATH];

    if (SHGetFolderPath(NULL, CSIDL_PROFILE, NULL, 0, diretorio) == S_OK) {

        strcat(diretorio, "\\Downloads\\");
    } else {
        printf("Erro ao obter o caminho do diretório.\n");
        return 1;
    }

    printf("Diretorio gerado: %s\n", diretorio);

    menu(diretorio);

    return 0;
}
