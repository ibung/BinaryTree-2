#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main() {
    Tree t;
    init_tree(&t);

    int pilihan, data;

    do {
        printf("\n=== Menu BST Non-Recursive ===\n");
        printf("1. Tambah node\n");
        printf("2. Cetak in-order traversal\n");
        printf("3. Cetak visualisasi tree\n");
        printf("0. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                printf("Masukkan nilai node: ");
                scanf("%d", &data);
                tambah_node(&t, data);
                break;
            case 2:
                printf("In-order traversal:\n");
                cetak_tree_traversal(&t);
                printf("\n");
                break;
            case 3:
                printf("Visualisasi tree:\n");
                cetak_tree_visual(t.root, 0);
                break;
            case 0:
                printf("Terima kasih!\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }

    } while (pilihan != 0);

    return 0;
}
