#include <stdio.h>
#include "include/fairuz.h"

// Traversal inorder
void inorderTraversal(Node *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Traversal preorder
void preorderTraversal(Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Traversal postorder
void postorderTraversal(Node *root)
{
    if (root != NULL)
    {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

int isEmpty(BinaryTree *tree)
{
    return tree == NULL || tree->root == NULL;
}

// Cari nilai minimum dalam binary tree
int findMinimum(BinaryTree *tree)
{
    if (tree == NULL || tree->root == NULL)
    {
        printf("Tree kosong\n");
        return -1; // Tidak ada nilai minimum
    }

    Node *current = tree->root;
    while (current->left != NULL)
    {
        current = current->left;
    }

    return current->data;
}