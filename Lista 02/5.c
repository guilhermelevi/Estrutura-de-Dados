#include <stdio.h>

#define ROWS 2
#define COLS 2
void insertion_sort(int arr[], int size);
void sort_2d_matrix(int matrix[][COLS]);

int main() {
    int matrix[ROWS][COLS];
    
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("Digite um valor para matrix[%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("\nMatriz Original:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    sort_2d_matrix(matrix);

    printf("\nMatriz Ordenada:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void insertion_sort(int arr[], int size) {
    int i, j, key;
    for (i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void sort_2d_matrix(int matrix[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        insertion_sort(matrix[i], COLS);
    }
}
