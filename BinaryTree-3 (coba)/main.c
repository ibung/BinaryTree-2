#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

// Fungsi untuk menampilkan menu
void tampilkan_menu() {
    printf("\n==== PROGRAM BINARY SEARCH TREE ====\n");
    printf("1. Tambah Node\n");
    printf("2. Cetak Tree (Traversal)\n");
    printf("3. Cetak Tree (Visual)\n");
    printf("4. Cari Node\n");
    printf("5. Hapus Node\n");
    printf("6. Tampilkan Nilai Minimum\n");
    printf("7. Tampilkan Nilai Maksimum\n");
    printf("8. Hitung Tinggi Tree\n");
    printf("9. Hitung Jumlah Node\n");
    printf("0. Keluar\n");
    printf("Pilihan Anda: ");
}

int main() {
    BinarySearchTree tree;
    initialize_tree(&tree);
    
    int pilihan, nilai;
    Node* hasil;
    
    do {
        tampilkan_menu();
        scanf("%d", &pilihan);
        
        switch (pilihan) {
            case 1:
                printf("Masukkan nilai yang akan ditambahkan: ");
                scanf("%d", &nilai);
                tambah_node(&tree, nilai);
                printf("Node dengan nilai %d berhasil ditambahkan.\n", nilai);
                break;
                
            case 2:
                cetak_tree(&tree);
                break;
                
            case 3:
                tampilkan_tree_visual(&tree);
                break;
                
            case 4:
                printf("Masukkan nilai yang akan dicari: ");
                scanf("%d", &nilai);
                hasil = cari_node(tree.root, nilai);
                if (hasil != NULL) {
                    printf("Node dengan nilai %d ditemukan dalam tree.\n", nilai);
                } else {
                    printf("Node dengan nilai %d tidak ditemukan dalam tree.\n", nilai);
                }
                break;
                
            case 5:
                printf("Masukkan nilai yang akan dihapus: ");
                scanf("%d", &nilai);
                hasil = cari_node(tree.root, nilai);
                if (hasil != NULL) {
                    tree.root = hapus_node(tree.root, nilai);
                    printf("Node dengan nilai %d berhasil dihapus.\n", nilai);
                } else {
                    printf("Node dengan nilai %d tidak ditemukan dalam tree.\n", nilai);
                }
                break;
                
            case 6:
                hasil = find_min(tree.root);
                if (hasil != NULL) {
                    printf("Nilai minimum dalam tree: %d\n", hasil->data);
                } else {
                    printf("Tree kosong!\n");
                }
                break;
                
            case 7:
                hasil = find_max(tree.root);
                if (hasil != NULL) {
                    printf("Nilai maksimum dalam tree: %d\n", hasil->data);
                } else {
                    printf("Tree kosong!\n");
                }
                break;
                
            case 8:
                printf("Tinggi tree: %d\n", hitung_tinggi(tree.root));
                break;
                
            case 9:
                printf("Jumlah node dalam tree: %d\n", hitung_jumlah_node(tree.root));
                break;
                
            case 0:
                printf("Terima kasih telah menggunakan program ini!\n");
                break;
                
            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }
    } while (pilihan != 0);
    
    // Membersihkan memori sebelum keluar
    destroy_tree(&tree);
    
    return 0;
}