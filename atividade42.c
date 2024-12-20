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

// Função para encontrar a interseção de duas listas vinculadas
Node* findIntersection(Node* head1, Node* head2) {
    if (head1 == NULL || head2 == NULL) return NULL;

    Node* current1 = head1;
    Node* current2 = head2;
    int len1 = 0, len2 = 0;

    // Calcular o comprimento da lista 1
    while (current1 != NULL) {
        len1++;
        current1 = current1->next;
    }

    // Calcular o comprimento da lista 2
    while (current2 != NULL) {
        len2++;
        current2 = current2->next;
    }

    // Ajustar os ponteiros para o início das listas
    current1 = head1;
    current2 = head2;

    // Ajustar o início da lista mais longa
    if (len1 > len2) {
        for (int i = 0; i < len1 - len2; i++) {
            current1 = current1->next;
        }
    } else {
        for (int i = 0; i < len2 - len1; i++) {
            current2 = current2->next;
        }
    }

    // Encontrar o ponto de interseção
    while (current1 != NULL && current2 != NULL) {
        if (current1 == current2) {
            return current1;
        }
        current1 = current1->next;
        current2 = current2->next;
    }

    return NULL;
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
    // Criando e conectando listas com interseção
    Node* list1 = createNode(1);
    list1->next = createNode(2);
    list1->next->next = createNode(7);

    Node* list2 = createNode(3);
    list2->next = createNode(4);
    list2->next->next = createNode(5);
    list2->next->next->next = list1->next->next; // interseção em 7

    printf("Lista-1: ");
    printList(list1);
    printf("Lista-2: ");
    printList(list2);

    Node* intersection = findIntersection(list1, list2);

    if (intersection != NULL) {
        printf("Interseção encontrada no nó com dados: %d\n", intersection->data);
    } else {
        printf("Nenhum cruzamento encontrado.\n");
    }

    // Criando e conectando listas sem interseção
    Node* list3 = createNode(1);
    list3->next = createNode(2);
    list3->next->next = createNode(5);

    Node* list4 = createNode(3);
    list4->next = createNode(4);
    list4->next->next = createNode(5);
    list4->next->next->next = createNode(7);

    printf("Lista-3: ");
    printList(list3);
    printf("Lista-4: ");
    printList(list4);

    intersection = findIntersection(list3, list4);

    if (intersection != NULL) {
        printf("Interseção encontrada no nó com dados: %d\n", intersection->data);
    } else {
        printf("Nenhum cruzamento encontrado.\n");
    }

    // Liberar a memória
    freeList(list1);
    freeList(list2);
    freeList(list3);
    freeList(list4);

    return 0;
}
