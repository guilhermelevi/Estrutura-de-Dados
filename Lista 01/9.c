#include <stdio.h>
#include <string.h>
#include <time.h>

typedef struct
{
  char Nome[50];
  char Cargo[50];
  char Admissao[11];
  float Salario;
} Funcionario;

Funcionario setFuncionario(char *nome, char *cargo, char *adm, float salario)
{
  Funcionario F;
  strcpy(F.Nome, nome);
  strcpy(F.Cargo, cargo);
  strcpy(F.Admissao, adm);
  F.Salario = salario;

  return F;
}

void aumento(float *salario)
{
  float aumento;

  printf("Porcentagem de aumento: ");
  scanf("%f", &aumento);

  *salario = *salario * (1 + (aumento / 100));

  printf("Salario apos aumento: R$%.2f\n\n", *salario);
}

int calcularTempoNaEmpresa(char *dataAdmissao)
{
  struct tm admissao_tm = {0};
  sscanf(dataAdmissao, "%d/%d/%d", &admissao_tm.tm_mday, &admissao_tm.tm_mon, &admissao_tm.tm_year);
  admissao_tm.tm_mon -= 1;
  admissao_tm.tm_year -= 1900;
  time_t now;
  time(&now);
  struct tm *dataAtual = localtime(&now);

  double diff = difftime(mktime(dataAtual), mktime(&admissao_tm));
  int anos = (int)(diff / (60 * 60 * 24 * 365.25));
  return anos;
}

void ImprimeFuncionario(Funcionario F)
{
  printf("\n\nNome: %s\nCargo: %s\nData admissao: %s\nSalario: R$%.2f\n\n", F.Nome, F.Cargo, F.Admissao, F.Salario);
}

int main()
{
  Funcionario F;

  F = setFuncionario("Joao Batista", "Gestor", "12/12/2012", 16800.00);
  ImprimeFuncionario(F);
  aumento(&F.Salario);

  int tempoNaEmpresa = calcularTempoNaEmpresa(F.Admissao);
  printf("Tempo na Empresa: %d anos\n", tempoNaEmpresa);

  return 0;
}
