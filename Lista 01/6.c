#include <stdio.h>
#include <string.h>

typedef struct{
  char Nome[50];
  char Matricula[10];
  float N1, N2, N3;
}Estudante;

void cadastro(Estudante Est[], int *i)
{
  printf("Cadastro Aluno\n");

  printf("Nome: ");
  fgets(Est[*i].Nome, 50, stdin);

  printf("Matricula: ");
  fgets(Est[*i].Matricula, 10, stdin);

  printf("Nota 1, 2 e 3: ");
  scanf("%f %f %f", &Est[*i].N1, &Est[*i].N2, &Est[*i].N3);
}

float media(float n1, float n2, float n3 )
{
  float media = (n1 + n2 + n3) / 3;
  return media; 
}

void aprovacao(float media)
{
  if(media >= 7){
    printf("Aprovado");
  }
  else{
    printf("Reprovado");
  }
}

int main(){
  int i = 0; 

  Estudante Est[5];
  
  cadastro(Est, &i);
  float notaMedia = media(Est[i].N1, Est[i].N2, Est[i].N3);
  printf("%.2f\n", notaMedia);
  if (notaMedia >= 7){
    printf("Aprovado\n");
  }
  else{
    printf("Reprovado\n");
  }
 
  return 0;
}