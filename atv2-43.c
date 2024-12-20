#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da lista duplamente vinculada
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// Função para criar um novo nó
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Função para exibir a lista duplamente vinculada
void displayList(Node* head) {
    Node* temp = head;
    int index = 1;
    printf("Os dados inseridos na lista são:\n");
    while (temp != NULL) {
        printf("nó %d: %d\n", index, temp->data);
        temp = temp->next;
        index++;
    }
}

// Função para liberar a memória da lista duplamente vinculada
void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int numNodes;
    Node *head = NULL, *tail = NULL, *temp = NULL;

    // Ler o número de nós
    printf("Insira o número de nós: ");
    scanf("%d", &numNodes);

    // Ler os dados dos nós e criar a lista
    for (int i = 0; i < numNodes; i++) {
        int data;
        printf("Dados de entrada para o nó %d: ", i + 1);
        scanf("%d", &data);

        // Criar um novo nó
        Node* newNode = createNode(data);

        // Adicionar o novo nó à lista
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Exibir a lista
    displayList(head);

    // Liberar a memória
    freeList(head);

    return 0;
}
