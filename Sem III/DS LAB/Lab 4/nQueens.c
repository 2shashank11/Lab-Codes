#include<stdio.h>

int count=0;

int isSafe(int arr[50][50], int x, int y, int n){

    for(int row=0; row<x; row++){
        if(arr[row][y]==1){
            return 0;
        }
    }
//checking top-left diagonal
    int row=x;
    int col=y;
    while(row>=0 && col>=0){
        if(arr[row][col]==1){
            return 0;
        }
        row--;
        col--;
    }

//checking top-right diagonal
    row=x--;
    col=y++;
    while(row>=0 && col<n){
        if(arr[row][col]==1){
            return 0;
        }
        row--;
        col++;
    }

    return 1;
}

int nQueen(int arr[50][50], int x, int y, int n){

    if(x>=n){
        return 1;
    }

    for(int col=0; col<n; col++){
        if(isSafe(arr, x, col, n)){
            arr[x][col]=1;
            ++count;

            if(nQueen(arr, x+1, y, n)){
                return 1;
            }

            arr[x][col]=0;
            --count; //backtracking
        }
        return 0;
    }
}

int main(){
    int n;
    scanf("%d", &n);
    int arr[n][n];
    for (int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            arr[i][j]=0;
        }
    }

    if(nQueen(arr, 0, 0, n)==1){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                printf("%d\t", arr[i][j]);
            }
            printf("\n");
        }
    }
    printf("%d", count);
    return 0;
}