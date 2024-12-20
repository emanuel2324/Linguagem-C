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

// Inserir novo nó
void insertNode(struct Node** head, int value) {
    struct Node* newNode = createNode(value);  // Cria um novo nó
    
    // Se estiver vazio, o novo nó será o primeiro
    if (*head == NULL) {
        *head = newNode;  // Atribuição para o primeiro nó
    } else {
        struct Node* temp = *head;
        
        // Percorrer até o último nó
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

// Exibir a lista de forma inversa (usando recursão)
void displayListReversed(struct Node* head) {
    if (head == NULL) {
        return;  // Caso base: quando o nó for NULL, não faz nada
    }
    displayListReversed(head->next);  // Chama recursivamente para o próximo nó
    printf("Data = %d\n", head->data);  // Exibe o dado após a chamada recursiva
}

int main() {
    struct Node* head = NULL;  // Inicializa a lista como vazia
    int n, value;
    
    printf("Digite o número de nós: ");
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) {
        printf("Os dados de entrada para o nó %d: ", i);
        scanf("%d", &value);
        insertNode(&head, value);  // Insere o valor na lista
    }
    
    // Exibe a lista na ordem original
    displayList(head);
    
    // Exibe a lista na ordem inversa
    printf("\nA lista invertida é:\n");
    displayListReversed(head);
    
    return 0;
}
