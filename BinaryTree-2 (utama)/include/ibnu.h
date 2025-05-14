#ifndef IBNU_H
#define IBNU_H
#include "fairuz.h"

// Deklarasi fungsi-fungsi
int searchNode(Node* tree, int value);  // Cari node
int getHeight(Node* tree);              // Hitung tinggi tree
int countNodes(Node* tree);             // Hitung jumlah node
void freeTree(Node* tree);              // Membersihkan memori tree
Node* findMinimum(Node* root);          // Cari nilai minimum
Node* findMaximum(Node* root);           // Cari nilai maksimum

#endif /* IBNU_H */