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

// Função para inserir um nó em uma posição específica
void insertAtPosition(struct Node** head_ref, int new_data, int position) {
    struct Node* newNode = createNode(new_data);
    struct Node* temp = *head_ref;

    // Se a lista estiver vazia ou a posição for a primeira, insira no início
    if (position == 1) {
        newNode->next = *head_ref;
        if (*head_ref != NULL)
            (*head_ref)->prev = newNode;
        *head_ref = newNode;
        return;
    }

    // Percorre até a posição onde será inserido o novo nó
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    // Se a posição for válida, insere o novo nó na posição
    if (temp != NULL) {
        newNode->next = temp->next;
        if (temp->next != NULL) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
        newNode->prev = temp;
    } else {
        printf("Posição inválida!\n");
    }
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
    int n, data, position;

    // Inserindo nós inicialmente na lista
    printf("Insira o número de nós (3 ou mais): ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        printf("Dados de entrada para o nó %d: ", i);
        scanf("%d", &data);
        append(&head, data);
    }

    displayList(head);

    // Inserir um novo nó em uma posição específica
    printf("\nInsira a posição para inserir um novo nó: ");
    scanf("%d", &position);
    printf("Dados de entrada para a posição %d: ", position);
    scanf("%d", &data);
    insertAtPosition(&head, data, position);

    printf("\nApós a inserção a nova lista é:\n");
    displayList(head);

    return 0;
}
