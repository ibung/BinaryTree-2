/**
 * main.c - Program utama untuk ADT Binary Tree
 * Implementasi menu interaktif untuk operasi Binary Tree
 */

#include <stdio.h>
#include <stdlib.h>
#include "include/ibnu.h"
#include "include/fairuz.h"
#include "include/siti.h"

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
        printf("6. Node Minimum (Minimum Node)\n");
        printf("7. Traversal Inorder\n");
        printf("8. Traversal Preorder\n");
        printf("9. Traversal Postorder\n");
        printf("10. Cek Apakah Tree Kosong\n");
        printf("11. Hapus Node (Delete Node)\n");
        printf("12. Level Order Traversal\n");
        printf("13. Cari Predecessor\n");
        printf("14. Cari Successor\n");
        printf("15. Cetak Tree\n");
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

            case 6:
                if (tree->root != NULL) {
                    printf("Nilai minimum dalam tree: %d\n", findMinimum(tree));
                } else {
                    printf("Tree kosong, tidak ada nilai minimum.\n");
                }
                break;

            case 7:
                printf("Traversal Inorder: ");
                inorderTraversal(tree->root);
                printf("\n");
                break;

            case 8:
                printf("Traversal Preorder: ");
                preorderTraversal(tree->root);
                printf("\n");
                break;

            case 9:
                printf("Traversal Postorder: ");
                postorderTraversal(tree->root);
                printf("\n");
                break;

            case 10:
                if (isEmpty(tree)) {
                    printf("Tree kosong.\n");
                } else {
                    printf("Tree tidak kosong.\n");
                }
                break;
                
            case 11:
                printf("Masukkan nilai yang ingin dihapus: ");
                scanf("%d", &value);
                deleteNode(tree, value);
                printf("Node %d berhasil dihapus dari tree.\n", value);
                break;

            case 12:
                printf("Level Order Traversal: ");
                levelOrderTraversal(tree);
                printf("\n");
                break;

            case 13:
                printf("Masukkan nilai untuk mencari predecessor: ");
                scanf("%d", &value);
                int predecessor = findPredecessor(tree, value);
                if (predecessor != -1) {
                    printf("Predecessor dari %d adalah %d\n", value, predecessor);
                } else {
                    printf("Tidak ada predecessor untuk %d\n", value);
                }
                break;

            case 14:
                printf("Masukkan nilai untuk mencari successor: ");
                scanf("%d", &value);
                int successor = findSuccessor(tree, value);
                if (successor != -1) {
                    printf("Successor dari %d adalah %d\n", value, successor);
                } else {
                    printf("Tidak ada successor untuk %d\n", value);
                }
                break;

            case 15:
                printf("Cetak Tree:\n");
                printTree(tree);
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