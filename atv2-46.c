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

    // Se a lista estiver vazia, o novo nó será o primeiro nó
    if (*head_ref == NULL) {
        *head_ref = newNode;
        return;
    }

    // Percorre até o último nó
    while (last->next != NULL) {
        last = last->next;
    }

    // Adiciona o novo nó no final
    last->next = newNode;
    newNode->prev = last;
}

// Função para inserir um nó no início da lista
void insertAtBeginning(struct Node** head_ref, int new_data) {
    struct Node* newNode = createNode(new_data);

    if (*head_ref == NULL) {
        *head_ref = newNode;
        return;
    }

    newNode->next = *head_ref;
    (*head_ref)->prev = newNode;
    *head_ref = newNode;
}

// Função para exibir a lista
void displayList(struct Node* head) {
    struct Node* temp = head;
    int node_number = 1;

    printf("Os dados inseridos na lista são:\n");
    while (temp != NULL) {
        printf("nó %d: %d\n", node_number++, temp->data);
        temp = temp->next;
    }
}

int main() {
    struct Node* head = NULL;
    int n, data;

    // Inserindo nós inicialmente na lista
    printf("Insira o número de nós: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        printf("Dados de entrada para o nó %d: ", i);
        scanf("%d", &data);
        append(&head, data);
    }

    displayList(head);

    // Inserir um nó no início da lista
    printf("Dados de entrada para o primeiro nó: ");
    scanf("%d", &data);
    insertAtBeginning(&head, data);

    printf("\nApós a inserção no início, a nova lista é:\n");
    displayList(head);

    // Inserir um nó no final da lista
    printf("\nDados de entrada para o último nó: ");
    scanf("%d", &data);
    append(&head, data);

    printf("\nApós a inserção no final, a nova lista é:\n");
    displayList(head);

    return 0;
}
