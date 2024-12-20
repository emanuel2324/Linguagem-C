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

// Função para particionar a lista em torno de um valor específico
Node* partitionList(Node* head, int partitionValue) {
    Node* lessHead = NULL;
    Node* lessTail = NULL;
    Node* greaterHead = NULL;
    Node* greaterTail = NULL;

    Node* current = head;

    // Separar os nós em duas listas
    while (current != NULL) {
        if (current->data < partitionValue) {
            if (lessHead == NULL) {
                lessHead = current;
                lessTail = lessHead;
            } else {
                lessTail->next = current;
                lessTail = current;
            }
        } else {
            if (greaterHead == NULL) {
                greaterHead = current;
                greaterTail = greaterHead;
            } else {
                greaterTail->next = current;
                greaterTail = current;
            }
        }
        current = current->next;
    }

    // Finaliza a lista maior
    if (greaterTail != NULL) {
        greaterTail->next = NULL;
    }

    // Junta as duas listas
    if (lessTail != NULL) {
        lessTail->next = greaterHead;
        return lessHead;
    } else {
        return greaterHead;
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
    // Criando uma lista vinculada
    Node* head = createNode(3);
    head->next = createNode(5);
    head->next->next = createNode(7);
    head->next->next->next = createNode(5);
    head->next->next->next->next = createNode(9);
    head->next->next->next->next->next = createNode(2);
    head->next->next->next->next->next->next = createNode(1);

    printf("Lista original:\n");
    printList(head);

    int partitionValue = 5;
    Node* partitionedHead = partitionList(head, partitionValue);

    printf("Lista vinculada após partição em torno de %d:\n", partitionValue);
    printList(partitionedHead);

    // Liberando a memória
    freeList(partitionedHead);

    return 0;
}
