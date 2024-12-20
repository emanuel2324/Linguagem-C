#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da lista vinculada
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Função para criar um novo nó
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Função para imprimir a lista vinculada
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Função para remover o enésimo nó do final da lista
Node* removeNthFromEnd(Node* head, int n) {
    Node* dummy = createNode(0);  // Nó fictício para simplificar os casos de remoção
    dummy->next = head;
    
    Node* first = dummy;
    Node* second = dummy;

    // Mover o primeiro ponteiro n+1 posições à frente para criar uma distância de n nós entre o primeiro e o segundo
    for (int i = 0; i <= n; i++) {
        if (first == NULL) return head;  // Se n for maior que o tamanho da lista, não faça nada
        first = first->next;
    }

    // Agora mova ambos os ponteiros até que o primeiro alcance o final
    while (first != NULL) {
        first = first->next;
        second = second->next;
    }

    // O segundo estará no nó anterior ao que precisa ser removido
    Node* temp = second->next;
    second->next = second->next->next;
    free(temp);

    Node* newHead = dummy->next;  // Guardar o novo cabeçalho da lista
    free(dummy);  // Liberar o nó fictício
    return newHead;
}

// Função para liberar a memória da lista
void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    // Criando a lista vinculada original (1 -> 2 -> 3 -> 4 -> 5)
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    printf("Lista original:\n");
    printList(head);

    // Removendo o 1º nó do final (o último nó)
    head = removeNthFromEnd(head, 1);
    printf("Remova o primeiro nó do final da lista:\n");
    printList(head);

    // Removendo o 3º nó do final
    head = removeNthFromEnd(head, 3);
    printf("Remova o terceiro nó do final da lista:\n");
    printList(head);

    // Liberando a memória
    freeList(head);

    return 0;
}
