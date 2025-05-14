#include <stdio.h>
#include <stdlib.h>
#include "./include/fairuz.h"

Node *newNode(int data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

Node *insertNode(Node *root, int data) {
    if (root == NULL) {
        return newNode(data);
    }

    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

Node *minNode(Node *root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

Node *deleteNode(Node *root, int data) {
    if (root == NULL) {
        return root;
    }

    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        if (root->left == NULL) {
            Node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node *temp = root->left;
            free(root);
            return temp;
        }

        Node *temp = minNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void printTree(Node *root, int space) {
    if (root == NULL) {
        return;
    }

    space += 5;

    printTree(root->right, space);

    printf("\n");
    for (int i = 5; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", root->data);

    printTree(root->left, space);
}

void inorderTraversal(Node *root) {
    Node *stack[100];
    int top = -1;
    Node *current = root;

    while (current != NULL || top != -1) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }

        current = stack[top--];
        printf("%d ", current->data);
        current = current->right;
    }
}

void preorderTraversal(Node *root) {
    if (root == NULL) return;

    Node *stack[100];
    int top = -1;
    stack[++top] = root;

    while (top != -1) {
        Node *current = stack[top--];
        printf("%d ", current->data);

        if (current->right) stack[++top] = current->right;
        if (current->left) stack[++top] = current->left;
    }
}

void postorderTraversal(Node *root) {
    if (root == NULL) return;

    Node *stack1[100], *stack2[100];
    int top1 = -1, top2 = -1;

    stack1[++top1] = root;

    while (top1 != -1) {
        Node *current = stack1[top1--];
        stack2[++top2] = current;

        if (current->left) stack1[++top1] = current->left;
        if (current->right) stack1[++top1] = current->right;
    }

    while (top2 != -1) {
        printf("%d ", stack2[top2--]->data);
    }
}


