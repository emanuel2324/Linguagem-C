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

// Função para excluir o nó do início da lista circular
void deleteFromBeginning(struct Node** head_ref) {
    struct Node* temp = *head_ref;
    struct Node* last = *head_ref;

    // Se a lista estiver vazia
    if (*head_ref == NULL) {
        printf("A lista está vazia.\n");
        return;
    }

    // Se a lista tiver apenas um nó
    if (temp->next == *head_ref) {
        printf("O nó excluído é -> %d\n", temp->data);
        free(temp);
        *head_ref = NULL;
        return;
    }

    // Encontra o último nó
    while (last->next != *head_ref) {
        last = last->next;
    }

    // Exclui o primeiro nó
    *head_ref = temp->next;
    last->next = *head_ref;
    printf("O nó excluído é -> %d\n", temp->data);
    free(temp);
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
    int n, data;

    // Inserindo nós na lista circular
    printf("Insira o número de nós: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        printf("Dados de entrada para o nó %d: ", i);
        scanf("%d", &data);
        append(&head, data);
    }

    displayList(head);

    // Excluindo o nó do início da lista circular
    deleteFromBeginning(&head);

    // Exibindo a lista após a exclusão
    printf("\nApós a exclusão, a nova lista é:\n");
    displayList(head);

    return 0;
}
