#ifndef TREE_H
#define TREE_H

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct {
    Node *root;
} Tree;

void init_tree(Tree *t);
Node* buat_node(int data);
void tambah_node(Tree *t, int data);
void cetak_tree_traversal(Tree *t);
void cetak_tree_visual(Node *root, int depth);

#endif
