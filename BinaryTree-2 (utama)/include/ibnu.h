#ifndef IBNU_H
#define IBNU_H
#include "fairuz.h"

// Deklarasi fungsi-fungsi
int searchNode(Node* tree, int value);  
int getHeight(Node* tree);              
int countNodes(Node* tree);             
void freeTree(Node* tree);              
Node* findMinimum(Node* root);          
Node* findMaximum(Node* root);           

#endif /* IBNU_H */