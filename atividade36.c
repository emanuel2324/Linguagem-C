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

// Função para reverter um bloco de nós
Node* reverseBlock(Node* head, int k) {
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

    // Reverter o bloco de tamanho k
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

// Função para reverter a lista vinculada em blocos de tamanho k
Node* reverseInBlocks(Node* head, int k) {
    Node* dummy = createNode(0); // Nó fictício para facilitar a manipulação
    dummy->next = head;
    Node* prevBlockEnd = dummy;
    Node* blockStart = head;

    while (blockStart != NULL) {
        Node* blockEnd = blockStart;
        for (int i = 1; i < k && blockEnd->next != NULL; i++) {
            blockEnd = blockEnd->next;
        }

        Node* nextBlockStart = blockEnd->next;
        blockEnd->next = NULL;

        Node* reversedBlockStart = reverseBlock(blockStart, k);
        prevBlockEnd->next = reversedBlockStart;
        blockStart->next = nextBlockStart;

        prevBlockEnd = blockStart;
        blockStart = nextBlockStart;
    }

    Node* resultHead = dummy->next;
    free(dummy);
    return resultHead;
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
    // Criando a lista vinculada original (1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8)
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);
    head->next->next->next->next->next = createNode(6);
    head->next->next->next->next->next->next = createNode(7);
    head->next->next->next->next->next->next->next = createNode(8);

    printf("Lista vinculada original:\n");
    printList(head);

    // Reverter os primeiros 3 nós da lista vinculada
    Node* reversedList1 = reverseInBlocks(head, 3);
    printf("Lista vinculada após inverter os 3 primeiros nós:\n");
    printList(reversedList1);

    // Reverter os primeiros 5 nós da lista vinculada
    Node* reversedList2 = reverseInBlocks(reversedList1, 5);
    printf("Lista vinculada após inverter os primeiros 5 nós:\n");
    printList(reversedList2);

    // Liberar a memória
    freeList(reversedList2);

    return 0;
}
