#ifndef Algoritmos_h
#define Funcoes_h

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Função (Merge Sort)
void merge(int vetor[], int esquerda, int meio, int direita) {
    int n1 = meio - esquerda + 1;
    int n2 = direita - meio;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));


    for (int i = 0; i < n1; i++) {
        L[i] = vetor[esquerda + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = vetor[meio + 1 + j];
    }

    int i = 0, j = 0, k = esquerda;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            vetor[k] = L[i];
            i++;
        } else {
            vetor[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        vetor[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        vetor[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void mergeSort(int vetor[], int esquerda, int direita) {
    if (esquerda < direita) {
        int meio = esquerda + (direita - esquerda) / 2;

        mergeSort(vetor, esquerda, meio);
        mergeSort(vetor, meio + 1, direita);

        merge(vetor, esquerda, meio, direita);
    }
}

// Função para encontrar o pivô mediano (Quick Sort)
int median_of_three(int vetor[], int low, int high) {
    int mid = low + (high - low) / 2;

    if (vetor[low] > vetor[mid]) {
        int temp = vetor[low];
        vetor[low] = vetor[mid];
        vetor[mid] = temp;
    }
    if (vetor[low] > vetor[high]) {
        int temp = vetor[low];
        vetor[low] = vetor[high];
        vetor[high] = temp;
    }
    if (vetor[mid] > vetor[high]) {
        int temp = vetor[mid];
        vetor[mid] = vetor[high];
        vetor[high] = temp;
    }

    int temp = vetor[mid];
    vetor[mid] = vetor[high];
    vetor[high] = temp;

    return vetor[high];
}

// Particionamento com pivô mediano (Quick Sort)
int partition(int vetor[], int low, int high) {
    int pivot = median_of_three(vetor, low, high);
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (vetor[j] < pivot) {
            i++;
            int temp = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = temp;
        }
    }

    int temp = vetor[i + 1];
    vetor[i + 1] = vetor[high];
    vetor[high] = temp;

    return i + 1;
}

// Função recursiva (Quick Sort)
void quick_sort_recursive(int vetor[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(vetor, low, high);
        quick_sort_recursive(vetor, low, pivotIndex - 1);
        quick_sort_recursive(vetor, pivotIndex + 1, high);
    }
}

// Função para criar o heap máximo
void heapify(int vetor[], int tamanho, int i) {
    int maior = i;              // Assume que o maior é o nó raiz
    int esquerda = 2 * i + 1;   // Filho à esquerda
    int direita = 2 * i + 2;    // Filho à direita

    // Verifica se o filho à esquerda é maior que a raiz
    if (esquerda < tamanho && vetor[esquerda] > vetor[maior]) {
        maior = esquerda;
    }

    // Verifica se o filho à direita é maior que o maior atual
    if (direita < tamanho && vetor[direita] > vetor[maior]) {
        maior = direita;
    }

    // Se o maior não for a raiz
    if (maior != i) {
        int temp = vetor[i];
        vetor[i] = vetor[maior];
        vetor[maior] = temp;

        // Faz recursivamente o heapify para o subárvore afetado
        heapify(vetor, tamanho, maior);
    }
}

double insertion_sort(int vetor[], int tamanho) {
    clock_t inicio = clock();

    for (int i = 1; i < tamanho; i++) {
        int chave = vetor[i];
        int j = i - 1;
        while (j >= 0 && vetor[j] > chave) {
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j + 1] = chave;
    }

    clock_t fim = clock();
    double tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("    Tempo gasto na ordenacao: %f segundos\n", tempo_gasto);

    return tempo_gasto;
}

double selection_sort(int vetor[], int tamanho) {
    clock_t inicio = clock();

    for (int i = 0; i < tamanho - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < tamanho; j++) {
            if (vetor[j] < vetor[min_index]) {
                min_index = j;
            }
        }
        if (min_index != i) {
            int temp = vetor[i];
            vetor[i] = vetor[min_index];
            vetor[min_index] = temp;
        }
    }

    clock_t fim = clock();
    double tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("    Tempo gasto na ordenacao: %f segundos\n", tempo_gasto);

    return tempo_gasto;
}

double shell_sort(int vetor[], int tamanho) {
    clock_t inicio = clock();

    for (int intervalo = tamanho / 2; intervalo > 0; intervalo /= 2) {
        for (int i = intervalo; i < tamanho; i++) {
            int temp = vetor[i];
            int j;
            for (j = i; j >= intervalo && vetor[j - intervalo] > temp; j -= intervalo) {
                vetor[j] = vetor[j - intervalo];
            }
            vetor[j] = temp;
        }
    }

    clock_t fim = clock();
    double tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("    Tempo gasto na ordenacao: %f segundos\n", tempo_gasto);

    return tempo_gasto;
}

double bubble_sort(int vetor[], int tamanho) {
    clock_t inicio = clock();

    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }

    clock_t fim = clock();
    double tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("    Tempo gasto na ordenacao: %f segundos\n", tempo_gasto);

    return tempo_gasto;
}

double merge_sort(int vetor[], int tamanho) {
    clock_t inicio = clock();

    mergeSort(vetor, 0, tamanho - 1);

    clock_t fim = clock();
    double tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("    Tempo gasto na ordenacao: %f segundos\n", tempo_gasto);

    return tempo_gasto;
}

double quick_sort(int vetor[], int tamanho) {
    clock_t inicio = clock();

    quick_sort_recursive(vetor, 0, tamanho - 1);

    clock_t fim = clock();
    double tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("    Tempo gasto na ordenacao: %f segundos\n", tempo_gasto);

    return tempo_gasto;
}

double heap_sort(int vetor[], int tamanho) {
    clock_t inicio = clock();

    for (int i = tamanho / 2 - 1; i >= 0; i--) {
        heapify(vetor, tamanho, i);
    }

    for (int i = tamanho - 1; i >= 0; i--) {
        int temp = vetor[0];
        vetor[0] = vetor[i];
        vetor[i] = temp;

        // Chama heapify no heap reduzido
        heapify(vetor, i, 0);
    }

    clock_t fim = clock();
    double tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("    Tempo gasto na ordenacao: %f segundos\n", tempo_gasto);

    return tempo_gasto;
}


#endif
