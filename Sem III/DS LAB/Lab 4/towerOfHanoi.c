#include<stdio.h>

int count=0;

void towerOfHanoi(int n, char source, char destination, char aux){
    if(n==1){
        ++count;
        printf("Move disk %d from %c to %c\n", n, source, destination);
        
    }
    else if(n>1){
        towerOfHanoi(n-1, source, aux, destination);
        ++count;
        printf("Move disk %d from %c to %c\n", n, source, destination);
        towerOfHanoi(n-1, aux, destination, source);
    }
}

void main(){
    int n;
    printf("Enter number of disks: ");
    scanf("%d", &n);
    towerOfHanoi(n, 'A', 'C', 'B');
    printf("\nTotal number of moves: %d\n", count);
}