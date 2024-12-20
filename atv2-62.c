#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura de um nó da lista duplamente vinculada
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Função para criar um novo nó
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Função para adicionar um nó ao final da lista duplamente vinculada
void append(struct Node** head_ref, int new_data) {
    struct Node* newNode = createNode(new_data);
    struct Node* last = *head_ref;

    // Se a lista estiver vazia, o novo nó será o primeiro nó
    if (*head_ref == NULL) {
        *head_ref = newNode;
        return;
    }

    // Percorre até o último nó
    while (last->next != NULL) {
        last = last->next;
    }

    // Adiciona o novo nó ao final
    last->next = newNode;
    newNode->prev = last;
}

// Função para converter a lista duplamente vinculada em string
void convertToString(struct Node* head) {
    struct Node* temp = head;
    char result[100] = ""; // String resultante que armazenará os valores

    printf("A lista duplamente vinculada em formato de string: ");

    while (temp != NULL) {
        char buffer[10];
        sprintf(buffer, "%d", temp->data);  // Converte o valor do nó para string
        strcat(result, buffer);             // Adiciona o valor à string resultante
        if (temp->next != NULL) {
            strcat(result, " ");            // Adiciona um espaço entre os números
        }
        temp = temp->next;
    }

    printf("%s\n", result);  // Exibe a string resultante
}

int main() {
    struct Node* head = NULL;
    int n, data;

    // Inserindo nós na lista duplamente vinculada
    printf("Insira o número de nós: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        printf("Dados de entrada para o nó %d: ", i);
        scanf("%d", &data);
        append(&head, data);
    }

    // Convertendo a lista para string
    convertToString(head);

    return 0;
}
