#include <stdio.h>
#include <stdlib.h>

void addMatrices(int rows, int column, int a[rows][column], int b[rows][column], int sum[rows][column]) {
        /*int rows = sizeof(a) / sizeof(a[0]);
        int column = sizeof(a[0])/row;
        int[][] sum = new int[rows][column];*/

        // Note: This code doesn't check whether the matrices conform.
        // Consider adding a check for the rows/colums in the C version.

        int i, j;
        for (i = 0; i < rows; i++) {
            for (j = 0; j < column; j++) {
                sum[i][j] = a[i][j] + b[i][j];
            }
        }
    }
 
 void multiplyMatrices(int rows, int column, int a[rows][column], int b[rows][column], int product[rows][column]) {
        /*int rows = sizeof(a) / sizeof(a[0]);
        int column = sizeof(a[0])/row;
        int[][] product = new int[rows][column];*/

        // Note: This code doesn't check whether the matrices conform.
        // Consider adding a check for the A's colums and B's rows n the C version.
        // Ensure the product has correct dimensions!

        int i,j,k;
        for (i = 0; i < rows; i++) {
            for (j = 0; j < column; j++) {
                //product[i][j] = 0;
                //for (k = 0; k < rows; k++) {
                    product[i][j] += a[i][k] * b[k][j];
                //}
            }
        }
    }


    void printMatrix(int rows, int collums, int matrix[rows][collums]) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < collums; j++) {
            printf("%d\n", matrix[i][j]);
        }
    }
    }

int main(){
    int matrix1[2][2] = {{1, 2}, {3, 4}};
    int matrix2[2][2] = {{5, 6}, {7, 8}};
    int sum[2][2];
    int product[2][2];
   
    addMatrices(2, 2, matrix1, matrix2, sum);

    multiplyMatrices(2, 2, matrix1, matrix2, product);

    printf("\nMatrix Addition: ");
    printMatrix(2,2,sum);
    printf("\nMatrix Multiplication: ");
    printMatrix(2,2,product);

    return EXIT_SUCCESS;
}