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

// Função para reordenar a lista vinculada
Node* reorderList(Node* head) {
    Node *evenHead = NULL, *oddHead = NULL;
    Node *evenTail = NULL, *oddTail = NULL;
    Node *current = head;

    // Separar a lista em pares e ímpares
    while (current != NULL) {
        if (current->data % 2 == 0) {
            // Inserir nó par na lista de pares
            if (evenHead == NULL) {
                evenHead = evenTail = createNode(current->data);
            } else {
                evenTail->next = createNode(current->data);
                evenTail = evenTail->next;
            }
        } else {
            // Inserir nó ímpar na lista de ímpares
            if (oddHead == NULL) {
                oddHead = oddTail = createNode(current->data);
            } else {
                oddTail->next = createNode(current->data);
                oddTail = oddTail->next;
            }
        }
        current = current->next;
    }

    // Concatenar listas de pares e ímpares
    if (evenTail != NULL) {
        evenTail->next = oddHead;
    } else {
        evenHead = oddHead;
    }

    return evenHead;
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
    // Criando a lista vinculada original (1 -> 2 -> 3 -> 4 -> 5 -> 6)
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);
    head->next->next->next->next->next = createNode(6);

    printf("Lista original:\n");
    printList(head);

    // Reordenar a lista colocando pares à frente dos ímpares
    head = reorderList(head);

    printf("Lista após reordenamento:\n");
    printList(head);

    // Liberando a memória
    freeList(head);

    return 0;
}
