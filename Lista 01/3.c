#include <stdio.h>
#include <math.h>

typedef struct
{
  float X;
  float Y;
}Ponto;

Ponto lerCoordenadas(){
  Ponto P;
  printf("Digite as Coordernadas de X e Y: ");
  scanf("%f %f", &P.X, &P.Y);

  return P;
}

float calculoDistancia(Ponto P1, Ponto P2)
{
  float dx = P2.X - P1.X;
  float dy = P2.Y - P1.Y;
  return sqrt((dx * dx) + (dy * dy));
}

float inclinação(Ponto P1, Ponto P2)
{
  return(P2.Y - P1.Y) / (P2.X - P1.X);
}

int main()
{
  Ponto P1, P2;
  printf("\n");
  P1 = lerCoordenadas();
  P2 = lerCoordenadas();
  
  printf("Distrancia entre os pontos: %.2f\n", calculoDistancia(P1, P2));

  printf("Inclinação: %.2f\n", inclinação(P1, P2));
  printf("\n");

  return 0;
}