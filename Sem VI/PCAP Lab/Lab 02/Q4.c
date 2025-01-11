#include "mpi.h"
#include<stdio.h>
#include<math.h>

int main(int argc, char *argv[]){

    int rank, size;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Status status;
    
    if(rank==0){
        int n;
        fprintf(stdout, "Enter number: ");

        scanf("%d", &n);

        n++;
        MPI_Send( &n , 1 , MPI_INT , rank+1 , 1 , MPI_COMM_WORLD);
        printf("Sent %d from P%d to P%d\n", n, rank, rank+1);

        MPI_Recv( &n , 1 , MPI_INT , size-1 , 1 , MPI_COMM_WORLD , &status);
        printf("Received %d from P%d to P%d\n", n, size-1, rank);

        fflush(stdout);
    }

    else{
        int n;
        MPI_Recv( &n , 1 , MPI_INT , rank-1 , 1 , MPI_COMM_WORLD , &status);

        fprintf(stdout, "Received %d from P%d to P%d\n", n, rank-1, rank);

        n++;
        MPI_Send( &n , 1 , MPI_INT , (rank+1)%size , 1 , MPI_COMM_WORLD);
        printf("Sending %d from P%d to P%d\n", n, rank, (rank+1)%size);

        fflush(stdout);
    }   

    MPI_Finalize();

    return 0;
}

// Enter number: 99
// Sent 100 from P0 to P1
// Received 102 from P2 to P0
// Received 100 from P0 to P1
// Sending 101 from P1 to P2
// Received 101 from P1 to P2
// Sending 102 from P2 to P0