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

// Função para intercala dois nós de listas vinculadas alternadamente
Node* mergeAlternately(Node* list1, Node* list2) {
    Node dummy;
    Node* tail = &dummy;
    dummy.next = NULL;

    // Itera sobre ambas as listas
    while (list1 != NULL && list2 != NULL) {
        // Adiciona o nó da lista1
        tail->next = list1;
        list1 = list1->next;
        tail = tail->next;

        // Adiciona o nó da lista2
        tail->next = list2;
        list2 = list2->next;
        tail = tail->next;
    }

    // Se houver nós restantes em list1 ou list2, adiciona-os
    if (list1 != NULL) {
        tail->next = list1;
    }
    if (list2 != NULL) {
        tail->next = list2;
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
    // Criando a Lista1 (1 -> 3 -> 5 -> 7)
    Node* list1 = createNode(1);
    list1->next = createNode(3);
    list1->next->next = createNode(5);
    list1->next->next->next = createNode(7);

    // Criando a Lista2 (2 -> 4 -> 6 -> 8)
    Node* list2 = createNode(2);
    list2->next = createNode(4);
    list2->next->next = createNode(6);
    list2->next->next->next = createNode(8);

    // Imprimir as listas originais
    printf("Listas Originais:\n");
    printf("Lista1: ");
    printList(list1);
    printf("Lista2: ");
    printList(list2);

    // Intercalar as listas
    Node* mergedList = mergeAlternately(list1, list2);

    // Imprimir a lista mesclada
    printf("Depois de intercalar as duas listas vinculadas alternativamente:\n");
    printList(mergedList);

    // Liberar a memória
    freeList(mergedList);

    return 0;
}
