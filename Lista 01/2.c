#include <stdio.h>

typedef struct
{
  int Inteiro;
  float Flutuante;
  char Caractere;
}Tipo;

Tipo setTipo()
{
  Tipo T;
  printf("Digite um valor inteiro: ");
  scanf("%d", &T.Inteiro);

  printf("Digite um valor Float: ");
  scanf("%f", &T.Flutuante);

  getchar();

  printf("Tipo um valor Char: ");
  scanf("%c", &T. Caractere);

  return T;
}

void ImprimeValores(Tipo T)
{
  printf("\n\nInteiro: %d\nFloat: %.3f\nChar: %c\n\n", T.Inteiro, T.Flutuante, T.Caractere);
}

int main()
{
 Tipo T = setTipo();
 ImprimeValores(T);
  
  return 0;
}