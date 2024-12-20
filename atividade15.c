#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

// Função para reverter uma lista vinculada
struct Node* reverseList(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;
    
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    return prev;
}

// Função para verificar se uma lista vinculada é um palíndromo
bool isPalindrome(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        return true;
    }
    
    // Encontrar o meio da lista usando dois ponteiros
    struct Node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    // Reverter a segunda metade da lista
    struct Node* secondHalf = reverseList(slow);
    struct Node* copySecondHalf = secondHalf;  // Para restaurar a lista depois
    
    // Comparar a primeira metade com a segunda metade
    struct Node* firstHalf = head;
    bool palindrome = true;
    while (secondHalf != NULL) {
        if (firstHalf->data != secondHalf->data) {
            palindrome = false;
            break;
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }
    
    // Restaurar a segunda metade da lista
    reverseList(copySecondHalf);
    
    return palindrome;
}

int main() {
    struct Node* head = NULL;
    
    // Inserindo nós na lista
    insertNodeAtEnd(&head, 1);
    insertNodeAtEnd(&head, 2);
    insertNodeAtEnd(&head, 2);
    insertNodeAtEnd(&head, 1);
    
    // Exibir a lista original
    printf("Lista original:\n");
    displayList(head);
    
    // Verificar se a lista é um palíndromo
    if (isPalindrome(head)) {
        printf("A lista vinculada é um palíndromo.\n");
    } else {
        printf("A lista vinculada não é um palíndromo.\n");
    }
    
    return 0;
}
