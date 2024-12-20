#include <stdio.h>
#include <stdlib.h>

// Estrutura de um nó
struct Node {
    int data;
    struct Node* next;
};

// Função para criar um novo nó
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Função para inserir um novo nó no final da lista
void insertNodeAtEnd(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Função para exibir a lista
void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Função para calcular o comprimento de uma lista vinculada
int getLength(struct Node* head) {
    int length = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        length++;
        temp = temp->next;
    }
    return length;
}

// Função para encontrar a interseção de duas listas
struct Node* findIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);
    
    // Ajusta o ponteiro da lista maior
    if (len1 > len2) {
        for (int i = 0; i < len1 - len2; i++) {
            head1 = head1->next;
        }
    } else if (len2 > len1) {
        for (int i = 0; i < len2 - len1; i++) {
            head2 = head2->next;
        }
    }
    
    // Percorre ambas as listas simultaneamente
    while (head1 != NULL && head2 != NULL) {
        if (head1 == head2) {
            return head1;  // Interseção encontrada
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    
    return NULL;  // Nenhuma interseção encontrada
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    struct Node* intersectionNode;

    // Inserindo nós na primeira lista
    insertNodeAtEnd(&list1, 1);
    insertNodeAtEnd(&list1, 2);
    insertNodeAtEnd(&list1, 3);
    insertNodeAtEnd(&list1, 4);

    // Inserindo nós na segunda lista
    insertNodeAtEnd(&list2, 5);

    // Criando uma interseção (segunda lista aponta para um nó da primeira lista)
    list2->next = list1->next->next;  // Faz a segunda lista intersectar no nó 3 da primeira lista

    // Exibindo as listas originais
    printf("Lista 1: ");
    displayList(list1);

    printf("Lista 2: ");
    displayList(list2);

    // Encontrar a interseção
    intersectionNode = findIntersection(list1, list2);

    if (intersectionNode != NULL) {
        printf("Interseção encontrada em %d.\n", intersectionNode->data);
    } else {
        printf("Interseção não encontrada.\n");
    }

    return 0;
}
