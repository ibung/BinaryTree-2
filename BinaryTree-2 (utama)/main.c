/*

Gambar di atas merepresentasikan struktur pohon biner dalam tampilan horizontal (menyamping), di mana:
- Akar (root) pohon terletak paling kiri dalam tampilan tersebut.
- Setiap node dalam pohon bercabang ke arah kanan, sehingga semakin ke kanan menunjukkan tingkat kedalaman (depth) dari pohon.
- Simpul-simpul (node) di bagian paling kanan yang tidak memiliki anak disebut sebagai leaf nodes atau simpul daun.

Pola visual ini mempermudah pembacaan pohon dari kiri ke kanan, dengan alur:
Root → Anak kiri → Anak kanan → ... → Leaf

*/

#include <stdio.h>
#include <stdlib.h>
#include "./include/fairuz.h"
#include "./include/siti.h"
#include "./include/ibnu.h"

int main() {
    Node *root = NULL;
    int choice, value;
    Node *temp;

    while (1) {
        printf("\nMenu:\n");
        printf(" 1.  Masukan Node\n");
        printf(" 2.  Hapus Node (Non-Recursive)\n");
        printf(" 3.  Tampilkan Struktur Tree\n");
        printf(" 4.  Inorder Traversal\n");
        printf(" 5.  Preorder Traversal\n");
        printf(" 6.  Postorder Traversal\n");
        printf(" 7.  Level Order Traversal (BFS)\n");
        printf(" 8.  Cari Predecessor\n");
        printf(" 9.  Cari Successor\n");
        printf("10.  Nilai Maksimum\n");
        printf("11.  Nilai Minimum\n");
        printf("12.  Tinggi Tree\n");
        printf("13.  Jumlah Node\n");
        printf("14.  Cari Node\n");
        printf("15.  Exit\n");
        printf("Masukan Pilihan: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Masukan Nilai yang akan ditambahkan: ");
            scanf("%d", &value);
            root = insertNode(root, value);
            break;

        case 2:
            printf("Masukan Nilai yang akan dihapus: ");
            scanf("%d", &value);
            root = deleteNodeIterative(root, value);
            break;

        case 3:
            printf("Struktur Tree:\n");
            printTree(root, 0);
            break;

        case 4:
            printf("Inorder Traversal: ");
            inorderTraversal(root);
            printf("\n");
            break;

        case 5:
            printf("Preorder Traversal: ");
            preorderTraversal(root);
            printf("\n");
            break;

        case 6:
            printf("Postorder Traversal: ");
            postorderTraversal(root);
            printf("\n");
            break;

        case 7:
            printf("Level Order Traversal (BFS): ");
            levelOrderTraversal(root);
            printf("\n");
            break;

        case 8:
            printf("Masukan Nilai untuk mencari Predecessor: ");
            scanf("%d", &value);
            temp = findPredecessor(root, value);
            if (temp != NULL)
                printf("Predecessor dari %d adalah %d\n", value, temp->data);
            else
                printf("Predecessor tidak ditemukan.\n");
            break;

        case 9:
            printf("Masukan Nilai untuk mencari Successor: ");
            scanf("%d", &value);
            temp = findSuccessor(root, value);
            if (temp != NULL)
                printf("Successor dari %d adalah %d\n", value, temp->data);
            else
                printf("Successor tidak ditemukan.\n");
            break;

        case 10:
            temp = findMaximum(root);
            if (temp != NULL)
                printf("Nilai maksimum dalam tree adalah %d\n", temp->data);
            else
                printf("Tree kosong.\n");
            break;

        case 11:
            temp = findMinimum(root);
            if (temp != NULL)
                printf("Nilai minimum dalam tree adalah %d\n", temp->data);
            else
                printf("Tree kosong.\n");
            break;

        case 12:
            printf("Tinggi tree adalah %d\n", getHeight(root));
            break;

        case 13:
            printf("Jumlah node dalam tree adalah %d\n", countNodes(root));
            break;

        case 14:
            printf("Masukan Nilai yang akan dicari: ");
            scanf("%d", &value);
            if (searchNode(root, value))
                printf("Node %d ditemukan dalam tree.\n", value);
            else
                printf("Node %d tidak ditemukan dalam tree.\n", value);
            break;

        case 15:
            printf("Keluar dari program.\n");
            exit(0);

        default:
            printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }
    }

    return 0;
}
