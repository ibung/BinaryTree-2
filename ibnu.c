/**
 * BinaryTree.c - Implementasi ADT Binary Tree
 * Implementasi dari fungsi-fungsi yang dideklarasikan di BinaryTree.h
 */

#include <stdio.h>
#include <stdlib.h>
#include "ibnu.h"

// Membuat tree kosong
BinaryTree* createEmpty() {
    BinaryTree* tree = (BinaryTree*)malloc(sizeof(BinaryTree));
    if (tree != NULL) {
        tree->root = NULL;
    }
    return tree;
}

// Membuat node baru
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode != NULL) {
        newNode->data = value;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}

// 1. Cari Node - Mencari node dengan nilai tertentu dalam binary tree
int searchNode(BinaryTree* tree, int value) {
    if (tree == NULL || tree->root == NULL) {
        return 0; // Tree kosong
    }
    
    Node* current = tree->root;
    
    while (current != NULL) {
        // Jika nilai ditemukan
        if (value == current->data) {
            return 1; // true
        }
        
        // Jika nilai lebih kecil, cari di subtree kiri
        if (value < current->data) {
            current = current->left;
        } 
        // Jika nilai lebih besar, cari di subtree kanan
        else {
            current = current->right;
        }
    }
    
    // Nilai tidak ditemukan
    return 0; // false
}

// 2. Tinggi Tree - Menghitung tinggi binary tree
int getHeight(BinaryTree* tree) {
    if (tree == NULL || tree->root == NULL) {
        return -1; // Tree kosong
    }
    
    // Implementasi iteratif dengan array sebagai queue sederhana
    Node* queue[1000];  // Ukuran maksimum queue
    int front = 0;
    int rear = 0;
    
    queue[rear++] = tree->root;
    int height = -1;
    
    while (front < rear) {
        // Jumlah node di level saat ini
        int nodeCount = rear - front;
        height++;
        
        // Proses semua node di level saat ini
        while (nodeCount > 0) {
            Node* current = queue[front++];
            
            // Tambahkan anak-anak ke queue
            if (current->left != NULL) {
                queue[rear++] = current->left;
            }
            if (current->right != NULL) {
                queue[rear++] = current->right;
            }
            
            nodeCount--;
        }
    }
    
    return height;
}

// 3. Jumlah Node - Menghitung jumlah node dalam binary tree
int countNodes(BinaryTree* tree) {
    if (tree == NULL || tree->root == NULL) {
        return 0; // Tree kosong
    }
    
    // Implementasi iteratif dengan array sebagai queue sederhana
    Node* queue[1000];  // Ukuran maksimum queue
    int front = 0;
    int rear = 0;
    
    queue[rear++] = tree->root;
    int count = 0;
    
    while (front < rear) {
        Node* current = queue[front++];
        count++;
        
        // Tambahkan anak-anak ke queue
        if (current->left != NULL) {
            queue[rear++] = current->left;
        }
        if (current->right != NULL) {
            queue[rear++] = current->right;
        }
    }
    
    return count;
}

// 4. Tambah Node - Menambahkan node baru ke dalam binary tree
void insertNode(BinaryTree* tree, int value) {
    if (tree == NULL) {
        return; // Tree tidak valid
    }
    
    Node* newNode = createNode(value);
    if (newNode == NULL) {
        return; // Gagal alokasi memori
    }
    
    // Jika tree kosong, node baru menjadi root
    if (tree->root == NULL) {
        tree->root = newNode;
        return;
    }
    
    Node* current = tree->root;
    Node* parent = NULL;
    
    while (1) {
        parent = current;
        
        // Jika nilai lebih kecil, masuk ke subtree kiri
        if (value < current->data) {
            current = current->left;
            
            // Jika sudah mencapai leaf node, tambahkan di sini
            if (current == NULL) {
                parent->left = newNode;
                return;
            }
        } 
        // Jika nilai lebih besar, masuk ke subtree kanan
        else if (value > current->data) {
            current = current->right;
            
            // Jika sudah mencapai leaf node, tambahkan di sini
            if (current == NULL) {
                parent->right = newNode;
                return;
            }
        } 
        // Nilai sudah ada, tidak menambahkan duplikat
        else {
            free(newNode); // Hapus node yang tidak digunakan
            return;
        }
    }
}

// 5. Node Maksimum - Mencari node dengan nilai maksimum dalam binary tree
int findMaximum(BinaryTree* tree) {
    if (tree == NULL || tree->root == NULL) {
        printf("Tree kosong\n");
        return -1;
    }
    
    // Pada binary search tree, node paling kanan adalah maksimum
    Node* current = tree->root;
    
    while (current->right != NULL) {
        current = current->right;
    }
    
    return current->data;
}

// Fungsi untuk membersihkan memori node (helper function)
void freeNode(Node* node) {
    if (node != NULL) {
        freeNode(node->left);
        freeNode(node->right);
        free(node);
    }
}

// Fungsi untuk membersihkan memori tree
void freeTree(BinaryTree* tree) {
    if (tree != NULL) {
        freeNode(tree->root);
        free(tree);
    }
}