#include <stdio.h>
#include <cuda_runtime.h>

#define N 4

__global__ void matrixAddRow(int *A, int *B, int *C, int width) {
    int row = blockIdx.x * blockDim.x + threadIdx.x;
    if (row < width) {
        for (int col = 0; col < width; col++) {
            C[row * width + col] = A[row * width + col] + B[row * width + col];
        }
    }
}

__global__ void matrixAddCol(int *A, int *B, int *C, int width) {
    int col = blockIdx.x * blockDim.x + threadIdx.x;
    if (col < width) {
        for (int row = 0; row < width; row++) {
            C[row * width + col] = A[row * width + col] + B[row * width + col];
        }
    }
}

__global__ void matrixAddElement(int *A, int *B, int *C, int width) {
    int row = blockIdx.y * blockDim.y + threadIdx.y;
    int col = blockIdx.x * blockDim.x + threadIdx.x;
    if (row < width && col < width) {
        C[row * width + col] = A[row * width + col] + B[row * width + col];
    }
}

int main() {
    int A[N][N], B[N][N], C[N][N];
    int *d_A, *d_B, *d_C;

    printf("Enter matrix 1: \n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter matrix 2: \n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    cudaMalloc((void**)&d_A, N * N * sizeof(int));
    cudaMalloc((void**)&d_B, N * N * sizeof(int));
    cudaMalloc((void**)&d_C, N * N * sizeof(int));

    cudaMemcpy(d_A, A, N * N * sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(d_B, B, N * N * sizeof(int), cudaMemcpyHostToDevice);

    // Row Addition
    matrixAddRow<<<1, N>>>(d_A, d_B, d_C, N);

    // Column Addition
    // matrixAddCol<<<1, N>>>(d_A, d_B, d_C, N);

    // Element Addition
    // dim3 threadsPerBlock(N, N);
    // matrixAddElement<<<1, threadsPerBlock>>>(d_A, d_B, d_C, N);



    cudaMemcpy(C, d_C, N * N * sizeof(int), cudaMemcpyDeviceToHost);

    printf("Result: \n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    cudaFree(d_A);
    cudaFree(d_B);
    cudaFree(d_C);

    return 0;
}

// Enter matrix 1: 
// 1 2 3 4
// 1 2 3 4
// 1 2 3 4
// 1 2 3 4

// Enter matrix 2: 
// 5 6 7 8
// 5 6 7 8
// 5 6 7 8
// 5 6 7 8

// Result: 
// 6 8 10 12 
// 6 8 10 12 
// 6 8 10 12 
// 6 8 10 12