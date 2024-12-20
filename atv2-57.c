#include <stdio.h>
#include <stdlib.h>

// Estrutura de um nó da lista circular
struct Node {
    int data;
    struct Node* next;
};

// Função para criar um novo nó
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Função para adicionar um nó ao final da lista circular
void append(struct Node** head_ref, int new_data) {
    struct Node* newNode = createNode(new_data);
    struct Node* last = *head_ref;

    // Se a lista estiver vazia, o novo nó será o primeiro nó
    if (*head_ref == NULL) {
        *head_ref = newNode;
        newNode->next = *head_ref;  // Apontando o último nó para o primeiro nó
        return;
    }

    // Percorre até o último nó
    while (last->next != *head_ref) {
        last = last->next;
    }

    // Adiciona o novo nó no final
    last->next = newNode;
    newNode->next = *head_ref;
}

// Função para inserir um nó em uma posição específica
void insertAtPosition(struct Node** head_ref, int new_data, int position) {
    struct Node* newNode = createNode(new_data);
    struct Node* temp = *head_ref;
    struct Node* prev = NULL;

    // Se a lista estiver vazia ou a posição for 1
    if (*head_ref == NULL) {
        *head_ref = newNode;
        newNode->next = *head_ref;
        return;
    }

    if (position == 1) {
        newNode->next = *head_ref;
        // Encontra o último nó para atualizar o ponteiro
        while (temp->next != *head_ref) {
            temp = temp->next;
        }
        temp->next = newNode;
        *head_ref = newNode;
        return;
    }

    // Percorre até a posição anterior
    for (int i = 1; temp != NULL && i < position; i++) {
        prev = temp;
        temp = temp->next;
    }

    // Verifica se a posição é válida
    if (temp == NULL && position > 1) {
        printf("Posição inválida.\n");
        free(newNode);
        return;
    }

    // Insere o novo nó na posição desejada
    prev->next = newNode;
    newNode->next = temp;
}

// Função para exibir a lista circular
void displayList(struct Node* head) {
    struct Node* temp = head;
    int node_number = 1;

    if (head == NULL) {
        printf("A lista está vazia.\n");
        return;
    }

    printf("Os dados inseridos na lista são:\n");
    do {
        printf("Dado %d = %d\n", node_number++, temp->data);
        temp = temp->next;
    } while (temp != head);
}

int main() {
    struct Node* head = NULL;
    int n, data, position;

    // Inserindo nós na lista circular
    printf("Insira o número de nós: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        printf("Dados de entrada para o nó %d: ", i);
        scanf("%d", &data);
        append(&head, data);
    }

    displayList(head);

    // Inserindo um nó em uma posição específica
    printf("Dados de entrada para o nó a ser inserido: ");
    scanf("%d", &data);
    printf("Insira a posição (1 a n+1): ");
    scanf("%d", &position);
    insertAtPosition(&head, data, position);

    printf("\nApós a inserção na posição %d, a nova lista é:\n", position);
    displayList(head);

    return 0;
}
