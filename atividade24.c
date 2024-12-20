#include <stdio.h>
#include <stdlib.h>

// Definição do nó da lista vinculada
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

// Função para obter o comprimento da lista vinculada
int getLength(Node* head) {
    int length = 0;
    Node* temp = head;
    while (temp != NULL) {
        length++;
        temp = temp->next;
    }
    return length;
}

// Função para trocar o k-ésimo nó do início com o k-ésimo nó do final
Node* swapKthNodes(Node* head, int k) {
    int length = getLength(head);

    // Verifica se k é válido
    if (k > length || k <= 0) {
        printf("O valor de k é inválido.\n");
        return head;
    }

    // Se o nó do início e do final for o mesmo, não precisa trocar
    if (2 * k - 1 == length) {
        return head;
    }

    Node *first = head, *firstPrev = NULL;
    Node *second = head, *secondPrev = NULL;

    // Encontrar o k-ésimo nó do início e seu nó anterior
    for (int i = 1; i < k; i++) {
        firstPrev = first;
        first = first->next;
    }

    // Encontrar o k-ésimo nó do final e seu nó anterior
    for (int i = 1; i < length - k + 1; i++) {
        secondPrev = second;
        second = second->next;
    }

    // Se o primeiro nó anterior não é nulo, ajustar o ponteiro para o primeiro nó
    if (firstPrev != NULL) {
        firstPrev->next = second;
    } else {
        head = second;  // Quando o primeiro nó é o próprio head
    }

    // Se o segundo nó anterior não é nulo, ajustar o ponteiro para o segundo nó
    if (secondPrev != NULL) {
        secondPrev->next = first;
    } else {
        head = first;  // Quando o segundo nó é o próprio head
    }

    // Trocar os ponteiros "next" dos dois nós
    Node* temp = first->next;
    first->next = second->next;
    second->next = temp;

    return head;
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
    // Criando a lista vinculada original (1 -> 3 -> 4 -> 7 -> 9)
    Node* head = createNode(1);
    head->next = createNode(3);
    head->next->next = createNode(4);
    head->next->next->next = createNode(7);
    head->next->next->next->next = createNode(9);

    printf("Lista Original:\n");
    printList(head);

    int k;

    // Troca o k-ésimo nó do início e do final
    k = 2;
    head = swapKthNodes(head, k);
    printf("Lista após troca do %d-ésimo nó do início com o %d-ésimo nó do final:\n", k, k);
    printList(head);

    // Troca o k-ésimo nó do início e do final
    k = 3;
    head = swapKthNodes(head, k);
    printf("Lista após troca do %d-ésimo nó do início com o %d-ésimo nó do final:\n", k, k);
    printList(head);

    // Liberando a memória
    freeList(head);

    return 0;
}
