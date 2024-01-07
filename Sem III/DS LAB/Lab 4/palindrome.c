#include<stdio.h>
#include<string.h>

int palinCheck(char a[100], int i){
    if(i<strlen(a)-i-1 && a[i]==a[strlen(a)-i-1]){
        palinCheck(a, i+1);
    }
    else if (a[i]!=a[strlen(a)-i-1]){
        return 0;
    }
    else return 1;
}

void main(){
    char a[100];
    printf("Enter string: ");
    gets(a);
    if (palinCheck(a, 0)==1){
        printf("Palindrome");
    }
    else printf("Not palindrome");
}