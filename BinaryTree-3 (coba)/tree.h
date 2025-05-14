#ifndef TREE_H
#define TREE_H

//cek//

// Struktur data untuk node dalam BST
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Struktur data untuk BST
typedef struct {
    Node* root;
} BinarySearchTree;

// Fungsi inisialisasi BST
void initialize_tree(BinarySearchTree* tree);

// Fungsi untuk membuat node baru
Node* create_node(int data);

// Fungsi untuk menambahkan node ke BST
void tambah_node(BinarySearchTree* tree, int data);

// Fungsi untuk mencetak BST secara inorder
void cetak_tree_inorder(Node* root);

// Fungsi untuk mencetak BST secara preorder
void cetak_tree_preorder(Node* root);

// Fungsi untuk mencetak BST secara postorder
void cetak_tree_postorder(Node* root);

// Fungsi untuk mencetak BST dengan berbagai metode
void cetak_tree(BinarySearchTree* tree);

// Fungsi untuk mencetak BST secara visual
void cetak_tree_visual(Node* root, int space);

// Fungsi wrapper untuk mencetak BST secara visual
void tampilkan_tree_visual(BinarySearchTree* tree);

// Fungsi untuk mencari nilai dalam BST
Node* cari_node(Node* root, int data);

// Fungsi untuk mendapatkan nilai minimum dalam BST
Node* find_min(Node* root);

// Fungsi untuk mendapatkan nilai maksimum dalam BST
Node* find_max(Node* root);

// Fungsi untuk menghapus node dari BST
Node* hapus_node(Node* root, int data);

// Fungsi untuk menghitung tinggi BST
int hitung_tinggi(Node* root);

// Fungsi untuk menghitung jumlah node dalam BST
int hitung_jumlah_node(Node* root);

// Fungsi untuk membersihkan BST
void bersihkan_tree(Node* root);

// Fungsi untuk menghancurkan BST dan membebaskan memori
void destroy_tree(BinarySearchTree* tree);

#endif /* TREE_H */