#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 3

typedef struct queue{
    int a[MAX];
    int rear, front;
} queue;

void pqinsert(queue *q, int element){
    q->a[++q->rear]=element;
}

int pqmindelete(queue *q){
    int min, index;
    min=q->a[0];
    for(int i=0; i<=q->rear; i++){
        if(q->a[i]<min){
            min=q->a[i];
            index=i;
        }
    }

    for(int i=index+1; i<=q->rear; i++){
        q->a[index]=q->a[i];
    }
    q->rear--;
    return min;
}

void display(queue *q){
    printf("Queue: ");
    for(int i=0; i<=q->rear; i++){
        printf("%d ", q->a[i]);
    }
    printf("\n");
}

int main(){
    queue *q = (queue *)malloc(sizeof(queue));
    q->front = q->rear = -1;
    while (true){
        printf("\n1. Insert \n2. Delete \n3. Exit \nChoice: ");
        int choice;
        scanf("%d", &choice);

        if (choice == 1){
            if (q->rear == MAX - 1) printf("\nQueue full!!\n");

            else{
                printf("Enter element: ");
                int element;
                scanf("%d", &element);
                pqinsert(q, element);
                display(q);
            }
        }

        else if (choice == 2){
            if (q->rear == -1) printf("\nQueue Empty!!\n");
            else{
                printf("\nDequeued: %d\n", pqmindelete(q));
                display(q);
            }
        }

        else if (choice == 3) break;

            else printf("\nEnter valid option!!\n");
    }
    return 0;
}