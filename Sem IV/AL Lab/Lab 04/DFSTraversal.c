#include<stdio.h>
#include<stdlib.h>

typedef struct stack{
    int arr[50];
    int top;
} stack;

int isEmpty(stack *s){
    if(s->top==-1) return 1;
    else return 0;
}

void push(stack *s, int value){
    s->arr[++s->top]=value;
}

int pop(stack* s){
    return s->arr[s->top--];
}

void DFS(int i, int visited[], int a[7][7]){
    printf("%d", i);
    visited[i]=1;
    for(int j=0; j<7; j++){
        if(a[i][j]==1 && visited[j]==0){
            DFS(j, visited, a);
        }
    }
}

int main(){
    stack* s=malloc(sizeof(stack));
    s->top=-1;

    int visited[7]={0, 0, 0, 0, 0, 0, 0};

    int a[7][7]={
        {0,1,1,1,0,0,0},
        {1,0,0,1,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},        
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0},
    };

    DFS(0, visited, a);

    return 0;
}