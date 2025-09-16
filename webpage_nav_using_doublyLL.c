#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100


struct Node {
    char url[MAX];
    struct Node* prev;
    struct Node* next;
};

struct Node* current = NULL;


struct Node* createNode(const char* url) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newnode->url, url);
    newnode->prev = NULL;
    newnode->next = NULL;
    return newnode;
}


void freeForwardHistory(struct Node* node) {
    while (node != NULL) {
        struct Node* temp = node;
        node = node->next;
        free(temp);
    }
}


void visitPage(const char* url) {
    // If there's forward history, free it
    if (current != NULL && current->next != NULL) {
        freeForwardHistory(current->next);
        current->next = NULL;
    }

    struct Node* newnode = createNode(url);

    if (current != NULL) {
        current->next = newnode;
        newnode->prev = current;
    }

    current = newnode;

    printf("Visited: %s\n", url);
}

void goBack() {
    if (current == NULL || current->prev == NULL) {
        printf("No previous page to go back to.\n");
        return;
    }
    current = current->prev;
    printf("Went back to: %s\n", current->url);
}


void goForward() {
    if (current == NULL || current->next == NULL) {
        printf("No forward page to go to.\n");
        return;
    }
    current = current->next;
    printf("Went forward to: %s\n", current->url);
}


void showCurrentPage() {
    if (current == NULL) {
        printf("No page currently open.\n");
    } else {
        printf("Current page: %s\n", current->url);
    }
}

// Free all nodes from the list (both directions)
void freeAll() {
   
    while (current != NULL && current->prev != NULL)
        current = current->prev;

    
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
}

// Main menu
int main() {
    int choice;
    char url[MAX];

    do {
        printf("\n--- Browser Navigation Menu ---\n");
        printf("1. Visit new page\n");
        printf("2. Go back\n");
        printf("3. Go forward\n");
        printf("4. Show current page\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1:
                printf("Enter URL: ");
                fgets(url, MAX, stdin);
                url[strcspn(url, "\n")] = 0; 
                visitPage(url);
                break;

            case 2:
                goBack();
                break;

            case 3:
                goForward();
                break;

            case 4:
                showCurrentPage();
                break;

            case 5:
                printf("Exiting browser...\n");
                freeAll(); 
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }

    } while (choice != 5);

    return 0;
}
