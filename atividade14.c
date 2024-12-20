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

// Função para criar um ciclo/loop na lista
void createLoop(struct Node* head, int position) {
    struct Node* temp = head;
    struct Node* loopNode = NULL;
    int count = 1;

    while (temp->next != NULL) {
        if (count == position) {
            loopNode = temp;  // Marca o nó onde o loop será criado
        }
        temp = temp->next;
        count++;
    }
    // Cria o loop
    if (loopNode != NULL) {
        temp->next = loopNode;
    }
}

// Função para detectar e remover um loop em uma lista vinculada
int detectAndRemoveLoop(struct Node* head) {
    struct Node *slow = head, *fast = head;
    
    // Detecta o loop usando ponteiros lentos e rápidos
    while (slow != NULL && fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        // Se os ponteiros lento e rápido se encontrarem, há um loop
        if (slow == fast) {
            removeLoop(head, slow);
            return 1;  // Loop encontrado e removido
        }
    }
    return 0;  // Nenhum loop encontrado
}

// Função auxiliar para remover o loop
void removeLoop(struct Node* head, struct Node* loopNode) {
    struct Node* ptr1 = head;
    struct Node* ptr2 = loopNode;

    // Encontra o início do loop
    while (ptr1->next != ptr2->next) {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    
    // Remove o loop
    ptr2->next = NULL;
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

int main() {
    struct Node* head = NULL;
    
    // Inserindo nós na lista
    insertNodeAtEnd(&head, 1);
    insertNodeAtEnd(&head, 2);
    insertNodeAtEnd(&head, 3);
    insertNodeAtEnd(&head, 4);
    insertNodeAtEnd(&head, 5);

    // Exibir a lista antes de criar o loop
    printf("Lista vinculada original:\n");
    displayList(head);
    
    // Criar um ciclo/loop (por exemplo, o último nó aponta para o nó na posição 2)
    createLoop(head, 2);
    
    // Detectar e remover o loop
    if (detectAndRemoveLoop(head)) {
        printf("Loop detectado e removido.\n");
    } else {
        printf("Nenhum loop detectado.\n");
    }

    // Exibir a lista após remover o loop
    printf("Lista depois de remover o loop:\n");
    displayList(head);

    return 0;
}
