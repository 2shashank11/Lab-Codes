#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

typedef struct node{
    char data;
    struct node* right;
    struct node* left;
} node;

typedef struct stack{
    node* item;
    struct stack* next;
} stack;

void push(stack** s, node* nodeItem){
    if(*s==NULL){
        stack *temp=malloc(sizeof(stack));
        temp->item=nodeItem;
        temp->next=NULL;
        *s=temp;
        return;
    }

    stack*temp=malloc(sizeof(stack));
    temp->item=nodeItem;
    temp->next=*s;
    *s=temp;
}

node* pop(stack **s){
    node* tempNode=(*s)->item;
    stack* tempStack=*s;
    *s=(*s)->next;
    free(tempStack);
    return tempNode;
}

bool isOperator(char i){
    return (i=='+' || i=='-' || i=='*' || i=='/');
}

bool isOperand(char i){
    return (i>='0' && i<='9');
}

node* createNode(char value){
    node* temp=malloc(sizeof(node));
    temp->data=value;
    temp->right=temp->left=NULL;
    return temp;
}

node* createTree(node* root, char* exp){
    
    stack* s;

    for(int i=(strlen(exp)-1); i>=0; i--){
        
        char value=exp[i];

        if(isOperand(value)){
            push(&s, createNode(value));
        }        

        else if(isOperator(value)){
            node* op1=pop(&s);
            node* op2=pop(&s);
            node* temp = createNode(value);
            temp->left=op1;
            temp->right=op2;
            push(&s, temp);
        }
    }

    root=(s)->item;
    return root;
}

int evaluate(node* root){
    if(!root) return 0;

    if(root->left==NULL && root->right==NULL){
        return root->data-'0';
    }

    int leftEval=evaluate(root->left);
    int rightEval=evaluate(root->right);

    if(root->data=='+') return leftEval+rightEval;
    else if(root->data=='-') return leftEval-rightEval;
    else if(root->data=='*') return leftEval*rightEval;
    else if(root->data=='/') return leftEval/rightEval;
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
    printf("Enter Prefix expression: ");
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