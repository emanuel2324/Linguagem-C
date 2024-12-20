#include <stdio.h>
#include <stdlib.h>

// Estrutura de um nó da lista duplamente vinculada
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Função para criar um novo nó
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Função para inserir um nó no final da lista
void append(struct Node** head_ref, int new_data) {
    struct Node* newNode = createNode(new_data);
    struct Node* last = *head_ref;

    if (*head_ref == NULL) {
        *head_ref = newNode;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = newNode;
    newNode->prev = last;
}

// Função para exibir a lista na ordem inversa
void displayReverse(struct Node* head) {
    struct Node* last = head;

    if (head == NULL) {
        printf("A lista está vazia.\n");
        return;
    }

    // Percorre até o último nó
    while (last->next != NULL) {
        last = last->next;
    }

    // Exibe os dados na ordem inversa
    printf("As datas na ordem inversa são:\n");
    int node_number = 1;
    while (last != NULL) {
        printf("Dados no nó %d: %d\n", node_number++, last->data);
        last = last->prev;
    }
}

int main() {
    struct Node* head = NULL;
    int n, data;

    printf("Insira o número de nós: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        printf("Dados de entrada para o nó %d: ", i);
        scanf("%d", &data);
        append(&head, data);
    }

    displayReverse(head);

    return 0;
}
