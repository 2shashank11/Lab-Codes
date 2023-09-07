#include<stdio.h>
#include<stdlib.h>

int r1, c1, r2, c2;

int **multiply(int **p1, int **p2) {
    int **a;
    a = (int **)malloc(r1 * sizeof(int *));
    for (int i = 0; i < r1; i++) {
        a[i] = (int *)malloc(c2 * sizeof(int));
        for (int j = 0; j < c2; j++) {
            a[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                a[i][j] += p1[i][k] * p2[k][j];
            }
        }
    }
    return a;
}

int main() {
    printf("Enter rows and columns of matrix 1: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter rows and columns of matrix 2: ");
    scanf("%d %d", &r2, &c2);
    if (c1 != r2) {
        printf("Matrix multiplication not possible.\n");
        exit(0);
    }
    
    int **mat1, **mat2;

    mat1 = (int **)malloc(r1 * sizeof(int *));
    mat2 = (int **)malloc(r2 * sizeof(int *));

    printf("Enter matrix 1:\n");
    for (int i = 0; i < r1; i++) {
        mat1[i] = (int *)malloc(c1 * sizeof(int));
        for (int j = 0; j < c1; j++) {
            scanf("%d", &mat1[i][j]);
        }
    }

    printf("Enter matrix 2:\n");
    for (int i = 0; i < r2; i++) {
        mat2[i] = (int *)malloc(c2 * sizeof(int));
        for (int j = 0; j < c2; j++) {
            scanf("%d", &mat2[i][j]);
        }
    }

    int **res = multiply(mat1, mat2);
    printf("Result:\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            printf("%d\t", res[i][j]); 
        }
        printf("\n");
    }

    for (int i = 0; i < r1; i++) {
        free(mat1[i]);
    }
    free(mat1);
    
    for (int i = 0; i < r2; i++) {
        free(mat2[i]);
    }
    free(mat2);

    for (int i = 0; i < r1; i++) {
        free(res[i]);
    }
    free(res);

    return 0;
}
