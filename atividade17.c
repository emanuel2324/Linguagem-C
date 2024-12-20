#include <stdio.h>
#include <stdlib.h>

// Estrutura de um nó da lista vinculada
struct Node {
    int data;
    struct Node* next;
};

// Função para criar um novo nó
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Função para inserir um novo nó no final da lista
void insertNodeAtEnd(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
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

// Função para dividir a lista em duas metades
void splitList(struct Node* head, struct Node** front, struct Node** back) {
    struct Node* slow = head;
    struct Node* fast = head->next;
    
    // Usando o método de dois ponteiros para dividir a lista em duas metades
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    
    // 'slow' estará no ponto médio da lista
    *front = head;
    *back = slow->next;
    slow->next = NULL;
}

// Função para mesclar duas listas classificadas
struct Node* mergeSortedLists(struct Node* list1, struct Node* list2) {
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

// Função de classificação por mesclagem (merge sort)
void mergeSort(struct Node** head) {
    struct Node* h = *head;
    struct Node* front = NULL;
    struct Node* back = NULL;

    // Caso base: lista vazia ou com um único nó
    if (h == NULL || h->next == NULL) {
        return;
    }

    // Dividir a lista em duas metades
    splitList(h, &front, &back);

    // Classificar recursivamente as duas metades
    mergeSort(&front);
    mergeSort(&back);

    // Mesclar as duas metades classificadas
    *head = mergeSortedLists(front, back);
}

int main() {
    struct Node* head = NULL;
    
    // Inserir os dados da lista
    insertNodeAtEnd(&head, 2);
    insertNodeAtEnd(&head, 3);
    insertNodeAtEnd(&head, 1);
    insertNodeAtEnd(&head, 7);
    insertNodeAtEnd(&head, 5);
    
    // Exibir a lista antes da classificação
    printf("Lista original:\n");
    displayList(head);
    
    // Classificar a lista usando classificação por mesclagem
    mergeSort(&head);
    
    // Exibir a lista após a classificação
    printf("Lista após a classificação por mesclagem:\n");
    displayList(head);
    
    return 0;
}
