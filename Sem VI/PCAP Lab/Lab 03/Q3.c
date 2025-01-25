#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include "mpi.h"

int count_non_vowels(char *str, int len) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        char ch = str[i];
        if (ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u') {
            count++;
        }
    }
    return count;
}

int main(int argc, char *argv[]) {
    int rank, size;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    char str[50], recvStr[50];
    int n, local_count = 0;
    int *counts = NULL;

    if (rank == 0) {
        printf("Enter String: ");
        scanf("%s", str);
        n = strlen(str);
        MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);
    } else {
        MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);
    }

    int chunk = n / size;

    MPI_Scatter(str, chunk, MPI_CHAR, recvStr, chunk, MPI_CHAR, 0, MPI_COMM_WORLD);

    local_count = count_non_vowels(recvStr, chunk);

    if (rank == 0) {
        counts = (int*) malloc(size * sizeof(int));
    }

    fprintf(stdout, "P%d non-vovels: %d\n", rank, local_count);
    fflush(stdout);

    MPI_Gather(&local_count, 1, MPI_INT, counts, 1, MPI_INT, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        int total_count = 0;
        for (int i = 0; i < size; i++) {
            total_count += counts[i];
        }
        printf("Total number of non-vowels: %d\n", total_count);
    }

    MPI_Finalize();
    return 0;
}
