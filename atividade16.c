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

// Função para remover duplicatas de uma lista não classificada
void removeDuplicates(struct Node* head) {
    struct Node *current = head, *prev = NULL;
    struct Node *temp = NULL, *duplicate = NULL;
    
    // Para cada nó, compare com os nós seguintes
    while (current != NULL && current->next != NULL) {
        prev = current;
        temp = current->next;
        
        while (temp != NULL) {
            if (current->data == temp->data) {
                // Se o valor for duplicado, remova o nó
                duplicate = temp;
                prev->next = temp->next;
                free(duplicate);
                temp = prev->next;
            } else {
                prev = temp;
                temp = temp->next;
            }
        }
        current = current->next;
    }
}

int main() {
    struct Node* head = NULL;
    
    // Inserindo nós na lista
    insertNodeAtEnd(&head, 1);
    insertNodeAtEnd(&head, 2);
    insertNodeAtEnd(&head, 3);
    insertNodeAtEnd(&head, 3);
    insertNodeAtEnd(&head, 4);
    
    // Exibir a lista original
    printf("Lista original:\n");
    displayList(head);
    
    // Remover duplicatas
    removeDuplicates(head);
    
    // Exibir a lista após remover duplicatas
    printf("Depois de remover elementos duplicados:\n");
    displayList(head);
    
    return 0;
}
