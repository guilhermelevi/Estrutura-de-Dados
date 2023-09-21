#include <stdio.h>

#define ROWS 2
#define COLS 2

int buscaSequencialMatriz(int matriz[][COLS], int valor, int *linhaEncontrada, int *colunaEncontrada) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (matriz[i][j] == valor) {
                *linhaEncontrada = i;
                *colunaEncontrada = j;
                return 1;
            }
        }
    }
    return 0; 
}

int main() {
    int matriz[ROWS][COLS];
    
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("Digite um valor para matriz[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    int valorProcurado;
    printf("\nDigite o valor que deseja encontrar na matriz: ");
    scanf("%d", &valorProcurado);

    int linhaEncontrada, colunaEncontrada;
    int encontrado = buscaSequencialMatriz(matriz, valorProcurado, &linhaEncontrada, &colunaEncontrada);

    if (encontrado) {
        printf("\nValor encontrado na posição [%d][%d].\n", linhaEncontrada, colunaEncontrada);
    } else {
        printf("\nValor não encontrado na matriz.\n");
    }

    return 0;
}
