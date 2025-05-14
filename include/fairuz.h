#ifndef TRAVERSAL_H
#define TRAVERSAL_H

#include "ibnu.h"

// Deklarasi fungsi untuk traversal
void inorderTraversal(Node *root);   // Traversal inorder
void preorderTraversal(Node *root);  // Traversal preorder
void postorderTraversal(Node *root); // Traversal postorder
int isEmpty(BinaryTree *tree);       // Cek apakah tree kosong
int findMinimum(BinaryTree *tree);   // Cari node minimum

#endif /* TRAVERSAL_H */