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

// Função para remover os nós com índices pares
Node* removeEvenIndexedNodes(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;  // Lista vazia ou com apenas um elemento
    }

    Node* current = head->next;  // Começa no segundo nó (índice 1)
    Node* prev = head;
    int index = 1;

    while (current != NULL) {
        if (index % 2 == 1) {
            // Se o índice anterior é par, removemos o nó atual (índice par)
            prev->next = current->next;
            free(current);
        } else {
            prev = prev->next;
        }

        // Avançar para o próximo nó
        if (prev != NULL) {
            current = prev->next;
        } else {
            break;
        }

        index++;
    }

    // Remove o primeiro nó (índice 0), se necessário
    if (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
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
    // Criando a lista vinculada original (7 -> 6 -> 5 -> 4 -> 3 -> 2 -> 1)
    Node* head = createNode(7);
    head->next = createNode(6);
    head->next->next = createNode(5);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(3);
    head->next->next->next->next->next = createNode(2);
    head->next->next->next->next->next->next = createNode(1);

    printf("Lista vinculada original:\n");
    printList(head);

    // Removendo nós de índices pares
    head = removeEvenIndexedNodes(head);
    printf("Lista vinculada após remoção de índices pares:\n");
    printList(head);

    // Liberando a memória
    freeList(head);

    return 0;
}
