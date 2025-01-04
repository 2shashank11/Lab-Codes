#include "mpi.h"
#include<stdio.h>
#include<math.h>

int main(int argc, char* argv[]){
	int rank, size;
	
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	int operation = rank;

	int a = 5, b = 3;

	switch(operation){
	case 0: // add
		printf("Add: %d\n", a+b);
		break;
	case 1: // subtract
		printf("Subtract: %d\n", a-b);
		break;
	case 2: // multiply
		printf("Multiply: %d\n", a*b);
		break;
	case 3: // divide
		printf("Divide: %d\n", a/b);
		break;
	case 4: // power
		printf("Power: %d", pow(a, b));
		break;
	default:
		printf("Invalid!");
		break;
	}

	MPI_Finalize();
	return 0;
}
