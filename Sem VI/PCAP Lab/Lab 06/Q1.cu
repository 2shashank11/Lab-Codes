#include<stdio.h>
#include<stdlib.h>
#include<cuda_runtime.h>
#include<device_launch_parameters.h>

__global__ void convolution_1D_basic_kernel(float *N, float *M, float *P, int Mask_Width, int Width){
    int i = blockIdx.x*blockDim.x+threadIdx.x;

    float Pvalue = 0;
    int N_start_point = i-(Mask_Width/2);
    for(int j=0; j<Mask_Width; j++){
        if(N_start_point + j >= 0 && N_start_point + j < Width){
            Pvalue += N[N_start_point + j] * M[j];
        }
    }
    P[i] = Pvalue;
}

int main(void){
    int n, w;
    float *a, *m, *p;
    float *d_a, *d_p, *d_m;

    printf("Enter size of array: ");
    scanf("%d", &n);
    a = (float*)(malloc(n*sizeof(float)));
    p = (float*)(malloc(n*sizeof(float)));
    cudaMalloc((void**)&d_a, n*sizeof(float));
    cudaMalloc((void**)&d_p, n*sizeof(float));

    printf("Enter %d elements of the array: ", n);
    for(int i=0; i<n; i++){
        scanf("%f", &a[i]);
    }

    printf("Enter width of the mask: ");
    scanf("%d", &w);
    m = (float*)(malloc(w*sizeof(float)));
    cudaMalloc((void**)&d_m, w*sizeof(float));

    printf("Enter %d elements of the mask: ", w);
    for(int i=0; i<w; i++){
        scanf("%f", &m[i]);
    }

    cudaMemcpy(d_a, a, n*sizeof(float), cudaMemcpyHostToDevice);
    cudaMemcpy(d_m, m, w*sizeof(float), cudaMemcpyHostToDevice);

    convolution_1D_basic_kernel<<<1, n>>>(d_a, d_m, d_p, w, n);
    cudaMemcpy(p, d_p, n*sizeof(float), cudaMemcpyDeviceToHost);

    printf("Resultant array is: ");
    for(int i=0; i<n; i++){
        printf("%.2f ", p[i]);
    }
    printf("\n");

    return 0;
}


// Enter size of array: 7
// Enter 7 elements of the array: 1 2 3 4 5 6 7
// Enter width of the mask: 5
// Enter 5 elements of the mask: 3 4 5 4 3
// Resultant array is: 22.00 38.00 57.00 76.00 95.00 90.00 74.00 