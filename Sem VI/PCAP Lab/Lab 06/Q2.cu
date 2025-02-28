#include <stdio.h>
#include <cuda_runtime.h>

__global__ void parallel_selection_sort(int *arr, int n, int step) {
    int idx = threadIdx.x + blockIdx.x * blockDim.x;

    if (idx >= step && idx < n) {
        int min_idx = step;

        for (int i = step + 1; i < n; i++) {
            if (arr[i] < arr[min_idx]) {
                min_idx = i;
            }
        }

        if (min_idx != step) {
            int temp = arr[step];
            arr[step] = arr[min_idx];
            arr[min_idx] = temp;
        }
    }
}

void selection_sort_parallel(int *arr, int n) {
    for (int step = 0; step < n - 1; step++) {
        parallel_selection_sort<<<(n + 255) / 256, 256>>>(arr, n, step);

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

    selection_sort_parallel(d_arr, n);

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