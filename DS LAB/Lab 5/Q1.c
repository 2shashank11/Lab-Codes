#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX_SIZE 100

typedef struct STACK{
    char a[MAX_SIZE];
    int n;
    int top;
} stack;

bool isFull(stack* s){
    if(s->top==s->n-1){
        return true;
    }
    else return false;
}

bool isEmpty(stack* s){
    if(s->top==-1){
        return true;
    }
    else return false;
}

void push(stack *s){
    printf("\nEnter element to push: ");
    int element;
    scanf(" %c", &element);
    s->a[++(s->top)]=element;
}

void pop(stack *s){
    printf("\nPopped %c out of stack\n", s->a[s->top]);
    //s->a[s->top]="0";
    s->top--;
}

void display(stack *s){
    printf("\nDisplaying Stack: ");
    for(int i=0; i<=s->top; i++){
        printf("%c ", s->a[i]);
    }
    printf("\n");
}

int main(){
    stack *s=malloc(sizeof(stack));
    s->top=-1;
    printf("Enter size of stack: ");
    scanf("%d", &s->n);

    while(true){
        printf("\n1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Select any option: ");
        int choice;
        scanf("%d", &choice);

        if(choice==1){
            if(!isFull(s)){
                push(s);
            }
            else printf("\nStack Overflow!!\n");
        }

        else if (choice==2){
            if(!isEmpty(s)){
                pop(s);
            }
            else printf("\nStack Underflow!!\n");
        }

        else if(choice==3){
            display(s);
        }
            
        else if (choice==4) break;
            
        else printf("\nSelect valid option\n");
    }
    return 0;
}