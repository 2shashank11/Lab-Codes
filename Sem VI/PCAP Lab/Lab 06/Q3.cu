#include <stdio.h>
#include <cuda_runtime.h>

__global__ void odd_even_phase(int *arr, int n, int phase) {
    int idx = threadIdx.x + blockIdx.x * blockDim.x;

    if (idx < n - 1) {
        if ((idx % 2 == phase) && (idx < n - 1)) {
            if (arr[idx] > arr[idx + 1]) {
                int temp = arr[idx];
                arr[idx] = arr[idx + 1];
                arr[idx + 1] = temp;
            }
        }
    }
}

void odd_even_transposition_sort(int *arr, int n) {
    for (int phase = 0; phase < n; phase++) {
        odd_even_phase<<<(n + 255) / 256, 256>>>(arr, n, phase % 2);

        cudaDeviceSynchronize();
    }
}

int main() {
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int *h_arr = (int *)malloc(n * sizeof(int));

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &h_arr[i]);
    }

    int *d_arr;
    cudaMalloc((void**)&d_arr, n * sizeof(int));

    cudaMemcpy(d_arr, h_arr, n * sizeof(int), cudaMemcpyHostToDevice);

    odd_even_transposition_sort(d_arr, n);

    cudaMemcpy(h_arr, d_arr, n * sizeof(int), cudaMemcpyDeviceToHost);

    printf("Sorted Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", h_arr[i]);
    }
    printf("\n");

    cudaFree(d_arr);
    free(h_arr);

    return 0;
}


// Enter the number of elements: 5
// Enter the elements: 6 2 13 7 5
// Sorted Array: 2 5 6 7 13 