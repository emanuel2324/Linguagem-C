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

// Função para excluir o último nó da lista
void deleteFromEnd(struct Node** head_ref) {
    if (*head_ref == NULL) {
        printf("A lista está vazia. Não há nada para excluir.\n");
        return;
    }

    struct Node* last = *head_ref;

    // Se há apenas um nó
    if (last->next == NULL) {
        *head_ref = NULL;
    } else {
        // Percorre até o último nó
        while (last->next != NULL) {
            last = last->next;
        }
        last->prev->next = NULL;  // Ajusta o ponteiro do penúltimo nó
    }

    free(last);  // Libera a memória do último nó
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
    int n, data;

    // Inserindo nós inicialmente na lista
    printf("Insira o número de nós (3 ou mais): ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        printf("Dados de entrada para o nó %d: ", i);
        scanf("%d", &data);
        append(&head, data);
    }

    displayList(head);

    // Excluir o último nó
    deleteFromEnd(&head);

    printf("\nApós a exclusão do último nó, a nova lista é:\n");
    displayList(head);

    return 0;
}
