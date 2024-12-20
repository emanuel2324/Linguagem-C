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

// Função para mesclar duas listas vinculadas classificadas
Node* mergeTwoLists(Node* l1, Node* l2) {
    Node dummy; // Nó fictício para simplificar a mesclagem
    Node* tail = &dummy;
    dummy.next = NULL;

    while (l1 != NULL && l2 != NULL) {
        if (l1->data <= l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    // Conectar a lista restante
    if (l1 != NULL) {
        tail->next = l1;
    } else {
        tail->next = l2;
    }

    return dummy.next;
}

// Função para mesclar k listas vinculadas classificadas
Node* mergeKLists(Node* lists[], int k) {
    if (k == 0) return NULL;

    Node* result = lists[0];

    for (int i = 1; i < k; i++) {
        result = mergeTwoLists(result, lists[i]);
    }

    return result;
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
    // Criando as listas vinculadas classificadas

    // Lista-1: 10 -> 20 -> 50
    Node* list1 = createNode(10);
    list1->next = createNode(20);
    list1->next->next = createNode(50);

    // Lista-2: 30 -> 40 -> 60
    Node* list2 = createNode(30);
    list2->next = createNode(40);
    list2->next->next = createNode(60);

    // Lista-3: 10 -> 70 -> 100
    Node* list3 = createNode(10);
    list3->next = createNode(70);
    list3->next->next = createNode(100);

    // Array de listas vinculadas
    Node* lists[] = { list1, list2, list3 };

    // Mesclando as listas
    Node* mergedList = mergeKLists(lists, 3);

    // Exibindo a lista mesclada
    printf("Depois de mesclar as três listas classificadas em uma lista classificada:\n");
    printList(mergedList);

    // Liberando a memória
    freeList(mergedList);

    return 0;
}
