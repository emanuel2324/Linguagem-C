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

// Função para imprimir a lista
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Função para adicionar duas listas vinculadas
Node* addLists(Node* head1, Node* head2) {
    Node dummy;
    Node* p = &dummy;
    int carry = 0;

    while (head1 != NULL || head2 != NULL || carry) {
        int sum = carry;

        if (head1 != NULL) {
            sum += head1->data;
            head1 = head1->next;
        }

        if (head2 != NULL) {
            sum += head2->data;
            head2 = head2->next;
        }

        carry = sum / 10;
        p->next = createNode(sum % 10);
        p = p->next;
    }

    return dummy.next;
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
    // Criando a primeira lista vinculada (8 -> 7 -> 9 -> 2)
    Node* list1 = createNode(8);
    list1->next = createNode(7);
    list1->next->next = createNode(9);
    list1->next->next->next = createNode(2);

    // Criando a segunda lista vinculada (2 -> 1 -> 2 -> 3)
    Node* list2 = createNode(2);
    list2->next = createNode(1);
    list2->next->next = createNode(2);
    list2->next->next->next = createNode(3);

    printf("Lista-1:\n");
    printList(list1);

    printf("Lista-2:\n");
    printList(list2);

    Node* result = addLists(list1, list2);

    printf("Adicionando as duas listas:\n");
    printList(result);

    // Liberando a memória
    freeList(list1);
    freeList(list2);
    freeList(result);

    return 0;
}
