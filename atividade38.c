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

// Função para encontrar pares cuja soma é igual a um valor específico
void findPairsWithSum(Node* head, int targetSum) {
    Node* ptr1 = head;
    int found = 0;

    while (ptr1 != NULL) {
        Node* ptr2 = ptr1->next;
        while (ptr2 != NULL) {
            if (ptr1->data + ptr2->data == targetSum) {
                printf("(%d.%d) ", ptr1->data, ptr2->data);
                found = 1;
            }
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }

    if (!found) {
        printf("Par não encontrado\n");
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
    // Criando a lista vinculada (1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7)
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);
    head->next->next->next->next->next = createNode(6);
    head->next->next->next->next->next->next = createNode(7);

    printf("Lista vinculada única original:\n");
    printList(head);

    // Encontrar pares cuja soma é igual a valores específicos
    printf("Encontre um par cuja soma seja igual a 4:\n");
    findPairsWithSum(head, 4);

    printf("Encontre um par cuja soma seja igual a 11:\n");
    findPairsWithSum(head, 11);

    printf("Encontre um par cuja soma seja igual a 5:\n");
    findPairsWithSum(head, 5);

    printf("Encontre um par cuja soma seja igual a 14:\n");
    findPairsWithSum(head, 14);

    // Liberar a memória
    freeList(head);

    return 0;
}
