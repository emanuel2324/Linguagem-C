#include <stdio.h>
#include <stdlib.h>

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

// Função para exibir a lista
void displayList(struct Node* head) {
    struct Node* temp = head;
    printf("Os dados inseridos na lista são:\n");
    while (temp != NULL) {
        printf("Data = %d\n", temp->data);
        temp = temp->next;
    }
}

// Função para procurar um elemento na lista
void searchElement(struct Node* head, int element) {
    struct Node* temp = head;
    int position = 1;
    int found = 0;  // Variável para verificar se o elemento foi encontrado
    
    // Percorre a lista até encontrar o elemento ou atingir o final
    while (temp != NULL) {
        if (temp->data == element) {
            printf("Elemento encontrado no nó %d\n", position);
            found = 1;
            break;
        }
        temp = temp->next;
        position++;
    }

    // Se o elemento não for encontrado
    if (!found) {
        printf("Elemento não encontrado na lista.\n");
    }
}

int main() {
    struct Node* head = NULL;  // Inicializa a lista como vazia
    int n, value, element;
    
    // Inserir nós na lista
    printf("Insira o número de nós: ");
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) {
        printf("Dados de entrada para o nó %d: ", i);
        scanf("%d", &value);
        insertNodeAtEnd(&head, value);  // Insere o nó no final da lista
    }
    
    // Exibe a lista após a inserção
    displayList(head);
    
    // Solicitar o elemento a ser pesquisado
    printf("\nInsira o elemento a ser pesquisado: ");
    scanf("%d", &element);
    
    // Chama a função de busca
    searchElement(head, element);
    
    return 0;
}
