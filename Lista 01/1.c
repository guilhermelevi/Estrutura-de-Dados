#include <stdio.h>
#include <string.h>

typedef struct
{
  char Nome[50];
  int Idade;
  float Altura;
} Pessoa;

Pessoa setPessoa()
{
  Pessoa P;
  printf("Nome: ");
  fgets(P.Nome, 50, stdin);

  printf("Idade: ");
  scanf("%d", &P.Idade);

  printf("Altura: ");
  scanf("%f", &P.Altura);

  return P;
}

void ImprimePessoa(Pessoa P)
{
  printf("\nNome: %s\nIdade: %d\nAltura: %.2f\n", P.Nome, P.Idade, P.Altura);
}

int main()
{
  Pessoa pessoa = setPessoa();
  ImprimePessoa(pessoa);
  return 0;
}