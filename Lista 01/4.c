#include <stdio.h>
#include <string.h>

#define MAX_CONTATOS 10

typedef struct
{
  char Nome[50];
  char Numero[11];
} Contato;

void limparBufferEntrada()
{
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
}

void adicionarContato(Contato Contatos[], int *numContato)
{
  if (*numContato < MAX_CONTATOS)
  {
    printf("Nome: ");
    fgets(Contatos[*numContato].Nome, sizeof(Contatos[*numContato].Nome), stdin);
    Contatos[*numContato].Nome[strcspn(Contatos[*numContato].Nome, "\n")] = '\0';

    printf("Numero: ");
    scanf("%10s", Contatos[*numContato].Numero);
    limparBufferEntrada();

    (*numContato)++;
    printf("Contato adicionado com sucesso!\n");
  }
  else
  {
    printf("Limite de contatos atingido.\n");
  }
}

void listarContatos(Contato Contatos[], int numContatos)
{
  printf("Lista de contatos:\n");
  if (numContatos == 0)
  {
    printf("Nenhum contato\n");
  }
  else
  {
    for (int i = 0; i < numContatos; i++)
    {
      printf("Nome: %s\n", Contatos[i].Nome);
      printf("Numero: %s\n", Contatos[i].Numero);
      printf("\n");
    }
  }
}

void buscarContato(Contato Contatos[], int numContatos, const char *nomeBusca)
{
  int encontrado = 0;

  for (int i = 0; i < numContatos; i++)
  {
    if (strcmp(Contatos[i].Nome, nomeBusca) == 0)
    {
      printf("Contato encontrado:\n");
      printf("Nome: %s\n", Contatos[i].Nome);
      printf("Numero: %s\n", Contatos[i].Numero);
      encontrado = 1;
      break;
    }
  }

  if (!encontrado)
  {
    printf("Contato nao encontrado.\n");
  }
}

int main()
{
  Contato Contatos[MAX_CONTATOS];
  int numContato = 0;
  int op;

  while (1)
  {
    printf("\n1 - Adicionar Contato\n2 - Listar contatos\n3 - Buscar Contato\n4 - Sair\nOperacao: ");
    scanf("%d", &op);
    limparBufferEntrada();

    switch (op)
    {
    case 1:
      adicionarContato(Contatos, &numContato);
      break;

    case 2:
      listarContatos(Contatos, numContato);
      break;

    case 3:
      if (numContato > 0)
      {
        char nomeBusca[50];
        printf("Digite o nome do contato a ser buscado: ");
        fgets(nomeBusca, sizeof(nomeBusca), stdin);
        nomeBusca[strcspn(nomeBusca, "\n")] = '\0';
                buscarContato(Contatos, numContato, nomeBusca);
      }
      else
      {
        printf("Nenhum contato registrado.\n");
      }
      break;

    case 4:
      printf("Saindo do programa.\n");
      return 0;

    default:
      printf("Opcao invalida.\n");
      break;
    }
  }

  return 0;
}