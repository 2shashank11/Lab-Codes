#include<stdio.h>
#include<stdlib.h>

typedef struct queue{
    int arr[50];
    int rear;
} queue;

int isEmpty(queue *q){
    if(q->rear==-1) return 1;
    else return 0;
}

void enqueue(queue* q, int value){
    q->arr[++q->rear]=value;
}

int dequeue(queue *q){
    int dequeued=q->arr[0];
    for(int i=0; i<q->rear; i++){
        q->arr[i]=q->arr[i+1];
    }
    q->rear--;
    return dequeued;
}

int main(){
    queue* q=malloc(sizeof(queue));
    q->rear=-1;

    int node; 
    int i=0;
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
    printf("%d", i);
    visited[i]=1;
    enqueue(q, i);
    while(!isEmpty(q)){

        int node=dequeue(q);
        for(int j=0; j<7; j++){
            if(a[node][j]==1 && visited[j]==0){
                printf("%d", j);
                visited[j]=1;
                enqueue(q, j);
            }
        }
    }
    return 0;
}