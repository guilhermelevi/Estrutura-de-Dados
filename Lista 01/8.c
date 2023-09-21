#include <stdio.h>

typedef struct
{
  char Nome[50];
  int Qntd;
  float Preco;
} Produto;

void limparBufferEntrada()
{
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
}

void cadastroProduto(Produto P[], int *nmrP)
{
  printf("\nNome do Produto: ");
  fgets(P[*nmrP].Nome, 50, stdin);

  printf("Informe o preco: R$");
  scanf("%f", &P[*nmrP].Preco);

  printf("Quantidade em estoque: ");
  scanf("%d", &P[*nmrP].Qntd);

  (*nmrP)++;
}

void compra(Produto P[], int *nmrP, float *carrinho)
{
  int op;

  for (int i = 0; i < *nmrP; i++)
  {
    printf("\n%d\n", i + 1);
    printf("Nome: %s", P[i].Nome);
    printf("Preco: %.2f\n", P[i].Preco);
    printf("Quantidade em estoque: %d\n", P[i].Qntd);
  }

  printf("\nSelecione o produto: ");
  scanf("%d", &op);

  if (op >= 1 && op <= *nmrP)
  {
    int selectedProductIndex = op - 1;
    if (P[selectedProductIndex].Qntd > 0)
    {
      P[selectedProductIndex].Qntd--;
      *carrinho += P[selectedProductIndex].Preco;
    }
    else
    {
      printf("Produto fora de estoque.\n");
    }
  }
  else
  {
    printf("Opção inválida.\n");
  }
}

float carrinhoCompra(float *carrinho)
{
  return *carrinho;
}

int main()
{
  Produto P[3];
  int cont = 1, op, nmrP = 0;
  float carrinho = 0.0;

  while (cont != 0)
  {
    printf("\n1 - Cadastrar Produtos\n2 - Comprar\n0 - Sair\n\nOpcao: ");
    scanf("%d", &op);

    switch (op)
    {
    case 1:
      limparBufferEntrada();
      cadastroProduto(P, &nmrP);
      break;

    case 2:
      compra(P, &nmrP, &carrinho);
      break;

    case 0:
      cont = 0;
      break;
    }
  }

  printf("\nCarrinho de compras: R$%.2f\n", carrinhoCompra(&carrinho));

  return 0;
}
