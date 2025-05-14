#include <stdio.h>
#include <stdlib.h>
#include "./include/ibnu.h"
#include "./include/fairuz.h"

// 1. Cari Node - Mencari node dengan nilai tertentu dalam binary tree
int searchNode(Node* root, int value) {
    Node* current = root;

    while (current != NULL) {
        if (value == current->data) {
            return 1; // Ditemukan
        } else if (value < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    return 0; // Tidak ditemukan
}

// 2. Tinggi Tree - Menghitung tinggi binary tree (dengan BFS/iteratif)
int getHeight(Node* root) {
    if (root == NULL) {
        return -1;
    }

    Node* queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = root;
    int height = -1;

    while (front < rear) {
        int nodeCount = rear - front;
        height++;

        while (nodeCount > 0) {
            Node* current = queue[front++];

            if (current->left != NULL) queue[rear++] = current->left;
            if (current->right != NULL) queue[rear++] = current->right;

            nodeCount--;
        }
    }

    return height;
}

// 3. Jumlah Node - Menghitung jumlah node dalam binary tree
int countNodes(Node* root) {
    if (root == NULL) {
        return 0;
    }

    Node* queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = root;
    int count = 0;

    while (front < rear) {
        Node* current = queue[front++];
        count++;

        if (current->left != NULL) queue[rear++] = current->left;
        if (current->right != NULL) queue[rear++] = current->right;
    }

    return count;
}

// 4. Node Minimum - Mencari node dengan nilai minimum
Node* findMinimum(Node* root) {
    if (root == NULL) {
        return NULL;
    }

    Node* current = root;
    while (current->left != NULL) {
        current = current->left;
    }

    return current;
}


// 5. Node Maksimum - Mencari node dengan nilai maksimum
Node* findMaximum(Node* root) {
    if (root == NULL) {
        return NULL;
    }

    Node* current = root;
    while (current->right != NULL) {
        current = current->right;
    }

    return current;
}


// Fungsi bantu untuk membersihkan node
void freeNode(Node* node) {
    if (node != NULL) {
        freeNode(node->left);
        freeNode(node->right);
        free(node);
    }
}
