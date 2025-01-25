#include<stdio.h>
#include "mpi.h"

int factorial(int n){
    if(n==0) return 1;
    return n * factorial(n-1);
}

int main( int argc, char *argv[]){
    int rank, size;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    
    int N, A[10], B[10], c, i;
    
    if(rank==0){
        N = size;
        fprintf(stdout, "Enter %d values: ", N);
        fflush(stdout);
        for(int i=0; i<N; i++){
            scanf("%d", &A[i]);
        }
    }
    MPI_Scatter( A , 1 , MPI_INT , &c , 1 , MPI_INT , 0 , MPI_COMM_WORLD);
    fprintf(stdout, "received %d in P%d\n", c, rank);
    fflush(stdout);

    c = factorial(c);
    MPI_Gather( &c , 1 , MPI_INT , B , 1 , MPI_INT , 0 , MPI_COMM_WORLD);

    if(rank==0){
        fprintf(stdout, "Result gathered in root: ");
        fflush(stdout);
        int sum=0;
        for(int i=0; i<N; i++){
            fprintf(stdout, "%d ", B[i]);
            sum+=B[i];
        }
        fprintf(stdout, "\nSum: %d\n", sum);
        fflush(stdout);
    }
    
    MPI_Finalize();
    
    return 0;
}