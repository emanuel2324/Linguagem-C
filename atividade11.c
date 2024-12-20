#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura de um nó
struct Node {
    int data;
    struct Node* next;
};

// Função para criar um novo nó
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));  // Aloca memória para o nó
    newNode->data = value;  // Atribui o valor ao nó
    newNode->next = NULL;   // Inicializa o ponteiro next como NULL
    return newNode;         // Retorna o novo nó
}

// Função para inserir um novo nó no final da lista
void insertNodeAtEnd(struct Node** head, int value) {
    struct Node* newNode = createNode(value);  // Cria um novo nó
    
    // Se a lista estiver vazia, o novo nó será o primeiro
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        
        // Percorre até o último nó
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;  // Insere o novo nó no final
    }
}

// Função para converter a lista encadeada em uma string
char* linkedListToString(struct Node* head) {
    // Inicializa uma string vazia para armazenar o resultado
    char* result = (char*)malloc(1024 * sizeof(char));
    strcpy(result, "");  // Inicializa a string como vazia
    
    struct Node* temp = head;
    
    // Percorre a lista encadeada e converte os dados para string
    while (temp != NULL) {
        char buffer[50];
        sprintf(buffer, "%d ", temp->data);  // Converte o número inteiro para string
        strcat(result, buffer);  // Concatena à string resultante
        temp = temp->next;
    }
    
    return result;  // Retorna a string contendo os valores da lista
}

// Função para exibir a lista como uma string
void displayLinkedListAsString(struct Node* head) {
    char* result = linkedListToString(head);
    printf("A lista vinculada: %s\n", result);
    free(result);  // Libera a memória alocada para a string
}

int main() {
    struct Node* head = NULL;  // Inicializa a lista como vazia
    int n, value;
    
    // Inserir nós na lista
    printf("Insira o número de nós: ");
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) {
        printf("Dados de entrada para o nó %d: ", i);
        scanf("%d", &value);
        insertNodeAtEnd(&head, value);  // Insere o nó no final da lista
    }
    
    // Exibe a lista convertida para string
    displayLinkedListAsString(head);
    
    return 0;
}
