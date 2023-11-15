#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertOrdered(struct Node** head, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = NULL;

    if (*head == NULL || newData < (*head)->data) {
        newNode->next = *head;
        *head = newNode;
    } else {
        struct Node* current = *head;

        while (current->next != NULL && current->next->data < newData) {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;
    }
}
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int size, data;

    printf("Informe o tamanho da lista: ");
    scanf("%d", &size);

    for (int i = 0; i < size; i++) {
        printf("Informe o elemento %d: ", i + 1);
        scanf("%d", &data);
        insertOrdered(&head, data);
    }

    printf("Lista Ordenada: ");
    printList(head);

    struct Node* current = head;
    while (current != NULL) {
        struct Node* next = current->next;
        free(current);
        current = next;
    }

    return 0;
}
