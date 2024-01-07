#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_SIZE 50

typedef struct stack{
    int top;
    char a[MAX_SIZE];
} stack;

void push(stack *s, char element){
    s->a[++(s->top)]=element;
}

int main(){
    stack *s = malloc(sizeof(stack));
    s->top=-1;
    printf("Enter string: ");
    char str[MAX_SIZE];
    gets(str);
    for(int i=strlen(str)-1; i>=0; i--){
        push(s, str[i]);
    }
    s->a[++(s->top)]='\0';

    if(strcmp(s->a, str)==0){
        printf("Palindrone");
    }
    else{
        printf("Not Palindrome");
    }
    return 0;
}