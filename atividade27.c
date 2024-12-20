#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da árvore binária
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Função para criar um novo nó da árvore
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Função para realizar a travessia in-order (em-ordem)
void inorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }

    // Primeiro, percorre o subárvore esquerda
    inorderTraversal(root->left);

    // Depois, imprime o valor do nó atual
    printf("%d ", root->data);

    // Finalmente, percorre o subárvore direita
    inorderTraversal(root->right);
}

int main() {
    // Criando os nós da árvore binária manualmente
    Node* root = createNode(10);
    root->left = createNode(20);
    root->right = createNode(30);
    root->left->left = createNode(40);
    root->left->right = createNode(50);

    // Exibindo a travessia in-order da árvore binária
    printf("Travessia in-order da árvore binária:\n");
    inorderTraversal(root);

    // Liberando a memória 
    free(root->left->left);
    free(root->left->right);
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}
