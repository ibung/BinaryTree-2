/**
 * BinaryTree.h - Header file untuk ADT Binary Tree
 * Deklarasi struktur data dan fungsi-fungsi untuk Binary Tree
 */

#ifndef BINARY_TREE
#define BINARY_TREE

#include "ibnu.h"

// Deklarasi fungsi-fungsi
void deleteNode(BinaryTree* tree, int value);       // Hapus node
void levelOrderTraversal(BinaryTree* tree);         // Cetak level order
int findPredecessor(BinaryTree* tree, int value);   // Cari predecessor
int findSuccessor(BinaryTree* tree, int value);     // Cari successor
void printTree(BinaryTree* tree);                   // Cetak tree
void freeTree(BinaryTree* tree);                    // Membersihkan memori tree

#endif /* BINARY_TREE */