#include <stdio.h>
#include <stdlib.h>

// Node structure for polynomial term
struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int coeff, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

// Function to append node at the end of the list
void appendNode(struct Node** head, int coeff, int exp) {
    struct Node* newNode = createNode(coeff, exp);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

// Function to print the polynomial
void printPolynomial(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%dx^%d", temp->coeff, temp->exp);
        if (temp->next != NULL)
            printf(" + ");
        temp = temp->next;
    }
    printf("\n");
}

// Function to add two polynomials and return the head of the result list
struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;
    struct Node* ptr1 = poly1;
    struct Node* ptr2 = poly2;

    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1->exp > ptr2->exp) {
            appendNode(&result, ptr1->coeff, ptr1->exp);
            ptr1 = ptr1->next;
        } else if (ptr1->exp < ptr2->exp) {
            appendNode(&result, ptr2->coeff, ptr2->exp);
            ptr2 = ptr2->next;
        } else {
            int sumCoeff = ptr1->coeff + ptr2->coeff;
            if (sumCoeff != 0) {
                appendNode(&result, sumCoeff, ptr1->exp);
            }
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
    }

    while (ptr1 != NULL) {
        appendNode(&result, ptr1->coeff, ptr1->exp);
        ptr1 = ptr1->next;
    }

    while (ptr2 != NULL) {
        appendNode(&result, ptr2->coeff, ptr2->exp);
        ptr2 = ptr2->next;
    }

    return result;
}

int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;
    struct Node* sum = NULL;

    int n1, n2;
    int coeff, exp;

    // Input for first polynomial
    printf("Enter number of terms for polynomial 1: ");
    scanf("%d", &n1);

    printf("Enter terms for polynomial 1 in descending order of exponents (coeff and exponent):\n");
    for (int i = 0; i < n1; i++) {
        printf("Term %d: ", i + 1);
        scanf("%d %d", &coeff, &exp);
        appendNode(&poly1, coeff, exp);
    }

    // Input for second polynomial
    printf("Enter number of terms for polynomial 2: ");
    scanf("%d", &n2);

    printf("Enter terms for polynomial 2 in descending order of exponents (coeff and exponent):\n");
    for (int i = 0; i < n2; i++) {
        printf("Term %d: ", i + 1);
        scanf("%d %d", &coeff, &exp);
        appendNode(&poly2, coeff, exp);
    }

    printf("\nPolynomial 1: ");
    printPolynomial(poly1);

    printf("Polynomial 2: ");
    printPolynomial(poly2);

    sum = addPolynomials(poly1, poly2);

    printf("Sum: ");
    printPolynomial(sum);

    // Free allocated memory (optional, but recommended)
    // You can add functions to free the lists here if you want.

    return 0;
}

