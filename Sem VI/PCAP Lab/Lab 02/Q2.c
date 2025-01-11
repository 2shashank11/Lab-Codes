#include "mpi.h"
#include<stdio.h>


int main(int argc, char *argv[]){

    int rank, size;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Status status;

    if (rank == 0){
        int n = 5;
        fprintf(stdout, "\nSending %d to processes:\n", n);
        fflush(stdout);

        for(int i=1; i<size; i++){
            MPI_Send( &n , 1 , MPI_INT , i , 1 , MPI_COMM_WORLD);
        }
    }
    else{
        int r;
        MPI_Recv( &r , 1 , MPI_INT , 0 , 1 , MPI_COMM_WORLD , &status);
        fprintf(stdout, "Received %d at process %d from process 0\n", r, rank);
        fflush(stdout);
    }


    MPI_Finalize();
    return 0;
}

// Sending 5 to processes:
// Received 5 at process 1 from process 0
// Received 5 at process 2 from process 0