#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó com ponteiros 'next' e 'random'
struct Node {
    int data;
    struct Node* next;
    struct Node* random;
};

// Função para criar um novo nó
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->random = NULL;
    return newNode;
}

// Função para exibir a lista (incluindo ponteiros aleatórios)
void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("Data: %d, Aleatório: %d\n", temp->data, (temp->random ? temp->random->data : -1));
        temp = temp->next;
    }
}

// Função para copiar a lista vinculada com ponteiros aleatórios
struct Node* copyRandomList(struct Node* head) {
    if (head == NULL) {
        return NULL;
    }

    struct Node* current = head;

    // 1. Intercalar nós duplicados entre os nós originais
    while (current != NULL) {
        struct Node* newNode = createNode(current->data);
        newNode->next = current->next;
        current->next = newNode;
        current = newNode->next;
    }

    // 2. Ajustar os ponteiros aleatórios dos nós duplicados
    current = head;
    while (current != NULL) {
        if (current->random != NULL) {
            current->next->random = current->random->next;
        }
        current = current->next->next;
    }

    // 3. Separar a lista duplicada da lista original
    struct Node* original = head;
    struct Node* copy = head->next;
    struct Node* copyHead = copy;

    while (original != NULL) {
        original->next = original->next->next;
        if (copy->next != NULL) {
            copy->next = copy->next->next;
        }
        original = original->next;
        copy = copy->next;
    }

    return copyHead;
}

int main() {
    // Criar nós
    struct Node* head = createNode(1);
    struct Node* second = createNode(2);
    struct Node* third = createNode(3);
    struct Node* fourth = createNode(5);
    struct Node* fifth = createNode(7);

    // Construir a lista
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    // Definir ponteiros aleatórios
    head->random = third;    // 1 -> 3
    second->random = fourth; // 2 -> 5
    third->random = fifth;   // 3 -> 7
    fourth->random = head;   // 5 -> 1
    fifth->random = third;   // 7 -> 3

    // Exibir a lista original com ponteiros aleatórios
    printf("Lista original:\n");
    displayList(head);

    // Fazer a cópia da lista com ponteiros aleatórios
    struct Node* copiedList = copyRandomList(head);

    // Exibir a lista copiada com ponteiros aleatórios
    printf("\nLista copiada:\n");
    displayList(copiedList);

    return 0;
}
