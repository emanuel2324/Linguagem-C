#include <stdio.h>
#include <stdlib.h>

// Definir a estrutura de um nó
struct Node { 
    int data;               // Aqui vai armazenar o dado do nó
    struct Node* next;      // Ponteiro para o próximo nó
};

// Criar novos nós
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); // Aloca memória para um novo nó
    newNode->data = value;  // Atribui o valor ao nó
    newNode->next = NULL;   // Inicialmente, o ponteiro para o próximo é NULL
    return newNode;         // Retorna o novo nó
}

// Inserir novo nó no final da lista
void insertNodeAtEnd(struct Node** head, int value) {
    struct Node* newNode = createNode(value);  // Cria um novo nó
    
    // Se a lista estiver vazia, o novo nó será o primeiro
    if (*head == NULL) {
        *head = newNode;  // O novo nó se torna a cabeça da lista
    } else {
        struct Node* temp = *head;
        
        // Percorre até o último nó
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;  // Insere o novo nó no final
    }
}

// Exibir a lista na ordem de inserção
void displayList(struct Node* head) {
    struct Node* temp = head;
    printf("Os dados inseridos na lista são:\n");
    while (temp != NULL) {
        printf("Data = %d\n", temp->data);
        temp = temp->next;
    }
}

int main() {
    struct Node* head = NULL;  // Inicializa a lista como vazia
    int n, value;
    
    // Inserção inicial de nós na lista
    printf("Insira o número de nós: ");
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) {
        printf("Dados de entrada para o nó %d: ", i);
        scanf("%d", &value);
        insertNodeAtEnd(&head, value);  // Insere o nó no final da lista
    }
    
    // Exibe a lista após inserção inicial
    displayList(head);
    
    // Inserir novo nó no final
    printf("\nDados de entrada para inserir no final da lista: ");
    scanf("%d", &value);
    insertNodeAtEnd(&head, value);  // Insere o nó no final da lista
    
    // Exibe a lista após inserir novo nó no final
    printf("\nOs dados, depois de inseridos na lista são:\n");
    displayList(head);
    
    return 0;
}
