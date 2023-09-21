#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preencherArray(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        arr[i] = rand() % 1000;
    }
}

void exibirArray(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubbleSort(int arr[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void quickSort(int arr[], int esquerda, int direita) {
    if (esquerda < direita) {
        int pivo = arr[direita];
        int i = esquerda - 1;

        for (int j = esquerda; j <= direita - 1; j++) {
            if (arr[j] < pivo) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        int temp = arr[i + 1];
        arr[i + 1] = arr[direita];
        arr[direita] = temp;

        int pontoDeDivisao = i + 1;

        quickSort(arr, esquerda, pontoDeDivisao - 1);
        quickSort(arr, pontoDeDivisao + 1, direita);
    }
}

void merge(int arr[], int esquerda, int meio, int direita) {
    int n1 = meio - esquerda + 1;
    int n2 = direita - meio;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = arr[esquerda + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[meio + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = esquerda;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int esquerda, int direita) {
    if (esquerda < direita) {
        int meio = esquerda + (direita - esquerda) / 2;

        mergeSort(arr, esquerda, meio);
        mergeSort(arr, meio + 1, direita);

        merge(arr, esquerda, meio, direita);
    }
}

int main() {
    srand(time(NULL));

    int tamanhos[] = {100, 1000, 10000, 100000}; 
    clock_t inicio, fim;
    double tempo;

    for (int i = 0; i < sizeof(tamanhos) / sizeof(tamanhos[0]); i++) {
        int tamanho = tamanhos[i];
        int *arr = (int *)malloc(sizeof(int) * tamanho);

        preencherArray(arr, tamanho);

        inicio = clock();
        bubbleSort(arr, tamanho);
        fim = clock();
        tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
        printf("Bubble Sort para %d elementos: %lf segundos\n", tamanho, tempo);

        preencherArray(arr, tamanho);

        inicio = clock();
        quickSort(arr, 0, tamanho - 1);
        fim = clock();
        tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
        printf("QuickSort para %d elementos: %lf segundos\n", tamanho, tempo);

        preencherArray(arr, tamanho);

        inicio = clock();
        mergeSort(arr, 0, tamanho - 1);
        fim = clock();
        tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
        printf("MergeSort para %d elementos: %lf segundos\n\n", tamanho, tempo);

        free(arr);
    }

    return 0;
}
