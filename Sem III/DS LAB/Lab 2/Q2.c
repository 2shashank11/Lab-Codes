#include<stdio.h>
#include<stdlib.h>

int* smallest(int* p, int n){
    int *q=p, *small=p;
    for(q=p; q<p+n; q++){
        if(*q<*small){
            small=q;
        }
    }
    return small;
}

int main(){
    int a[100], n;
    printf("Enter length of array: ");
    scanf("%d", &n);
    int *p = (int*) malloc(n*sizeof(int));
    printf("Enter elements: ");
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    p=a;
    int*small=smallest(p, n);
    printf("Smallest element is: %d\n", *small);
    return 0;
}