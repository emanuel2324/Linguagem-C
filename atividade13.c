#include <stdio.h>
#include <stdlib.h>  // Para malloc e free
#include <string.h>  // Para manipulação de strings

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
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Função para mesclar duas listas classificadas
struct Node* mergeSortedLists(struct Node* list1, struct Node* list2) {
    // Caso base: se uma das listas estiver vazia, retorna a outra lista
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;
    
    struct Node* mergedHead = NULL;

    // Comparar os dados dos dois nós e construir a lista mesclada
    if (list1->data <= list2->data) {
        mergedHead = list1;
        mergedHead->next = mergeSortedLists(list1->next, list2);
    } else {
        mergedHead = list2;
        mergedHead->next = mergeSortedLists(list1, list2->next);
    }
    
    return mergedHead;
}

// Função para converter uma lista vinculada em uma string
char* linkedListToString(struct Node* head) {
    char* result = (char*)malloc(1024 * sizeof(char));  // Aloca memória para a string
    result[0] = '\0';  // Inicializa a string como vazia
    
    struct Node* temp = head;
    char buffer[50];
    
    while (temp != NULL) {
        sprintf(buffer, "%d ", temp->data);  // Converte o número em string
        strcat(result, buffer);  // Concatena o número à string result
        temp = temp->next;
    }
    
    return result;
}

// Função para exibir a lista como uma string
void displayLinkedListAsString(struct Node* head) {
    char* result = linkedListToString(head);
    printf("A lista vinculada: %s\n", result);
    free(result);  // Libera a memória alocada para a string
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    
    // Inserindo nós na primeira lista
    insertNodeAtEnd(&list1, 1);
    insertNodeAtEnd(&list1, 3);
    insertNodeAtEnd(&list1, 5);
    insertNodeAtEnd(&list1, 7);
    
    // Inserindo nós na segunda lista
    insertNodeAtEnd(&list2, 2);
    insertNodeAtEnd(&list2, 4);
    insertNodeAtEnd(&list2, 6);
    
    // Exibindo as duas listas antes da mesclagem
    printf("Lista 1: ");
    displayList(list1);
    
    printf("Lista 2: ");
    displayList(list2);
    
    // Mesclar as duas listas classificadas
    struct Node* mergedList = mergeSortedLists(list1, list2);
    
    // Exibir a lista mesclada
    printf("Depois de mesclar as duas listas classificadas:\n");
    displayList(mergedList);
    
    // Exibir a lista como uma string
    displayLinkedListAsString(mergedList);
    
    return 0;
}
