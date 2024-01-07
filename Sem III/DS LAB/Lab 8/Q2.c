#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX 3
typedef struct queue{
    int a[MAX];
    int rear, front;
} queue;

bool isFull(queue *q){
    return q->rear==MAX-1;
}

bool isEmpty(queue *q){
    return q->rear==-1;
}

void insertRight(queue *q, int element){
    if(q->front==-1) q->front=0;
    q->a[++q->rear]=element;
}

void insertLeft(queue *q, int element){
    if(q->front==-1) q->front=0;
    for(int i=q->rear; i>=0; i--){
        q->a[i+1]=q->a[i];
    }
    q->rear++;
    q->a[0]=element;
}

int deleteLeft(queue *q){
    int i=q->a[0];
    for(int i=0; i<q->rear; i++){
        q->a[i]=q->a[i+1];
    }
    q->rear--;
    return i;
}

void display(queue *q){
    printf("Queue: ");
    for(int i=0; i<=q->rear; i++){
        printf("%d ", q->a[i]);
    }
    printf("\n");
}

int main(){
    queue *q = (queue*)(malloc(sizeof(queue)));
    q->front=q->rear=-1;

    while(true){
        printf("\n1. Insert Right \n2. Insert Left \n3. Delete Left \n4. Display \n5. Exit \nChoice: ");
        int choice;
        scanf("%d", &choice);

        if(choice==1){
            if(!isFull(q)){
                printf("Enter element: ");
                int element;
                scanf("%d", &element);
                insertRight(q, element);
            }
            else printf("\nQueue Full!!\n");
        }
        else if(choice==2){
            if(!isFull(q)){
                printf("Enter element: ");
                int element;
                scanf("%d", &element);
                insertLeft(q, element);
            }
            else printf("\nQueue Full!!\n");
        }

        else if(choice==3){
            if(!isEmpty(q)){
                printf("Deleted: %d", deleteLeft(q));
            }
            else printf("\nQueue Empty!!\n");
        }

        else if(choice==4){
            display(q);
        }

        else if(choice==5){
            break;
        }

        else printf("\nEnter a valid option!!\n");

    }
}