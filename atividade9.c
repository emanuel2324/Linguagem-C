#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura de um nó
struct Node {
    int data;
    struct Node* next;
};

// Função para criar um novo nó
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); // Aloca memória para o nó
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

// Função para exibir a lista
void displayList(struct Node* head) {
    struct Node* temp = head;
    printf("Os dados inseridos na lista são:\n");
    while (temp != NULL) {
        printf("Data = %d\n", temp->data);
        temp = temp->next;
    }
}

// Função para excluir o último nó da lista
void deleteLastNode(struct Node** head) {
    // Verifica se a lista está vazia
    if (*head == NULL) {
        printf("A lista está vazia.\n");
        return;
    }

    struct Node* temp = *head;

    // Se houver apenas um nó, ele será o último a ser removido
    if (temp->next == NULL) {
        free(temp);
        *head = NULL;
        printf("O último nó foi excluído.\n");
        return;
    }

    // Percorre até o penúltimo nó
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    // Libera o último nó
    free(temp->next);
    temp->next = NULL;  // Define o penúltimo nó como o último
    printf("O último nó foi excluído.\n");
}

int main() {
    struct Node* head = NULL;  // Inicializa a lista como vazia
    int n, value;
    
    // Insere nós na lista
    printf("Insira o número de nós: ");
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) {
        printf("Dados de entrada para o nó %d: ", i);
        scanf("%d", &value);
        insertNodeAtEnd(&head, value);  // Insere o nó no final da lista
    }
    
    // Exibe a lista após a inserção inicial
    displayList(head);
    
    // Exclui o último nó da lista
    deleteLastNode(&head);
    
    // Exibe a lista atualizada após a exclusão
    printf("\nA nova lista após a exclusão do último nó é:\n");
    displayList(head);
    
    return 0;
}
