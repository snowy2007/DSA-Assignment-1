#include <stdio.h>
#include <stdlib.h>

struct Student {
    int roll_no;
    char name[20];
    float marks;
};

int main() {
    int n, i;
    char choice;
    float sum = 0;
    struct Student *ptr, *temp, *topper;

    printf("Enter number of students: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid number of students.\n");
        return 1;
    }

    ptr = (struct Student *)malloc(n * sizeof(struct Student));

    if (ptr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("Enter roll, name, marks: ");
        scanf("%d %19s %f",
              &(ptr + i)->roll_no,
              (ptr + i)->name,
              &(ptr + i)->marks);
    }

    topper = ptr;

    for (i = 0; i < n; i++) {
        sum += (ptr + i)->marks;

        if ((ptr + i)->marks > topper->marks)
            topper = ptr + i;
    }

    printf("Average marks: %.2f\n", sum / n);
    printf("Topper: %s (Roll %d, Marks %.2f)\n",
           topper->name, topper->roll_no, topper->marks);

    printf("Add 2 more students? (y/n): ");
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y') {
        temp = (struct Student *)realloc(
            ptr, (n + 2) * sizeof(struct Student));

        if (temp == NULL) {
            printf("Memory reallocation failed.\n");
            free(ptr);
            return 1;
        }

        ptr = temp;

        for (i = n; i < n + 2; i++) {
            printf("Enter roll, name, marks: ");
            scanf("%d %19s %f",
                  &(ptr + i)->roll_no,
                  (ptr + i)->name,
                  &(ptr + i)->marks);
        }

        n += 2;
        sum = 0;

        for (i = 0; i < n; i++)
            sum += (ptr + i)->marks;

        printf("Updated average marks: %.2f\n", sum / n);
    }

    free(ptr);
    return 0;
}

