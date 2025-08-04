#include <stdio.h>

struct poly {
    int coeff;
    int exp;
};

void sort(struct poly p[], int n) {
    // Sort the polynomial in descending order of exponents
    int i, j;
    struct poly temp;
    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(p[i].exp < p[j].exp) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

int main() {
    int i, j, n, m, k = 0;
    struct poly p1[10], p2[10], p3[20];

    // Input for 1st polynomial
    printf("Enter the no. of terms of 1st polynomial: ");
    scanf("%d", &n);
    printf("Enter the terms of 1st polynomial:\n");
    for(i = 0; i < n; i++) {
        printf("Term %d (coeff exp): ", i + 1);
        scanf("%d%d", &p1[i].coeff, &p1[i].exp);
    }

    // Input for 2nd polynomial
    printf("Enter the no. of terms of 2nd polynomial: ");
    scanf("%d", &m);
    printf("Enter the terms of 2nd polynomial:\n");
    for(j = 0; j < m; j++) {
        printf("Term %d (coeff exp): ", j + 1);
        scanf("%d%d", &p2[j].coeff, &p2[j].exp);
    }

    // Sort both polynomials
    sort(p1, n);
    sort(p2, m);

    // Add polynomials
    i = 0; j = 0;
    while(i < n && j < m) {
        if(p1[i].exp == p2[j].exp) {
            p3[k].coeff = p1[i].coeff + p2[j].coeff;
            p3[k].exp = p1[i].exp;
            i++; j++; k++;
        } else if(p1[i].exp > p2[j].exp) {
            p3[k++] = p1[i++];
        } else {
            p3[k++] = p2[j++];
        }
    }

    // Copy remaining terms
    while(i < n) p3[k++] = p1[i++];
    while(j < m) p3[k++] = p2[j++];

    // Print the result
    printf("The Resultant Polynomial:\n");
    for(i = 0; i < k; i++) {
        printf("%d(x^%d)", p3[i].coeff, p3[i].exp);
        if(i != k - 1) printf(" + ");
    }
    printf("\n");

    return 0;
}