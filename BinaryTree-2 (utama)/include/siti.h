#ifndef SITI_H
#define SITI_H
#include "fairuz.h"

// Deklarasi fungsi
Node* deleteNodeIterative(Node* root, int data);
void levelOrderTraversal(Node* root);
Node* findPredecessor(Node* root, int data);
Node* findSuccessor(Node* root, int data);
void printTree(struct Node *root, int space);

#endif
