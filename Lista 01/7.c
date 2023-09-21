#include <stdio.h>
#include <string.h>

typedef struct
{
  char NomeTitular[50];
  int Numero;
  float Saldo;
}ContaBancaria;

void cadastro(ContaBancaria *Conta)
{
  printf("\nNome do titular: ");
  fgets(Conta->NomeTitular, 50, stdin);

  printf("Numero da conta: ");
  scanf("%d", &Conta->Numero);

  printf("Saldo: ");
  scanf("%f", &Conta->Saldo);
}

void deposito(ContaBancaria *Conta)
{

  float deposito, total;

  printf("\nValor do deposito: ");
  scanf("%f", &deposito);

  Conta->Saldo += deposito;
}

void saque(ContaBancaria *Conta)
{

  float saque;

  printf("\nValor do saque: ");
  scanf("%f", &saque);

  Conta->Saldo -= saque;
}

int main(){
  
  ContaBancaria Conta;
  int op = 1;


  cadastro(&Conta);

  while(op != 0){
    printf("\n1 - Depositar\n2 - Sacar\n3 - Verificar Saldo\nOpcao: ");
    scanf("%d", &op);

    switch(op){
      case 1:
        deposito(&Conta);
      break;

      case 2: 
        saque(&Conta);
      break;

      case 3:
        printf("\n%.1f", Conta.Saldo);
      break;
    }
  }
}