#include <stdio.h>
#include <stdlib.h>
#define TAM 5

void insertionSort(int vet[]){
  int i, j, a;

  for(i = 1; i < TAM; i++){
    a = vet[i];
    j = i - 1;

    while(j >= 0 && vet[j] < a){
      vet[j + 1] = vet[j];
      j--;
    }
    vet[j + 1] = a;
  }
}


int main(){

  int vet[TAM];

  printf("Digite %d valores: ", TAM);
  for(int i = 0;  i < TAM; i++){
    scanf("%d", &vet[i]);
  }

  insertionSort(vet);

  printf("Valores ordenados: ");
  for(int i = 0;  i < TAM; i++){
    printf("%d ", vet[i]);
  }
  printf("\n");


  return 0; 
}