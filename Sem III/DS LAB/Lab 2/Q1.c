#include <stdio.h>
#include <stdlib.h>

void reverse(int* p, int* q, int n){
    int* i = p;
    for(i=p, q=p+n-1; i<p+n-1; i++, q--){
        int temp = *i;
        *i=*q;
        *q=temp;                                                                                                                                                                          
    }
}

int main(){
    int a[100], n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements: \n");
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    int *p=a, *q=a+n-1;
    reverse(p, q, n);

    for(int i=0; i<n; i++){
        printf("%d ",a[i]);
    } 
    printf("\n");
    return 0;
}