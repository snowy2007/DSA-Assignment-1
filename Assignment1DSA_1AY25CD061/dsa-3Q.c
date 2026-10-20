
#include <stdio.h>

typedef struct {
    int degree;
    float coef[101];
} polynomial;

polynomial add(polynomial a, polynomial b) {
    polynomial c;
    int i, j, k;

    c.degree = (a.degree > b.degree) ? a.degree : b.degree;

    for (i = 0; i <= c.degree; i++) {
        c.coef[i] = 0;

        k = c.degree - i;

        if (k <= a.degree) {
            j = a.degree - k;
            c.coef[i] += a.coef[j];
        }

        if (k <= b.degree) {
            j = b.degree - k;
            c.coef[i] += b.coef[j];
        }
    }

    return c;
}

void display(polynomial p) {
    int i, exponent, printed = 0;
    float c;

    for (i = 0; i <= p.degree; i++) {
        c = p.coef[i];
        exponent = p.degree - i;

        if (c == 0)
            continue;

        if (printed && c > 0)
            printf(" + ");
        else if (printed && c < 0)
            printf(" - ");
        else if (!printed && c < 0)
            printf("-");

        if (c < 0)
            c = -c;

        if (exponent == 0)
            printf("%.2g", c);
        else if (exponent == 1) {
            if (c == 1)
                printf("x");
            else
                printf("%.2gx", c);
        } else {
            if (c == 1)
                printf("x^%d", exponent);
            else
                printf("%.2gx^%d", c, exponent);
        }

        printed = 1;
    }

    if (!printed)
        printf("0");

    printf("\n");
}

int main() {
    polynomial a, b, c;
    int i;

    printf("Enter degree of first polynomial: ");
    scanf("%d", &a.degree);

    if (a.degree < 0 || a.degree > 100) {
        printf("Invalid degree.\n");
        return 1;
    }

    printf("Enter coefficients from highest power to constant:\n");
    for (i = 0; i <= a.degree; i++)
        scanf("%f", &a.coef[i]);

    printf("Enter degree of second polynomial: ");
    scanf("%d", &b.degree);

    if (b.degree < 0 || b.degree > 100) {
        printf("Invalid degree.\n");
        return 1;
    }

    printf("Enter coefficients from highest power to constant:\n");
    for (i = 0; i <= b.degree; i++)
        scanf("%f", &b.coef[i]);

    c = add(a, b);

    printf("First polynomial: ");
    display(a);

    printf("Second polynomial: ");
    display(b);

    printf("Sum: ");
    display(c);

    return 0;
}

