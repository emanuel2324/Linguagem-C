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

// Função para reverter k nós alternativos
Node* reverseKAlternatives(Node* head, int k) {
    if (k <= 0 || head == NULL) return head;

    Node dummy;
    dummy.next = head;
    Node* prevGroupEnd = &dummy;
    Node* current = head;

    while (current != NULL) {
        Node* groupStart = current;
        Node* prev = NULL;
        Node* next = NULL;
        int count = 0;

        // Reverter k nós
        while (current != NULL && count < k) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
            count++;
        }

        // Conectar o fim do grupo revertido com o próximo grupo
        prevGroupEnd->next = prev;
        groupStart->next = current;
        prevGroupEnd = groupStart;

        // Pular k nós
        count = 0;
        while (current != NULL && count < k) {
            prevGroupEnd = current;
            current = current->next;
            count++;
        }
    }

    return dummy.next;
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

    printf("Lista Original:\n");
    printList(head);

    // Reverter k nós alternativos
    int k = 2;
    Node* updatedHead = reverseKAlternatives(head, k);
    printf("Nós alternativos reversos k (k = %d) da referida lista vinculada individualmente:\n", k);
    printList(updatedHead);

    k = 3;
    updatedHead = reverseKAlternatives(head, k);
    printf("Nós alternativos reversos k (k = %d) da referida lista vinculada individualmente:\n", k);
    printList(updatedHead);

    k = 4;
    updatedHead = reverseKAlternatives(head, k);
    printf("Nós alternativos reversos k (k = %d) da referida lista vinculada individualmente:\n", k);
    printList(updatedHead);

    // Liberar a memória
    freeList(updatedHead);

    return 0;
}
