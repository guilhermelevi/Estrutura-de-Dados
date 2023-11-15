#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Produto {
    char nome[50];
    float preco;
    struct Produto* next;
};

void insertOrdered(struct Produto** head, char novoNome[], float novoPreco) {
    struct Produto* novoProduto = (struct Produto*)malloc(sizeof(struct Produto));
    strncpy(novoProduto->nome, novoNome, sizeof(novoProduto->nome));
    novoProduto->preco = novoPreco;
    novoProduto->next = NULL;

    if (*head == NULL || novoPreco < (*head)->preco) {
        novoProduto->next = *head;
        *head = novoProduto;
    } else {
        struct Produto* atual = *head;

        while (atual->next != NULL && atual->next->preco < novoPreco) {
            atual = atual->next;
        }

        novoProduto->next = atual->next;
        atual->next = novoProduto;
    }
}

void printLista(struct Produto* head) {
    struct Produto* atual = head;
    while (atual != NULL) {
        printf("Produto: %s, Preco: %.2f\n", atual->nome, atual->preco);
        atual = atual->next;
    }
    printf("\n");
}

int main() {
    struct Produto* listaCompras = NULL;
    int tamanhoLista;
    char nomeProduto[50];
    float precoProduto;

    printf("Informe o tamanho da lista de compras: ");
    scanf("%d", &tamanhoLista);

    for (int i = 0; i < tamanhoLista; i++) {
        printf("Informe o nome do produto %d: ", i + 1);
        scanf("%s", nomeProduto);

        printf("Informe o preco do produto %d: ", i + 1);
        scanf("%f", &precoProduto);

        insertOrdered(&listaCompras, nomeProduto, precoProduto);
    }

    printf("\nLista Ordenada de Compras:\n");
    printLista(listaCompras);

    struct Produto* atual = listaCompras;
    while (atual != NULL) {
        struct Produto* proximo = atual->next;
        free(atual);
        atual = proximo;
    }

    return 0;
}
