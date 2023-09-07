#include<stdio.h>
#include<string.h>

void strCopy(char a[], char b[], int i){
    if(a[i]!='\n'){
        b[i]=a[i];
        strCopy(a, b, i+1);
    }

    else {
        return ;
    }
}

void main(){
    char a[100], b[100];
    printf("Enter string: ");
    gets(a);
    int i=0;
    strCopy(a, b, i);
    printf("Copied string is: ");
    b[strlen(b)+1]='\n';
    puts(b);
}