#include <stdio.h>
#include <stdlib.h>

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

// Função para contar o número de nós na lista
int countNodes(struct Node* head) {
    int count = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Função para converter a lista duplamente vinculada em array
int* convertToArray(struct Node* head, int* size) {
    int count = countNodes(head);  // Contar o número de nós
    *size = count;  // Retornar o tamanho do array

    // Alocar o array dinâmicamente com o tamanho da lista
    int* array = (int*)malloc(count * sizeof(int));

    struct Node* temp = head;
    int i = 0;
    
    // Copiar os dados da lista para o array
    while (temp != NULL) {
        array[i++] = temp->data;
        temp = temp->next;
    }

    return array;  // Retornar o array
}

int main() {
    struct Node* head = NULL;
    int n, data;
    int arraySize;

    // Inserindo nós na lista duplamente vinculada
    printf("Insira o número de nós: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        printf("Dados de entrada para o nó %d: ", i);
        scanf("%d", &data);
        append(&head, data);
    }

    // Converter a lista duplamente vinculada em array
    int* array = convertToArray(head, &arraySize);

    // Exibir o array
    printf("Lista duplamente vinculada em formato de array:\n");
    for (int i = 0; i < arraySize; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Liberar a memória alocada para o array
    free(array);

    return 0;
}
