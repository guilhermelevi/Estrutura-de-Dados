#include <stdio.h>

typedef struct{
  float Dolar; 
  float Euro;
}Moeda;

float converter(Moeda M)
{
  int op;
  float cambio, vf;

  printf("\n1 - Euro p/ Dolar\n2 - Dolar p/ Euro\n\nOpcao: ");
  scanf("%d", &op);

  switch(op)
  {
    case 1:
      printf("\nValor em Euro: EUR ");
      scanf("%f", &M.Euro);

      printf("Taxa de cambio atual: EUR");
      scanf("%f", &cambio);

     vf = cambio * M.Euro;
    break;

    case 2:
      printf("Valor em Dolar: USD ");
      scanf("%f", &M.Euro);

      printf("Taxa de cambio atual: USD");
      scanf("%f", &cambio);

      vf = cambio * M.Euro;
    break;
  }
  return vf;
}

int main()
{
  float vf;
  Moeda M;

  vf = converter(M);
  printf("%.2f\n", vf);
}