#include <stdio.h>
#include "mpi.h"
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int rank, size;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int *A, n, m;
    float sum = 0, avg = 0, avgRecv[size], finalAvg = 0;

    if (rank == 0) {
        printf("Enter any number: ");
        scanf("%d", &m);
        n = m * size;
        A = (int *)malloc(n * sizeof(int));
        printf("Enter %d elements: ", n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &A[i]);
        }
    }

    MPI_Bcast(&m, 1, MPI_INT, 0, MPI_COMM_WORLD);
    int B[m];
    MPI_Scatter(A, m, MPI_INT, B, m, MPI_INT, 0, MPI_COMM_WORLD);


    fprintf(stdout, "Received ");
    for (int i = 0; i < m; i++) {
        fprintf(stdout, "%d ", B[i]);
        sum += B[i];
    }
    avg = sum / (1.0 * m);
    fprintf(stdout, "in P%d and average is: %.2f \n", rank, avg);
    fflush(stdout);

    MPI_Gather(&avg, 1, MPI_FLOAT, &avgRecv, 1, MPI_FLOAT, 0, MPI_COMM_WORLD);

    if (rank == 0) {
    for (int i = 0; i < size; i++) {
        finalAvg += avgRecv[i];
    }
    finalAvg /= size;
    fprintf(stdout, "Final average of all the averages is: %.2f\n", finalAvg);
    fflush(stdout);
}

    MPI_Finalize();
    return 0;
}
