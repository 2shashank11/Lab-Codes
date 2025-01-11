#include "mpi.h"
#include<stdio.h>
#include<string.h>

int main(int argc, char *argv[]){
    
    int rank, size;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Status status;


    if(rank==0){
        char s[5] = {'H', 'E', 'L', 'L', 'O'};
        MPI_Ssend( s , 5, MPI_CHAR , 1 , 1 , MPI_COMM_WORLD);
        fprintf(stdout, "\nSending string from process %d: ", rank);
        for(int i=0; i<5; i++){
            printf("%c", s[i]);
        }

        char r[5];
        MPI_Recv( r , 5 , MPI_CHAR , 1 , 1 , MPI_COMM_WORLD, &status);

        fprintf(stdout, "\nReceived string at process %d: ", rank);
        for(int i=0; i<5; i++){
            printf("%c", r[i]);
        }
        fflush(stdout);
        printf("\n");
    }
    else{
        char r[5];
        MPI_Recv( r , 5 , MPI_CHAR , 0 , 1 , MPI_COMM_WORLD, &status);
        fprintf(stdout, "\nToggling string at process %d", rank);
        fflush(stdout);

        for(int i=0; i<5; i++){
            r[i] = r[i]+32;
        }

        MPI_Ssend( r , 5 , MPI_CHAR , 0 , 1 , MPI_COMM_WORLD);
    }

    MPI_Finalize();

    return 0;
}

// Sending string from process 0: HELLO
// Toggling string at process 1
// Received string at process 0: hello