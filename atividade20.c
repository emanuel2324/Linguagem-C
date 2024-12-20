#include <stdio.h>
#include <stdlib.h>

// Definição do nó da lista vinculada
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

// Função para imprimir a lista
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Função para imprimir os últimos n nós da lista
void printLastNNodes(Node* head, int n) {
    Node* mainPtr = head;
    Node* refPtr = head;

    // Move refPtr para a posição n na lista
    int count = 0;
    while (count < n) {
        if (refPtr == NULL) {
            printf("A lista tem menos de %d nós.\n", n);
            return;
        }
        refPtr = refPtr->next;
        count++;
    }

    // Move ambos os ponteiros até refPtr chegar ao final da lista
    while (refPtr != NULL) {
        mainPtr = mainPtr->next;
        refPtr = refPtr->next;
    }

    // Imprime os últimos n nós
    while (mainPtr != NULL) {
        printf("%d ", mainPtr->data);
        mainPtr = mainPtr->next;
    }
    printf("\n");
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
    // Criando uma lista vinculada
    Node* head = createNode(1);
    head->next = createNode(3);
    head->next->next = createNode(5);
    head->next->next->next = createNode(11);

    printf("Lista original:\n");
    printList(head);

    // Testando a função para diferentes valores de n
    printf("Últimos 2 nós do final da referida lista única:\n");
    printLastNNodes(head, 2);

    printf("Últimos 3 nós do final da referida lista única:\n");
    printLastNNodes(head, 3);

    printf("Últimos 4 nós do final da referida lista única:\n");
    printLastNNodes(head, 4);

    printf("Último 1 nó do final da referida lista única:\n");
    printLastNNodes(head, 1);

    printf("Últimos 5 nós do final da referida lista única:\n");
    printLastNNodes(head, 5);

    // Liberando a memória
    freeList(head);

    return 0;
}
