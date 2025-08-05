#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

// Check if queue is empty
int isEmpty() {
    return (front == -1 && rear == -1);
}

// Check if queue is full
int isFull() {
    return (rear == MAX - 1);
}

// Enqueue operation
void enqueue() {
    if (isFull()) {
        printf("Queue is full!\n");
        return;
    }

    int value;
    printf("Enter a value to enqueue: ");
    scanf("%d", &value);

    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear++;
    }

    queue[rear] = value;
    printf("Enqueued %d\n", value);
}

// Dequeue operation
int dequeue() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return -1;
    }

    int value = queue[front];
    if (front == rear) {
        front = rear = -1;  // Queue is now empty
    } else {
        front++;
    }

    return value;
}

// Display queue elements
void display() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice;

    do {
        printf("\n--- Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2: {
                int val = dequeue();
                if (val != -1)
                    printf("Dequeued: %d\n", val);
                break;
            }
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }

    } while (choice != 4);

    return 0;
}

