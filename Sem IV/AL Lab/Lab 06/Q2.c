#include <stdio.h>  

int opcount=0;

void swap(int* a, int* b) {  
    int t = *a;  
    *a = *b;  
    *b = t; 
    opcount++; 
}  
int partition(int arr[], int low, int high) {  
    int pivot = arr[high];  
    int i = (low - 1);  
  
    for (int j = low; j <= high - 1; j++) {  
        if (arr[j] < pivot) {  
            i++;  
            swap(&arr[i], &arr[j]);  
        }  
    }  
    swap(&arr[i + 1], &arr[high]);  
    return (i + 1);  
}  
void quickSort(int arr[], int low, int high) {  
    if (low < high) {  
        int pi = partition(arr, low, high);  
        quickSort(arr, low, pi - 1);  
        quickSort(arr, pi + 1, high);  
    }  
}  
  
// Function to print the array  
void printArray(int arr[], int size) {  
    int i;  
    for (i = 0; i < size; i++)  
        printf("%d ", arr[i]);  
    printf("\n");  
}  
  
int main() {  
    int size;
    printf("Enter number of elements: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter elements: \n");
    for(int i=0; i<size; i++){
        scanf("%d", &arr[i]);
    }
    int n=sizeof(arr)/sizeof(arr[0]);
    quickSort(arr, 0, n-1);
    printf("Sorted array: ");
    printArray(arr, n);
    printf("opcount: %d\n", opcount);
    return 0;  
}  
