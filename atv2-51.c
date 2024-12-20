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

// Função para excluir um nó de uma posição específica
void deleteFromPosition(struct Node** head_ref, int position) {
    if (*head_ref == NULL) {
        printf("A lista está vazia. Não há nada para excluir.\n");
        return;
    }

    struct Node* temp = *head_ref;

    // Se o nó a ser excluído for o primeiro
    if (position == 1) {
        *head_ref = temp->next;
        if (*head_ref != NULL) {
            (*head_ref)->prev = NULL;
        }
        free(temp);
        return;
    }

    // Percorre até o nó na posição fornecida
    for (int i = 1; temp != NULL && i < position; i++) {
        temp = temp->next;
    }

    // Se o nó na posição fornecida não existir
    if (temp == NULL) {
        printf("A posição fornecida é inválida.\n");
        return;
    }

    // Ajusta os ponteiros para excluir o nó
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }

    free(temp);  // Libera a memória do nó excluído
}

// Função para exibir a lista
void displayList(struct Node* head) {
    struct Node* temp = head;
    int node_number = 1;

    if (head == NULL) {
        printf("A lista está vazia.\n");
        return;
    }

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

    // Exclui o nó de uma posição específica
    printf("Insira a posição (1 a %d) para excluir um nó: ", n);
    scanf("%d", &position);

    deleteFromPosition(&head, position);

    printf("\nApós a exclusão, a nova lista é:\n");
    displayList(head);

    return 0;
}
