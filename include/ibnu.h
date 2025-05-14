/**
 * BinaryTree.h - Header file untuk ADT Binary Tree
 * Deklarasi struktur data dan fungsi-fungsi untuk Binary Tree
 */

#ifndef BINARY_TREE_H
#define BINARY_TREE_H

// Struktur untuk Node pada Binary Tree
typedef struct node {
    int data;              // Nilai dari node
    struct node* left;     // Pointer ke anak kiri
    struct node* right;    // Pointer ke anak kanan
} Node;

// Definisi ADT BinaryTree
typedef struct binaryTree {
    Node* root;            // Pointer ke node root
} BinaryTree;

// Deklarasi fungsi-fungsi
BinaryTree* createEmpty();                    // Membuat tree kosong
Node* createNode(int value);                  // Membuat node baru
void insertNode(BinaryTree* tree, int value); // Tambah node
int searchNode(BinaryTree* tree, int value);  // Cari node
int getHeight(BinaryTree* tree);              // Hitung tinggi tree
int countNodes(BinaryTree* tree);             // Hitung jumlah node
int findMaximum(BinaryTree* tree);            // Cari node maksimum
void freeTree(BinaryTree* tree);              // Membersihkan memori tree

#endif /* BINARY_TREE_H */