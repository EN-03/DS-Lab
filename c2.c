#include <stdio.h>

#define MAX 100

int main() {
    int matrix[MAX][MAX];
    int compact[MAX * MAX + 1][3];
    int transpose[MAX * MAX + 1][3];

    int rows, cols;
    int i, j, k = 1;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter the matrix elements:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Create compact (triplet) representation
    compact[0][0] = rows;
    compact[0][1] = cols;
    compact[0][2] = 0;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                compact[k][0] = i;
                compact[k][1] = j;
                compact[k][2] = matrix[i][j];
                k++;
            }
        }
    }

    compact[0][2] = k - 1;

    // Display compact matrix
    printf("\nCompact Matrix (Triplet Form):\n");
    printf("Row\tCol\tValue\n");

    for (i = 0; i < k; i++) {
        printf("%d\t%d\t%d\n",
               compact[i][0],
               compact[i][1],
               compact[i][2]);
    }

    // Simple transpose
    transpose[0][0] = compact[0][1];
    transpose[0][1] = compact[0][0];
    transpose[0][2] = compact[0][2];

    int t = 1;

    for (i = 0; i < cols; i++) {
        for (j = 1; j < k; j++) {
            if (compact[j][1] == i) {
                transpose[t][0] = compact[j][1];
                transpose[t][1] = compact[j][0];
                transpose[t][2] = compact[j][2];
                t++;
            }
        }
    }

    // Display transpose
    printf("\nSimple Transpose of Compact Matrix:\n");
    printf("Row\tCol\tValue\n");

    for (i = 0; i < t; i++) {
        printf("%d\t%d\t%d\n",
               transpose[i][0],
               transpose[i][1],
               transpose[i][2]);
    }

    return 0;
}