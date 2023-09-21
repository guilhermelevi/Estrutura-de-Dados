#include <stdio.h>
#include <stdlib.h>

#define ROWS 2
#define COLS 2

void quick_sort_2d(int arr[][COLS], int left, int right);

int main() {
    int matriz[ROWS][COLS];
    
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("Digite um valor para matriz[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("\nMatriz Original:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }

    quick_sort_2d(matriz, 0, ROWS - 1);

    printf("\nMatriz Ordenada:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void quick_sort_2d(int arr[][COLS], int left, int right) {
    int i, j, pivot, temp;

    if (left < right) {
        pivot = left;
        i = left;
        j = right;

        while (i < j) {
            while (arr[i / COLS][i % COLS] <= arr[pivot / COLS][pivot % COLS] && i < right) {
                i++;
            }
            while (arr[j / COLS][j % COLS] > arr[pivot / COLS][pivot % COLS]) {
                j--;
            }
            if (i < j) {
                temp = arr[i / COLS][i % COLS];
                arr[i / COLS][i % COLS] = arr[j / COLS][j % COLS];
                arr[j / COLS][j % COLS] = temp;
            }
        }

        temp = arr[pivot / COLS][pivot % COLS];
        arr[pivot / COLS][pivot % COLS] = arr[j / COLS][j % COLS];
        arr[j / COLS][j % COLS] = temp;

        quick_sort_2d(arr, left, j - 1);
        quick_sort_2d(arr, j + 1, right);
    }
}
