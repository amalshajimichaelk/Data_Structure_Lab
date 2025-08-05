#include <stdio.h>
#define MAX 5

int deque[MAX];
int front = -1;
int rear = -1;

// Check if deque is empty
int isEmpty() {
    return (front == -1 && rear == -1);
}

// Check if deque is full
int isFull() {
    return (front == 0 && rear == MAX - 1);
}

// Insert at front
void insert_front() {
     if (front == 0) {
        deque[front+1]=deque[front];
    }
    if (isFull()) {
        printf("Cannot insert at front. Deque full!\n");
        return;
    }
    
    int value;
    printf("Enter a value to insert at front: ");
    scanf("%d", &value);

    if (isEmpty()) {
        front = rear = 0;
    } else {
        front--;
    }

    deque[front] = value;
    printf("Inserted %d at front\n", value);
}

// Insert at back
void insert_back() {
    if (isFull()) {
        printf("Deque is full!\n");
        return;
    }

    int value;
    printf("Enter a value to insert at back: ");
    scanf("%d", &value);

    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear++;
    }

    deque[rear] = value;
    printf("Inserted %d at back\n", value);
}

// Delete from front
void delete_front() {
    if (isEmpty()) {
        printf("Deque is empty!\n");
        return;
    }

    int value = deque[front];
    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }

    printf("Deleted from front: %d\n", value);
}

// Delete from back
void delete_back() {
    if (isEmpty()) {
        printf("Deque is empty!\n");
        return;
    }

    int value = deque[rear];
    if (front == rear) {
        front = rear = -1;
    } else {
        rear--;
    }

    printf("Deleted from back: %d\n", value);
}

// Display deque elements
void display() {
    if (isEmpty()) {
        printf("Deque is empty!\n");
        return;
    }

    printf("Deque elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", deque[i]);
    }
    printf("\n");
}

int main() {
    int choice;

    do {
        printf("\n--- Deque Menu ---\n");
        printf("1. Insert Front\n");
        printf("2. Insert Back\n");
        printf("3. Delete Front\n");
        printf("4. Delete Back\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert_front();
                break;
            case 2:
                insert_back();
                break;
            case 3:
                delete_front();
                break;
            case 4:
                delete_back();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }

    } while (choice != 6);

    return 0;
}

