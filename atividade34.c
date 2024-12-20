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

// Função para mesclar nós alternativos de duas listas vinculadas
Node* mergeAlternateNodes(Node* list1, Node* list2) {
    Node* mergedHead = NULL;
    Node* mergedTail = NULL;

    while (list1 != NULL || list2 != NULL) {
        // Adicionar nó da primeira lista
        if (list1 != NULL) {
            if (mergedHead == NULL) {
                mergedHead = mergedTail = createNode(list1->data);
            } else {
                mergedTail->next = createNode(list1->data);
                mergedTail = mergedTail->next;
            }
            list1 = list1->next;
        }

        // Adicionar nó da segunda lista
        if (list2 != NULL) {
            if (mergedHead == NULL) {
                mergedHead = mergedTail = createNode(list2->data);
            } else {
                mergedTail->next = createNode(list2->data);
                mergedTail = mergedTail->next;
            }
            list2 = list2->next;
        }
    }

    return mergedHead;
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
    // Criando a primeira lista vinculada (9 -> 7 -> 5 -> 3 -> 1)
    Node* list1 = createNode(9);
    list1->next = createNode(7);
    list1->next->next = createNode(5);
    list1->next->next->next = createNode(3);
    list1->next->next->next->next = createNode(1);

    // Criando a segunda lista vinculada (10 -> 8 -> 6 -> 4 -> 2)
    Node* list2 = createNode(10);
    list2->next = createNode(8);
    list2->next->next = createNode(6);
    list2->next->next->next = createNode(4);
    list2->next->next->next->next = createNode(2);

    printf("Primeira lista vinculada:\n");
    printList(list1);

    printf("Segunda lista vinculada:\n");
    printList(list2);

    // Mesclar os nós alternativos de duas listas vinculadas
    Node* mergedList = mergeAlternateNodes(list1, list2);

    printf("Lista vinculada mesclada:\n");
    printList(mergedList);

    // Liberar a memória
    freeList(mergedList);

    return 0;
}
