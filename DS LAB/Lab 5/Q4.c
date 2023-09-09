#include<stdio.h>

int main(){
    int n, k;
    printf("Enter array length: ");
    scanf("%d", &n);
    printf("Enter number < n: ");
    scanf("%d", &k);

    int a[n];
    printf("Enter array: ");
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    int i=0;
    for(int j=0; j<k; j++){
        for(int i=0; i<n; i++){
            if(a[i]<a[i+1]){
                for(int ref=i; ref<n; ref++){
                    a[ref]=a[ref+1];
                }
                n--;
                break;
            }
        }
    }

    printf("Modified array: ");
    for(int i=0; i<n; i++){
        printf("%d ", a[i]);
    }
    return 0;
}