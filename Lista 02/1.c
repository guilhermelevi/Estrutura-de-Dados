#include <stdio.h>
#include <stdlib.h>
#define TAMANHO 5

void bubbleSort(int vetor[]){
  int aux = 0;

  for(int contador = 1; contador < TAMANHO; contador++){
    for(int i = 0; i < TAMANHO - 1; i++){
      if(vetor[i] > vetor[i + 1]){
        aux = vetor[i];
        vetor[i] = vetor[i + 1];
        vetor[i + 1] = aux;
      }
    }
  }
}

int main(){

  int vetor[TAMANHO];

  printf("Digite %d numeros: ", TAMANHO);
  for(int i = 0; i < TAMANHO; i++){
    scanf("%d", &vetor[i]);
  }

  bubbleSort(vetor);
  printf("vetor ordenado: ");
  for(int i = 0; i < TAMANHO; i++){
    printf("%d ", vetor[i]);
  }
  printf("\n");

  

  return 0;
}