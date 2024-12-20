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

// Função para excluir nós alternativos
Node* deleteAlternateNodes(Node* head) {
    Node* current = head;

    // Iterar através da lista
    while (current != NULL && current->next != NULL) {
        Node* nextNode = current->next;  // Nó a ser excluído
        current->next = nextNode->next;  // Conectar o nó atual ao próximo do nó a ser excluído
        free(nextNode);  // Liberar a memória do nó excluído
        current = current->next;  // Avançar para o próximo nó
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
    // Criando a lista vinculada original (1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7)
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);
    head->next->next->next->next->next = createNode(6);
    head->next->next->next->next->next->next = createNode(7);

    printf("Lista original:\n");
    printList(head);

    // Excluir nós alternativos
    head = deleteAlternateNodes(head);

    printf("Lista após excluir nós alternativos:\n");
    printList(head);

    // Liberar a memória
    freeList(head);

    return 0;
}
