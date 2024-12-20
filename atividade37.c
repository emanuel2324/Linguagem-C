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

// Função para inverter os primeiros k nós da lista
Node* reverseKNodes(Node* head, int k) {
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;
    int count = 0;

    // Verifica se há pelo menos k nós
    Node* temp = head;
    for (int i = 0; i < k; i++) {
        if (temp == NULL) return head;
        temp = temp->next;
    }

    // Reverter os primeiros k nós
    while (current != NULL && count < k) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }

    // Conectar o bloco revertido com o próximo bloco
    if (head != NULL) {
        head->next = current;
    }

    return prev; // Novo cabeçalho do bloco revertido
}

// Função para reverter os primeiros k nós e depois os primeiros m nós
Node* reverseInBlocks(Node* head, int k, int m) {
    // Reverter os primeiros k nós
    head = reverseKNodes(head, k);

    // Reverter os primeiros m nós
    return reverseKNodes(head, m);
}

// Função para remover todos os nós com valor maior que x
Node* removeGreaterThan(Node* head, int x) {
    // Remove os nós do início que são maiores que x
    while (head != NULL && head->data > x) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }

    // Remove nós maiores que x do resto da lista
    Node* current = head;
    while (current != NULL && current->next != NULL) {
        if (current->next->data > x) {
            Node* temp = current->next;
            current->next = current->next->next;
            free(temp);
        } else {
            current = current->next;
        }
    }

    return head;
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
    // Criando a lista vinculada (1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8)
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);
    head->next->next->next->next->next = createNode(6);
    head->next->next->next->next->next->next = createNode(7);
    head->next->next->next->next->next->next->next = createNode(8);

    printf("Dada lista vinculada:\n");
    printList(head);

    // Inverter os primeiros 3 nós da lista
    head = reverseKNodes(head, 3);
    printf("Inverta os 3 primeiros nós da referida lista vinculada:\n");
    printList(head);

    // Inverter os primeiros 5 nós da lista
    head = reverseKNodes(head, 5);
    printf("Inverta os primeiros 5 nós da referida lista vinculada:\n");
    printList(head);

    // Valor x para remover todos os elementos maiores que x
    int x = 5;

    // Remover elementos maiores que x
    Node* updatedList = removeGreaterThan(head, x);
    printf("Lista vinculada após remover elementos maiores que %d:\n", x);
    printList(updatedList);

    // Liberar a memória
    freeList(updatedList);

    return 0;
}
