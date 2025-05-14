/**
 * main.c - Program utama untuk ADT Binary Tree
 * Implementasi menu interaktif untuk operasi Binary Tree
 */

#include <stdio.h>
#include <stdlib.h>
#include "ibnu.h"

int main() {
    BinaryTree* tree = createEmpty();
    int choice, value;
    
    do {
        // Menu
        printf("\n=== BINARY TREE ADT MENU ===\n");
        printf("1. Tambah Node (Insert Node)\n");
        printf("2. Cari Node (Search Node)\n");
        printf("3. Tinggi Tree (Tree Height)\n");
        printf("4. Jumlah Node (Node Count)\n");
        printf("5. Node Maksimum (Maximum Node)\n");
        printf("0. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Masukkan nilai untuk ditambahkan: ");
                scanf("%d", &value);
                insertNode(tree, value);
                printf("Node %d berhasil ditambahkan ke tree.\n", value);
                break;
                
            case 2:
                printf("Masukkan nilai yang dicari: ");
                scanf("%d", &value);
                if (searchNode(tree, value)) {
                    printf("Node %d ditemukan dalam tree.\n", value);
                } else {
                    printf("Node %d tidak ditemukan dalam tree.\n", value);
                }
                break;
                
            case 3:
                printf("Tinggi tree: %d\n", getHeight(tree));
                break;
                
            case 4:
                printf("Jumlah node dalam tree: %d\n", countNodes(tree));
                break;
                
            case 5:
                if (tree->root != NULL) {
                    printf("Nilai maksimum dalam tree: %d\n", findMaximum(tree));
                } else {
                    printf("Tree kosong, tidak ada nilai maksimum.\n");
                }
                break;
                
            case 0:
                printf("Terima kasih telah menggunakan program ini!\n");
                break;
                
            default:
                printf("Pilihan tidak valid, silakan coba lagi.\n");
        }
    } while (choice != 0);
    
    // Bersihkan memori sebelum keluar
    freeTree(tree);
    
    return 0;
}