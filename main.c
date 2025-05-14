#include <stdio.h>
#include <stdlib.h>
#include "./include/fairuz.h"

int main()
{
    Node *root = NULL;
    int choice, value;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Masukan Node\n");
        printf("2. Hapus Node\n");
        printf("3. Tampilkan Tree\n");
        printf("4. Inorder Traversal\n");
        printf("5. Preorder Traversal\n");
        printf("6. Postorder Traversal\n");
        printf("7. Exit\n");
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
            root = deleteNode(root, value);
            break;
        case 3:
            printf("Tree saat ini:\n");
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
            printf("Exiting program.\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
