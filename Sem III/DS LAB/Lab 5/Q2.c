#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 50

typedef struct STACK{
    char a[MAX_SIZE];
    int n;
    int top;
} stack;

void push(stack *s, int quotient){
    s->a[++(s->top)]=quotient;
}

void display(stack *s){
    printf("Binary form: ");
    for(int i=s->top; i>=0; i--){
        printf("%d", s->a[i]);
    }
    printf("\n");
}

int main(){
    stack *s=malloc(sizeof(stack));
    s->top=-1;
    int decimal, remainder=0;
    printf("Enter Decimal number: ");
    scanf("%d", &decimal);
    int quotient=decimal;
    
    while(quotient!=1){
        remainder=quotient%2;
        push(s, remainder);
        quotient=quotient/2;
    }
    push(s, quotient);
    display(s);

    return 0;
}