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

// Função para dividir a lista em duas metades
void splitList(Node* head, Node** firstHalf, Node** secondHalf) {
    if (head == NULL || head->next == NULL) {
        *firstHalf = head;
        *secondHalf = NULL;
        return;
    }

    Node *slow = head, *fast = head;
    Node *prev = NULL;

    // Avançar 'fast' duas vezes e 'slow' uma vez
    while (fast != NULL && fast->next != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    // Dividir a lista em duas metades
    *firstHalf = head;
    *secondHalf = slow;
    prev->next = NULL;
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
    // Criando a lista vinculada original (1 -> 2 -> 3 -> 4 -> 5)
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    Node* firstHalf = NULL;
    Node* secondHalf = NULL;

    printf("Lista original:\n");
    printList(head);

    // Dividir a lista em duas metades
    splitList(head, &firstHalf, &secondHalf);

    printf("Primeira metade:\n");
    printList(firstHalf);
    printf("Segunda metade:\n");
    printList(secondHalf);

    // Liberar a memória
    freeList(firstHalf);
    freeList(secondHalf);

    // Criando a lista vinculada original (1 -> 2 -> 3 -> 4 -> 5 -> 6)
    head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);
    head->next->next->next->next->next = createNode(6);

    printf("Lista original:\n");
    printList(head);

    // Dividir a lista em duas metades
    splitList(head, &firstHalf, &secondHalf);

    printf("Primeira metade:\n");
    printList(firstHalf);
    printf("Segunda metade:\n");
    printList(secondHalf);

    // Liberar a memória
    freeList(firstHalf);
    freeList(secondHalf);

    return 0;
}
