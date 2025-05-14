/**
 * BinaryTree.c - Implementasi ADT Binary Tree
 * Implementasi dari fungsi-fungsi yang dideklarasikan di BinaryTree.h
 */

#include <stdio.h>
#include <stdlib.h>
#include "include/siti.h"

// 6. Delete Node - Menghapus node dengan nilai tertentu dari binary tree.
void deleteNode(BinaryTree* tree, int value) {
    if (tree == NULL || tree->root == NULL) return;

    Node* parent = NULL;
    Node* current = tree->root;

    // Cari node yang akan dihapus dan simpan parent-nya
    while (current != NULL && current->data != value) {
        parent = current;
        if (value < current->data)
            current = current->left;
        else
            current = current->right;
    }

    if (current == NULL) return; // Tidak ditemukan

    // Case 1: Node tidak punya anak
    if (current->left == NULL && current->right == NULL) {
        if (parent == NULL) tree->root = NULL;
        else if (parent->left == current) parent->left = NULL;
        else parent->right = NULL;
        free(current);
    }

    // Case 2: Satu anak
    else if (current->left == NULL || current->right == NULL) {
        Node* child = (current->left != NULL) ? current->left : current->right;
        if (parent == NULL) tree->root = child;
        else if (parent->left == current) parent->left = child;
        else parent->right = child;
        free(current);
    }

    // Case 3: Dua anak
    else {
        // Cari successor (anak paling kiri dari right subtree)
        Node* succParent = current;
        Node* succ = current->right;
        while (succ->left != NULL) {
            succParent = succ;
            succ = succ->left;
        }

        // Salin data successor ke current
        current->data = succ->data;

        // Hapus successor
        if (succParent->left == succ)
            succParent->left = succ->right;
        else
            succParent->right = succ->right;
        free(succ);
    }
}

// 7. Level order traversal - Melakukan traversal level order pada binary tree.
void levelOrderTraversal(BinaryTree* tree) {
    if (tree == NULL || tree->root == NULL) return;

    Node* queue[1000];
    int front = 0, rear = 0;

    queue[rear++] = tree->root;

    while (front < rear) {
        Node* current = queue[front++];
        printf("%d ", current->data);

        if (current->left != NULL)
            queue[rear++] = current->left;
        if (current->right != NULL)
            queue[rear++] = current->right;
    }

    printf("\n");
}

// 8. Cari predecessor - Mencari predecessor node dengan nilai tertentu dalam binary tree.
int findPredecessor(BinaryTree* tree, int value) {
    if (tree == NULL || tree->root == NULL) return -1;

    Node* current = tree->root;
    Node* predecessor = NULL;

    while (current != NULL) {
        if (value > current->data) {
            predecessor = current;
            current = current->right;
        } else {
            current = current->left;
        }
    }

    return (predecessor != NULL) ? predecessor->data : -1;
}

// 9. Cari successor - Mencari successor node dengan nilai tertentu dalam binary tree.
int findSuccessor(BinaryTree* tree, int value) {
    if (tree == NULL || tree->root == NULL) return -1;

    Node* current = tree->root;
    Node* successor = NULL;

    while (current != NULL) {
        if (value < current->data) {
            successor = current;
            current = current->left;
        } else {
            current = current->right;
        }
    }

    return (successor != NULL) ? successor->data : -1;
}

// 10. Cetak tree - Mencetak struktur binary tree.
void printTree(BinaryTree* tree) {
    if (tree == NULL || tree->root == NULL) return;

    typedef struct {
        Node* node;
        int level;
    } QueueItem;

    QueueItem queue[1000];
    int front = 0, rear = 0;

    queue[rear++] = (QueueItem){tree->root, 0};
    int currentLevel = 0;

    while (front < rear) {
        QueueItem current = queue[front++];

        if (current.level != currentLevel) {
            printf("\n");
            currentLevel = current.level;
        }

        for (int i = 0; i < current.level; i++) printf("  ");
        printf("%d\n", current.node->data);

        if (current.node->left)
            queue[rear++] = (QueueItem){current.node->left, current.level + 1};
        if (current.node->right)
            queue[rear++] = (QueueItem){current.node->right, current.level + 1};
    }
}