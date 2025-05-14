#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

void init_tree(Tree *t) {
    t->root = NULL;
}

Node* buat_node(int data) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

void tambah_node(Tree *t, int data) {
    Node *new_node = buat_node(data);

    if (t->root == NULL) {
        t->root = new_node;
        return;
    }

    Node *curr = t->root;
    Node *parent = NULL;

    while (curr != NULL) {
        parent = curr;
        if (data < curr->data)
            curr = curr->left;
        else
            curr = curr->right;
    }

    if (data < parent->data)
        parent->left = new_node;
    else
        parent->right = new_node;
}

void cetak_tree_traversal(Tree *t) {
    Node *stack[100];
    int top = -1;
    Node *curr = t->root;

    while (curr != NULL || top != -1) {
        while (curr != NULL) {
            stack[++top] = curr;
            curr = curr->left;
        }

        curr = stack[top--];
        printf("%d ", curr->data);
        curr = curr->right;
    }
    printf("\n");
}

void cetak_tree_visual(Node *root, int depth) {
    if (root == NULL) return;

    cetak_tree_visual(root->right, depth + 1);

    for (int i = 0; i < depth; i++)
        printf("    ");
    printf("%d\n", root->data);

    cetak_tree_visual(root->left, depth + 1);
}
