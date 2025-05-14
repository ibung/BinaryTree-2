#ifndef FAIRUZ_H
#define FAIRUZ_H

// Struktur Node BST
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

// Deklarasi fungsi
Node *newNode(int data);
Node *insertNode(Node *root, int data);
Node *deleteNode(Node *root, int data);
Node *minNode(Node *root);
void inorderTraversal(Node *root);
void preorderTraversal(Node *root);
void postorderTraversal(Node *root);


#endif
