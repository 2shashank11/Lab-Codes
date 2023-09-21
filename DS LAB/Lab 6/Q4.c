#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define MAX_LENGTH 100

typedef struct stack{
    char a[MAX_LENGTH];
    int top;
} stack;

bool isEmpty(stack *s){
    if(s->top==-1) return true;
    else return false;
}

void push(stack *s, char x){
    s->top++;
    s->a[s->top]=x;
}

char pop(stack *s){
    return s->a[s->top--];
}

bool isOperand(char x){
    if(x>='0' && x<='9' || x>='a' && x<='z' || x>='A' && x<='Z'){
        return true;
    }
    else return false;
}

bool isOperator(char x){
    if(x=='^' || x=='/' || x=='*' || x=='+' || x=='-'){
        return true;
    }
    else return false;
}

void prefixToPostfix(stack *s, char exp[MAX_LENGTH]){
    for(int i=0; i<strlen(exp); i++){
        if(isOperand(exp[i])){
            push(s, exp[i]);
        }

        else if(isOperator(exp[i])){
            char p = pop(s);
            char q = pop(s);
            char postFixExpr[3] = {p, q, exp[i]};
            strcat(postFixExpr, s->a + s->top+1);
            strcpy(s->a + s->top+1, postFixExpr);
        }
    }
}

int main(){
    stack *s = malloc(sizeof(stack));
    printf("Enter prefix expression: ");
    char exp[MAX_LENGTH];
    scanf("%s", exp);
    for(int i=0; i<strlen(exp)/2; i++){
        char temp = exp[i]; 
        exp[i] = exp[strlen(exp)-i-1];
        exp[strlen(exp)-i-1] = temp;
    }
    printf("Postfix converted expression: ");
    prefixToPostfix(s, exp); 
    puts(s->a);
    free(s);
    return 0;
}