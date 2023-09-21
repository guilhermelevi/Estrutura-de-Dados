#include <stdio.h>
#include <string.h>

#define MAX_LIVRO 5

typedef struct
{
  char Titulo[50];
  char Autor[50];
  int Ano;
} Livro;

void limparBufferEntrada()
{
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
}

void cadastroLivro(Livro Livro[], int *nmrLivro)
{
  printf("Cadastro de Livro\n");
  printf("Título: ");
  fgets(Livro[*nmrLivro].Titulo, 50, stdin);

  printf("Autor: ");
  fgets(Livro[*nmrLivro].Autor, 50, stdin);

  printf("Ano de publicação: ");
  scanf("%d", &Livro[*nmrLivro].Ano);

  (*nmrLivro)++;
}

void listarLivros(Livro Livro[], int nmrLivro)
{
  printf("Lista de livros:\n");
  if (nmrLivro == 0)
  {
    printf("Nenhum Livro cadastrado");
  }
  else
  {
    for (int i = 0; i < nmrLivro; i++)
    {
      printf("Titulo: %s", Livro[i].Titulo);
      printf("Autor: %s", Livro[i].Autor);
      printf("Ano: %d", Livro[i].Ano);
    }
  }
}

void buscarLivro(Livro Livro[], int nmrLivro)
{
  int encontrado = 0;
  char nomeBusca[50];

  printf("Digite o nome da busca: ");
  fgets(nomeBusca, 50, stdin);

  for (int i = 0; i < nmrLivro; i++)
  {
    if (strcmp(Livro[i].Titulo, nomeBusca) == 0)
    {
      printf("Livro Encontrado\n");
      printf("\nTitulo: %s", Livro[i].Titulo);
      printf("Autor: %s", Livro[i].Autor);
      printf("Ano: %d", Livro[i].Ano);
    }
    else
    {
      printf("Livro NAO Encontrado");
    }
  }
}

int main()
{

  Livro Livro[MAX_LIVRO];
  int nmrLivro = 0, op;

  while (op != 4)
  {

    printf("\n\n1 - Cadastrar Livro\n2 - Listar Livro\n3 - Buscar Livro\n4 - Sair\nOperacao: ");
    scanf("%d", &op);
    limparBufferEntrada();

    switch (op)
    {
    case 1:
      printf("\n");
      cadastroLivro(Livro, &nmrLivro);
      break;

    case 2:
      printf("\n");
      listarLivros(Livro, nmrLivro);
      break;

    case 3:
      printf("\n");
      buscarLivro(Livro, nmrLivro);
      break;

    case 4:
      printf("Saindo do programa.\n");
      return 0;

    default:
      printf("Opcao invalida.\n");
      break;
    }
  }
}