#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert a node in BST
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    // Ignore duplicates
    return root;
}

// Search for a value in BST
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;

    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

// Find the minimum node in BST
struct Node* findMin(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

// Delete a node from BST
struct Node* delete(struct Node* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = delete(root->left, key);
    else if (key > root->data)
        root->right = delete(root->right, key);
    else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: get inorder successor
        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = delete(root->right, temp->data);
    }
    return root;
}

// Main function with user input
int main() {
    struct Node* root = NULL;
    int choice, n, i, value;

    while (1) {
        printf("\nBinary Search Tree Operations:\n");
        printf("1. Insert multiple elements\n");
        printf("2. Delete multiple elements\n");
        printf("3. Search\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the number of elements to insert: ");
            scanf("%d", &n);
            for (i = 0; i < n; i++) {
                printf("Enter value %d to insert: ", i + 1);
                scanf("%d", &value);
                root = insert(root, value);
            }
            break;

        case 2:
            printf("Enter the number of elements to delete: ");
            scanf("%d", &n);
            for (i = 0; i < n; i++) {
                printf("Enter value %d to delete: ", i + 1);
                scanf("%d", &value);
                root = delete(root, value);
            }
            break;

        case 3:
            printf("Enter value to search: ");
            scanf("%d", &value);
            if (search(root, value))
                printf("%d found in the BST.\n", value);
            else
                printf("%d not found in the BST.\n", value);
            break;

        case 4:
            printf("Exiting...\n");
            exit(0);

        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}


