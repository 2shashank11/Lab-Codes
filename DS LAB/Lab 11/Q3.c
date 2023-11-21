#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

typedef struct node{
    char data;
    struct node* left;
    struct node* right;
} node;

typedef struct stack{
    node* item;
    struct stack* next;
} stack;

bool isOperator(char value){
    return (value=='+' || value=='-' || value=='/' || value=='*');
}

bool isOperand(char value){
    return (value>='0' && value<='9');
}

void push(stack **s, node* value){
    if((*s)==NULL){
        stack* temp=malloc(sizeof(stack));
        temp->item=value;
        temp->next=NULL;
        (*s)=temp;
        return;
    }

    stack* temp=malloc(sizeof(node));
    temp->item=value;
    temp->next=(*s);
    (*s)=temp;
}

node* pop(stack **s){
    node* temp=(*s)->item;
    stack* t=*s;
    *s=(*s)->next;
    free(t);
    return temp;
}

node* createNode(char value){
    node* temp = malloc(sizeof(node));
    temp->data=value;
    temp->right=NULL;
    temp->left=NULL;
    return temp;
}

node* createTree(node* root, char* exp){

    stack *s=NULL;
    
    for(int i=0; exp[i]!='\0'; i++){
        char value=exp[i];

        if(root==NULL){
        root=createNode(value);
        }
        
        if(isOperand(value)){
            node* temp=createNode(value);
            push(&s, temp);
        }

        else if(isOperator(value)){
            root=createNode(value);
            node* op1=pop(&s);
            node* op2=pop(&s);
            root->right=op1;
            root->left=op2;
            push(&s, root);
        }

    }
    root=(s)->item;
    return root;
}

int evaluate(node* root){
    if(root==NULL) return 0;

    if(root->left==NULL && root->right==NULL){
        return root->data-'0';
    }

    int leftEval = eval(root->left);
    int rightEval = eval(root->right);

    if(root->data == '+') return leftEval+rightEval;
    else if(root->data == '-') return leftEval-rightEval;
    else if(root->data == '*') return leftEval*rightEval;
    else if(root->data == '/') return leftEval/rightEval;
}

void inorder(node* root){
    if(root==NULL) return;
    inorder(root->left);
    printf("%c", root->data);
    inorder(root->right);
}

void preorder(node* root){
    if(root==NULL) return;
    printf("%c", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(node* root){
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%c", root->data);
}

int main(){
    char exp[50];
    printf("Enter Postfix expression: ");
    gets(exp);

    node* root=NULL;
    root=createTree(root, exp);

    printf("\nInorder: ");
    inorder(root);

    printf("\nPreorder: ");
    preorder(root);

    printf("\nPostorder: ");
    postorder(root);

    printf("\nEvaluation: %d", evaluate(root));
}