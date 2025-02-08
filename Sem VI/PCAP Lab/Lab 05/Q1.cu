#include <stdio.h>

const short N = 5 ;

__global__ void Vector_Addition_Block ( const int *dev_a , const int *dev_b , int *dev_c_block){
    unsigned short tid = blockIdx.x ;
     
    if ( tid < N ){
        dev_c_block [tid] = dev_a[tid] + dev_b[tid] ;
    }
}

__global__ void Vector_Addition_Thread ( const int *dev_a , const int *dev_b , int *dev_c_thread){
    unsigned short tid = threadIdx.x ;
     
    if ( tid < N ){
        dev_c_thread [tid] = dev_a[tid] + dev_b[tid] ;
    }

}


int main (void){

    int Host_a[N], Host_b[N], Host_c_thread[N], Host_c_block[N];

    int *dev_a , *dev_b, *dev_c_thread, *dev_c_block ;

    cudaMalloc((void **)&dev_a , N*sizeof(int) );
    cudaMalloc((void **)&dev_b , N*sizeof(int) );
    cudaMalloc((void **)&dev_c_thread , N*sizeof(int) );
    cudaMalloc((void **)&dev_c_block , N*sizeof(int) );

    for ( int i = 0; i <N ; i++ ){
        Host_a[i] = -i ;
        Host_b[i] = i*i ; 
    }

    cudaMemcpy (dev_a , Host_a , N*sizeof(int) , cudaMemcpyHostToDevice);
    cudaMemcpy (dev_b , Host_b , N*sizeof(int) , cudaMemcpyHostToDevice);

    //BLOCK
    printf("\nBlock Vector Sum: \n");
    Vector_Addition_Block <<< N, 1  >>> (dev_a , dev_b , dev_c_block ) ;

    cudaMemcpy(Host_c_block , dev_c_block , N*sizeof(int) , cudaMemcpyDeviceToHost);

    for ( int i = 0; i<N; i++ ){
        printf ("%d + %d = %d\n", Host_a[i] , Host_b[i] , Host_c_block[i] ) ;
    }

    //THREAD
    printf("\nThread Vector Sum: \n");
    Vector_Addition_Thread <<< 1, N  >>> (dev_a , dev_b , dev_c_thread ) ;

    cudaMemcpy(Host_c_thread , dev_c_thread , N*sizeof(int) , cudaMemcpyDeviceToHost);

    for ( int i = 0; i<N; i++ ){
        printf ("%d + %d = %d\n", Host_a[i] , Host_b[i] , Host_c_thread[i] ) ;
    }


    cudaFree (dev_a) ;
    cudaFree (dev_b) ;
    cudaFree (dev_c_block) ;
    cudaFree(dev_c_thread);

    return 0 ;
}