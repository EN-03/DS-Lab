#include <stdio.h>

#define MAX 100

typedef struct {
    int row;
    int col;
    int value;
} Term;

void fastTranspose(Term a[], Term b[]) {
    int rowTerms[MAX], startingPos[MAX];
    int i, j, numCols = a[0].col, numTerms = a[0].value;

    b[0].row = numCols;
    b[0].col = a[0].row;
    b[0].value = numTerms;

    if (numTerms > 0) {
        // Count the number of elements in each column
        for (i = 0; i < numCols; i++)
            rowTerms[i] = 0;

        for (i = 1; i <= numTerms; i++)
            rowTerms[a[i].col]++;

        // Find the starting position of each row in transpose
        startingPos[0] = 1;

        for (i = 1; i < numCols; i++)
            startingPos[i] = startingPos[i - 1] + rowTerms[i - 1];

        // Store the transposed elements
        for (i = 1; i <= numTerms; i++) {
            j = startingPos[a[i].col]++;

            b[j].row = a[i].col;
            b[j].col = a[i].row;
            b[j].value = a[i].value;
        }
    }
}

void display(Term a[]) {
    int i;

    printf("\nRow\tColumn\tValue\n");

    for (i = 0; i <= a[0].value; i++)
        printf("%d\t%d\t%d\n", a[i].row, a[i].col, a[i].value);
}

int main() {
    Term a[MAX], b[MAX];
    int rows, cols, i, j, k = 1;
    int value;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    a[0].row = rows;
    a[0].col = cols;
    a[0].value = 0;

    printf("Enter the matrix elements:\n");

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &value);

            if (value != 0) {
                a[k].row = i;
                a[k].col = j;
                a[k].value = value;
                k++;
            }
        }
    }

    a[0].value = k - 1;

    printf("\nOriginal Sparse Matrix (3-Tuple Form):");
    display(a);

    fastTranspose(a, b);

    printf("\nFast Transpose (3-Tuple Form):");
    display(b);

    return 0;
}