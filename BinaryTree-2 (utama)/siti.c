#include <stdio.h>
#include <stdlib.h>
#include "./include/siti.h"
#include "./include/fairuz.h"

// 1. Fungsi Delete Node (Non-Recursive)
Node* deleteNodeIterative(Node* root, int data) {
    Node* current = root;
    Node* parent = NULL;
    
    // Cari node yang akan dihapus dan parent-nya
    while (current != NULL && current->data != data) {
        parent = current;
        if (data < current->data)
            current = current->left;
        else
            current = current->right;
    }
    
    if (current == NULL) return root; // Node tidak ditemukan
    
    // Case 1: Node dengan 0 atau 1 anak
    if (current->left == NULL || current->right == NULL) {
        Node* newChild;
        
        if (current->left == NULL)
            newChild = current->right;
        else
            newChild = current->left;
        
        // Jika node yang dihapus adalah root
        if (parent == NULL) {
            free(current);
            return newChild;
        }
        
        if (parent->left == current)
            parent->left = newChild;
        else
            parent->right = newChild;
        
        free(current);
    }
    // Case 2: Node dengan 2 anak
    else {
        // Cari successor (nilai terkecil di subtree kanan)
        Node* successorParent = current;
        Node* successor = current->right;
        
        while (successor->left != NULL) {
            successorParent = successor;
            successor = successor->left;
        }
        
        // Ganti data node dengan successor
        current->data = successor->data;
        
        // Hapus successor
        if (successorParent->left == successor)
            successorParent->left = successor->right;
        else
            successorParent->right = successor->right;
        
        free(successor);
    }
    
    return root;
}

// 2. Level Order Traversal (BFS)
void levelOrderTraversal(Node* root) {
    if (root == NULL) return;
    
    Node* queue[100];
    int front = 0, rear = 0;
    
    queue[rear++] = root;
    
    while (front < rear) {
        Node* current = queue[front++];
        printf("%d ", current->data);
        
        if (current->left != NULL)
            queue[rear++] = current->left;
        
        if (current->right != NULL)
            queue[rear++] = current->right;
    }
}

// 3. Cari Predecessor (Non-Recursive)
Node* findPredecessor(Node* root, int data) {
    if (root == NULL) return NULL;
    
    Node* current = root;
    Node* ancestor = NULL;
    Node* lastRight = NULL;
    
    // Cari node target sambil menyimpan lastRight
    while (current != NULL && current->data != data) {
        if (data < current->data) {
            current = current->left;
        } else {
            lastRight = current;
            current = current->right;
        }
    }
    
    if (current == NULL) return NULL; // Node tidak ditemukan
    
    // Jika ada left subtree, predecessor adalah max di left subtree
    if (current->left != NULL) {
        current = current->left;
        while (current->right != NULL)
            current = current->right;
        return current;
    }
    // Jika tidak ada left subtree, predecessor adalah lastRight
    else {
        return lastRight;
    }
}

// 4. Cari Successor (Non-Recursive)
Node* findSuccessor(Node* root, int data) {
    if (root == NULL) return NULL;
    
    Node* current = root;
    Node* ancestor = NULL;
    Node* lastLeft = NULL;
    
    // Cari node target sambil menyimpan lastLeft
    while (current != NULL && current->data != data) {
        if (data < current->data) {
            lastLeft = current;
            current = current->left;
        } else {
            current = current->right;
        }
    }
    
    if (current == NULL) return NULL; // Node tidak ditemukan
    
    // Jika ada right subtree, successor adalah min di right subtree
    if (current->right != NULL) {
        current = current->right;
        while (current->left != NULL)
            current = current->left;
        return current;
    }
    // Jika tidak ada right subtree, successor adalah lastLeft
    else {
        return lastLeft;
    }
}

void printTree(struct Node *root, int space)
{
    if (root == NULL)
    {
        return;
    }

    // Tambahkan jarak antar level
    space += 5;

    // Pertama tampilkan anak kanan
    printTree(root->right, space);

    // Tampilkan data root setelah anak kanan
    printf("\n");
    for (int i = 5; i < space; i++)
    {
        printf(" ");
    }
    printf("%d\n", root->data);

    // Tampilkan anak kiri
    printTree(root->left, space);
}