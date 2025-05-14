#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

////

// Fungsi inisialisasi BST
void initialize_tree(BinarySearchTree* tree) {
    tree->root = NULL;
}

// Fungsi untuk membuat node baru
Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Kesalahan: Alokasi memori gagal!\n");
        exit(EXIT_FAILURE);
    }
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Fungsi rekursif untuk menambahkan node ke BST
Node* tambah_node_recursive(Node* node, int data) {
    // Jika node kosong, buat node baru
    if (node == NULL) {
        return create_node(data);
    }
    
    // Jika data lebih kecil, tambahkan ke sub-tree kiri
    if (data < node->data) {
        node->left = tambah_node_recursive(node->left, data);
    }
    // Jika data lebih besar, tambahkan ke sub-tree kanan
    else if (data > node->data) {
        node->right = tambah_node_recursive(node->right, data);
    }
    // Jika data sama, abaikan (tidak ada duplikat)
    
    return node;
}

// Fungsi untuk menambahkan node ke BST
void tambah_node(BinarySearchTree* tree, int data) {
    tree->root = tambah_node_recursive(tree->root, data);
}

// Fungsi untuk mencetak BST secara inorder (left, root, right)
void cetak_tree_inorder(Node* root) {
    if (root != NULL) {
        cetak_tree_inorder(root->left);
        printf("%d ", root->data);
        cetak_tree_inorder(root->right);
    }
}

// Fungsi untuk mencetak BST secara preorder (root, left, right)
void cetak_tree_preorder(Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        cetak_tree_preorder(root->left);
        cetak_tree_preorder(root->right);
    }
}

// Fungsi untuk mencetak BST secara postorder (left, right, root)
void cetak_tree_postorder(Node* root) {
    if (root != NULL) {
        cetak_tree_postorder(root->left);
        cetak_tree_postorder(root->right);
        printf("%d ", root->data);
    }
}

// Fungsi untuk mencetak BST dengan berbagai metode
void cetak_tree(BinarySearchTree* tree) {
    if (tree->root == NULL) {
        printf("Tree kosong!\n");
        return;
    }
    
    printf("Inorder traversal   : ");
    cetak_tree_inorder(tree->root);
    printf("\n");
    
    printf("Preorder traversal  : ");
    cetak_tree_preorder(tree->root);
    printf("\n");
    
    printf("Postorder traversal : ");
    cetak_tree_postorder(tree->root);
    printf("\n");
}

// Fungsi untuk mencetak BST secara visual dengan pendekatan rotasi 90 derajat
// Parameter space digunakan untuk indentasi
#define COUNT 10
void cetak_tree_visual(Node* root, int space) {
    // Basis: jika tree kosong
    if (root == NULL)
        return;
    
    // Tambahkan jarak antar level
    space += COUNT;
    
    // Proses subtree kanan terlebih dahulu (akan ditampilkan di bagian atas)
    cetak_tree_visual(root->right, space);
    
    // Cetak node saat ini setelah jarak yang sesuai
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);
    
    // Proses subtree kiri (akan ditampilkan di bagian bawah)
    cetak_tree_visual(root->left, space);
}

// Fungsi wrapper untuk mencetak BST secara visual
void tampilkan_tree_visual(BinarySearchTree* tree) {
    if (tree->root == NULL) {
        printf("Tree kosong!\n");
        return;
    }
    
    printf("\nStruktur Visual BST (diputar 90 derajat):\n");
    printf("(Kanan di atas, Kiri di bawah)\n");
    cetak_tree_visual(tree->root, 0);
    printf("\n");
}

// Fungsi untuk mencari nilai dalam BST
Node* cari_node(Node* root, int data) {
    // Basis: root NULL atau data ditemukan di root
    if (root == NULL || root->data == data) {
        return root;
    }
    
    // Jika data lebih kecil dari root, cari di subtree kiri
    if (data < root->data) {
        return cari_node(root->left, data);
    }
    
    // Jika data lebih besar dari root, cari di subtree kanan
    return cari_node(root->right, data);
}

// Fungsi untuk mendapatkan nilai minimum dalam BST
Node* find_min(Node* root) {
    if (root == NULL) {
        return NULL;
    }
    
    // Nilai minimum selalu berada di paling kiri
    Node* current = root;
    while (current->left != NULL) {
        current = current->left;
    }
    
    return current;
}

// Fungsi untuk mendapatkan nilai maksimum dalam BST
Node* find_max(Node* root) {
    if (root == NULL) {
        return NULL;
    }
    
    // Nilai maksimum selalu berada di paling kanan
    Node* current = root;
    while (current->right != NULL) {
        current = current->right;
    }
    
    return current;
}

// Fungsi untuk menghapus node dari BST
Node* hapus_node(Node* root, int data) {
    // Basis: Jika tree kosong
    if (root == NULL) {
        return root;
    }
    
    // Temukan node yang akan dihapus
    if (data < root->data) {
        // Nilai lebih kecil, cari di subtree kiri
        root->left = hapus_node(root->left, data);
    } else if (data > root->data) {
        // Nilai lebih besar, cari di subtree kanan
        root->right = hapus_node(root->right, data);
    } else {
        // Node dengan nilai yang sesuai ditemukan
        
        // Kasus 1: Node tidak memiliki anak atau memiliki satu anak
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        
        // Kasus 2: Node memiliki dua anak
        // Temukan penerus inorder (nilai terkecil di subtree kanan)
        Node* temp = find_min(root->right);
        
        // Salin data penerus ke node ini
        root->data = temp->data;
        
        // Hapus penerus inorder
        root->right = hapus_node(root->right, temp->data);
    }
    return root;
}

// Fungsi untuk menghitung tinggi BST
int hitung_tinggi(Node* root) {
    if (root == NULL) {
        return -1; // Tinggi tree kosong adalah -1
    }
    
    int left_height = hitung_tinggi(root->left);
    int right_height = hitung_tinggi(root->right);
    
    // Tinggi adalah maksimum dari tinggi subtree kiri dan kanan, ditambah 1
    return (left_height > right_height ? left_height : right_height) + 1;
}

// Fungsi untuk menghitung jumlah node dalam BST
int hitung_jumlah_node(Node* root) {
    if (root == NULL) {
        return 0;
    }
    
    return 1 + hitung_jumlah_node(root->left) + hitung_jumlah_node(root->right);
}

// Fungsi untuk membersihkan BST secara rekursif
void bersihkan_tree(Node* root) {
    if (root != NULL) {
        bersihkan_tree(root->left);
        bersihkan_tree(root->right);
        free(root);
    }
}

// Fungsi untuk menghancurkan BST dan membebaskan memori
void destroy_tree(BinarySearchTree* tree) {
    bersihkan_tree(tree->root);
    tree->root = NULL;
}