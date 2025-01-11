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
        int arr[size];
        fprintf(stdout, "Enter %d elements of array: ", size-1);
        fflush(stdout);
        for(int i=1; i<size; i++){
            scanf("%d", &arr[i]);
        }
        
        for(int i=1; i<size; i++){
            if(i%2==1){
                int r = pow(arr[i], 3);
                MPI_Send( &r , 1 , MPI_INT , i , 1 , MPI_COMM_WORLD);
            }
            else{
                int r = pow(arr[i], 2);
                MPI_Send( &r , 1 , MPI_INT , i , 1 , MPI_COMM_WORLD);
            }
        }
    }

    else{
        int r;
        MPI_Recv( &r , 1 , MPI_INT , 0 , 1 , MPI_COMM_WORLD , &status);
        fprintf(stdout, "Received %d from source 0 to process %d\n", r, rank);
        fflush(stdout);
    }

    MPI_Finalize();

    return 0;
}

// Enter 4 elements of array: 1 2 3 4
// Received 1 from source 0 to process 1
// Received 4 from source 0 to process 2
// Received 27 from source 0 to process 3
// Received 16 from source 0 to process 4