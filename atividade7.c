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
    newNode->next = NULL;   // Inicializa o próximo nó como NULL
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

// Função para inserir um nó no meio da lista em uma posição específica
void insertAtPosition(struct Node** head, int value, int position) {
    struct Node* newNode = createNode(value);  // Cria o novo nó
    
    // Se a posição for 1, insere o nó no início da lista
    if (position == 1) {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    
    struct Node* temp = *head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;  // Percorre até o nó anterior à posição desejada
    }
    
    // Verifica se a posição é válida e insere o nó na posição
    if (temp != NULL) {
        newNode->next = temp->next;
        temp->next = newNode;
        printf("Inserção concluída com sucesso.\n");
    } else {
        printf("Posição inválida!\n");
        free(newNode);  // Libera a memória caso a posição seja inválida
    }
}

// Função para excluir um nó da lista em uma posição específica
void deleteAtPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("A lista está vazia.\n");
        return;
    }

    struct Node* temp = *head;

    // Se o nó a ser removido for o primeiro
    if (position == 1) {
        *head = temp->next;  // Muda a cabeça para o próximo nó
        free(temp);  // Libera o nó antigo
        printf("Nó na posição 1 excluído com sucesso.\n");
        return;
    }

    // Percorre até o nó anterior ao que será excluído
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    // Verifica se a posição é válida
    if (temp == NULL || temp->next == NULL) {
        printf("Posição inválida!\n");
        return;
    }

    struct Node* nodeToDelete = temp->next;  // Nó a ser excluído
    temp->next = nodeToDelete->next;  // Ajusta o ponteiro para pular o nó excluído
    free(nodeToDelete);  // Libera a memória do nó excluído
    printf("Nó na posição %d excluído com sucesso.\n", position);
}

int main() {
    struct Node* head = NULL;  // Inicializa a lista como vazia
    int n, value, position;
    
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
    
    // Inserção de um nó no meio da lista
    printf("\nDados de entrada para inserir no meio da lista: ");
    scanf("%d", &value);
    printf("Insira a posição para inserir o novo nó: ");
    scanf("%d", &position);
    
    insertAtPosition(&head, value, position);  // Insere o nó na posição desejada
    
    // Exibe a lista atualizada
    printf("\nA nova lista é:\n");
    displayList(head);
    
    // Exclusão de um nó da lista
    printf("\nInsira a posição do nó a ser excluído: ");
    scanf("%d", &position);
    
    deleteAtPosition(&head, position);  // Exclui o nó na posição especificada
    
    // Exibe a lista atualizada após exclusão
    printf("\nLista após exclusão:\n");
    displayList(head);
    
    return 0;
}
