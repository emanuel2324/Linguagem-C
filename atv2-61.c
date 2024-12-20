#include <stdio.h>
#include <stdlib.h>

// Estrutura de um nó da lista circular
struct Node {
    int data;
    struct Node* next;
};

// Função para criar um novo nó
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Função para adicionar um nó ao final da lista circular
void append(struct Node** head_ref, int new_data) {
    struct Node* newNode = createNode(new_data);
    struct Node* last = *head_ref;

    // Se a lista estiver vazia, o novo nó será o primeiro nó
    if (*head_ref == NULL) {
        *head_ref = newNode;
        newNode->next = *head_ref;  // Apontando o último nó para o primeiro nó
        return;
    }

    // Percorre até o último nó
    while (last->next != *head_ref) {
        last = last->next;
    }

    // Adiciona o novo nó no final
    last->next = newNode;
    newNode->next = *head_ref;
}

// Função para exibir a lista circular
void displayList(struct Node* head) {
    struct Node* temp = head;
    int node_number = 1;

    if (head == NULL) {
        printf("A lista está vazia.\n");
        return;
    }

    printf("Os dados inseridos na lista são:\n");
    do {
        printf("Dado %d = %d\n", node_number++, temp->data);
        temp = temp->next;
    } while (temp != head);
}

// Função para pesquisar um elemento na lista circular
void searchElement(struct Node* head, int element) {
    struct Node* temp = head;
    int node_number = 1;
    int found = 0;

    if (head == NULL) {
        printf("A lista está vazia.\n");
        return;
    }

    do {
        if (temp->data == element) {
            printf("Elemento encontrado no nó %d\n", node_number);
            found = 1;
            break;
        }
        temp = temp->next;
        node_number++;
    } while (temp != head);

    if (!found) {
        printf("Elemento não encontrado na lista.\n");
    }
}

int main() {
    struct Node* head = NULL;
    int n, data, element;

    // Inserindo nós na lista circular
    printf("Insira o número de nós: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        printf("Dados de entrada para o nó %d: ", i);
        scanf("%d", &data);
        append(&head, data);
    }

    displayList(head);

    // Pesquisar um elemento
    printf("Insira o elemento que deseja encontrar: ");
    scanf("%d", &element);

    searchElement(head, element);

    return 0;
}
