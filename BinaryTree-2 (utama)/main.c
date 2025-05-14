#include <stdio.h>
#include <stdlib.h>
#include "./include/fairuz.h"
#include "./include/siti.h"

int main()
{
    Node *root = NULL;
    int choice, value;
    Node *temp;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Masukan Node\n");
        printf("2. Hapus Node (Non-Recursive)\n");
        printf("3. Tampilkan Struktur Tree\n");
        printf("4. Inorder Traversal\n");
        printf("5. Preorder Traversal\n");
        printf("6. Postorder Traversal\n");
        printf("7. Level Order Traversal (BFS)\n");
        printf("8. Cari Predecessor\n");
        printf("9. Cari Successor\n");
        printf("10. Exit\n");
        printf("Masukan Pilihan: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Masukan Nilai yang akan ditambahkan: ");
            scanf("%d", &value);
            root = insertNode(root, value);
            break;
        case 2:
            printf("Masukan Nilai yang akan dihapus: ");
            scanf("%d", &value);
            root = deleteNodeIterative(root, value); // Menggunakan versi non-rekursif
            break;
        case 3:
            printf("Struktur Tree:\n");
            printTree(root, 0); // Visualisasi tree
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
            printf("Keluar dari program.\n");
            exit(0);
        default:
            printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }
    }

    return 0;
}
