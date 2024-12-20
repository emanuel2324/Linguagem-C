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

// Função para remover duplicatas de uma lista vinculada classificada
void removeDuplicates(Node* head) {
    Node* current = head;
    
    while (current != NULL && current->next != NULL) {
        // Se o valor do nó atual é igual ao valor do próximo nó
        if (current->data == current->next->data) {
            Node* duplicate = current->next;
            current->next = current->next->next;
            free(duplicate);
        } else {
            current = current->next;
        }
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
    // Criando a lista vinculada original classificada (1 -> 2 -> 3 -> 3 -> 5 -> 6 -> 6)
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(3);
    head->next->next->next->next = createNode(5);
    head->next->next->next->next->next = createNode(6);
    head->next->next->next->next->next->next = createNode(6);

    printf("Lista vinculada classificada original:\n");
    printList(head);

    // Remover duplicatas
    removeDuplicates(head);

    printf("Lista vinculada após remover duplicatas:\n");
    printList(head);

    // Liberar a memória
    freeList(head);

    return 0;
}
