#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include <mpi.h>

int main(int argc, char* argv[]) {
    int rank, size;
    int n;
    char *s1, *s2, *local_s1, *local_s2, *local_result, *result;
    int chunk_size;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0) {
        printf("Enter the length of the strings: ");
        scanf("%d", &n);

        s1 = (char*)malloc(n + 1);
        s2 = (char*)malloc(n + 1);

        printf("Enter the first string (s1): ");
        scanf("%s", s1);
        printf("Enter the second string (s2): ");
        scanf("%s", s2);

        result = (char*)malloc(n + 1); 
    }

    MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);

    chunk_size = n / size;

    local_s1 = (char*)malloc(chunk_size + 1);
    local_s2 = (char*)malloc(chunk_size + 1);
    local_result = (char*)malloc(chunk_size * 2 + 1);

    MPI_Scatter(s1, chunk_size, MPI_CHAR, local_s1, chunk_size, MPI_CHAR, 0, MPI_COMM_WORLD);
    MPI_Scatter(s2, chunk_size, MPI_CHAR, local_s2, chunk_size, MPI_CHAR, 0, MPI_COMM_WORLD);

    for (int i = 0; i < chunk_size; i++) {
        local_result[2*i] = local_s1[i];
        local_result[2*i + 1] = local_s2[i];
    }
    local_result[2*chunk_size] = '\0'; 

    MPI_Gather(local_result, chunk_size * 2, MPI_CHAR, result, chunk_size * 2, MPI_CHAR, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        printf("The resultant string is: %s\n", result);
    }

    MPI_Finalize();

    return 0;
}
