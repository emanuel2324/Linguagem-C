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

// Função para excluir um nó de uma posição específica da lista circular
void deleteFromPosition(struct Node** head_ref, int position) {
    struct Node* temp = *head_ref;
    struct Node* prev = NULL;
    int count = 1;

    // Se a lista estiver vazia
    if (*head_ref == NULL) {
        printf("A lista está vazia.\n");
        return;
    }

    // Caso especial: excluir o primeiro nó
    if (position == 1) {
        struct Node* last = *head_ref;

        // Se a lista tiver apenas um nó
        if (temp->next == *head_ref) {
            printf("O nó excluído é -> %d\n", temp->data);
            free(temp);
            *head_ref = NULL;
            return;
        }

        // Encontrar o último nó
        while (last->next != *head_ref) {
            last = last->next;
        }

        // Atualizar o ponteiro de head
        *head_ref = temp->next;
        last->next = *head_ref;
        printf("O nó excluído é -> %d\n", temp->data);
        free(temp);
        return;
    }

    // Percorre a lista até a posição fornecida
    while (count < position && temp->next != *head_ref) {
        prev = temp;
        temp = temp->next;
        count++;
    }

    // Verifica se a posição é válida
    if (count != position) {
        printf("Posição inválida.\n");
        return;
    }

    // Exclui o nó
    prev->next = temp->next;
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

    // Inserindo a posição para excluir o nó
    printf("\nInsira a posição para excluir o nó: ");
    scanf("%d", &position);

    // Excluindo o nó na posição especificada
    deleteFromPosition(&head, position);

    // Exibindo a lista após a exclusão
    printf("\nApós a exclusão, a nova lista é:\n");
    displayList(head);

    return 0;
}
