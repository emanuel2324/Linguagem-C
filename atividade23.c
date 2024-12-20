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

// Função para imprimir a lista vinculada
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Função para obter o comprimento da lista vinculada
int getLength(Node* head) {
    int length = 0;
    Node* temp = head;
    while (temp != NULL) {
        length++;
        temp = temp->next;
    }
    return length;
}

// Função para girar a lista vinculada para a direita em k posições
Node* rotateRight(Node* head, int k) {
    if (head == NULL || head->next == NULL || k == 0) {
        return head; // Não há necessidade de girar
    }

    // Obter o comprimento da lista vinculada
    int length = getLength(head);

    // k pode ser maior que o comprimento, ajustamos k para k % length
    k = k % length;
    if (k == 0) {
        return head; // A rotação não muda a lista
    }

    // Encontre o novo final da lista, que será (length - k)-ésimo nó
    Node* current = head;
    for (int i = 1; i < length - k; i++) {
        current = current->next;
    }

    // O novo início será o próximo nó após o novo final
    Node* newHead = current->next;
    current->next = NULL;

    // Conecte o final original ao início original
    Node* temp = newHead;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head;

    return newHead;
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
    // Criando a lista vinculada original (1 -> 3 -> 4 -> 7 -> 9)
    Node* head = createNode(1);
    head->next = createNode(3);
    head->next->next = createNode(4);
    head->next->next->next = createNode(7);
    head->next->next->next->next = createNode(9);

    printf("Lista Original:\n");
    printList(head);

    // Girando a lista para a direita em 1 posição
    head = rotateRight(head, 1);
    printf("Gire a lista vinculada para a direita em 1 casa:\n");
    printList(head);

    // Girando a lista para a direita em 2 posições
    head = rotateRight(head, 2);
    printf("Gire a lista vinculada para a direita em 2 casas:\n");
    printList(head);

    // Girando a lista para a direita em 4 posições
    head = rotateRight(head, 4);
    printf("Gire a lista vinculada para a direita em 4 casas:\n");
    printList(head);

    // Liberando a memória
    freeList(head);

    return 0;
}
