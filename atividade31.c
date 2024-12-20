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

// Função para inverter pares na lista vinculada
Node* reverseInPairs(Node* head) {
    // Caso base: se a lista estiver vazia ou tiver um único nó
    if (head == NULL || head->next == NULL) {
        return head;
    }

    // Inicializa o novo cabeçalho da lista
    Node* newHead = head->next;
    Node* prev = NULL;
    Node* current = head;

    while (current != NULL && current->next != NULL) {
        Node* first = current;
        Node* second = current->next;
        
        // Inverte o par
        first->next = second->next;
        second->next = first;

        // Conecta o par invertido com a lista anterior
        if (prev != NULL) {
            prev->next = second;
        }

        // Avança para o próximo par
        prev = first;
        current = first->next;
    }

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
    // Criando a lista vinculada original (1 -> 2 -> 3 -> 4 -> 5 -> 6)
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);
    head->next->next->next->next->next = createNode(6);

    printf("Lista original:\n");
    printList(head);

    // Reverter a lista em pares
    head = reverseInPairs(head);

    printf("Lista após reverter em pares:\n");
    printList(head);

    // Liberando a memória
    freeList(head);

    return 0;
}
