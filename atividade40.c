#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da lista vinculada
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Função para criar um novo nó
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Função para imprimir a lista vinculada
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Função para trocar cada dois nós adjacentes
void swapAdjacentNodes(Node** head) {
    Node* current = *head;
    Node* prev = NULL;

    // Caso especial: Se a lista está vazia ou contém apenas um nó
    if (current == NULL || current->next == NULL) {
        return;
    }

    *head = current->next; // Atualiza a cabeça para o segundo nó

    while (current != NULL && current->next != NULL) {
        Node* next = current->next;
        Node* nextNext = next->next;

        // Troca os nós
        next->next = current;
        current->next = nextNext;
        
        // Atualiza o ponteiro do nó anterior
        if (prev != NULL) {
            prev->next = next;
        }

        // Move os ponteiros
        prev = current;
        current = nextNext;
    }
}

// Função para liberar a memória da lista
void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    // Criando a lista vinculada (1 -> 2 -> 3 -> 4 -> 5)
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    printf("Lista Original:\n");
    printList(head);

    // Trocar cada dois nós adjacentes
    swapAdjacentNodes(&head);

    printf("Lista atualizada após trocar cada dois nós adjacentes:\n");
    printList(head);

    // Liberar a memória
    freeList(head);

    return 0;
}
