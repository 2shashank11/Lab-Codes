#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
} node;

typedef struct stack{
    node* data;
    struct stack* next;
} stack;

int isEmpty(stack *s){
    if(s==NULL) return 1;
    else return 0;
}

node* pop(stack **s){
    node* item;
	stack* top;
	top = *s;
	item = top->data;
	*s = top->next;
	free(top);
	return item;
}

void push(stack **s, node* n){
    if(*s==NULL){
        *s = malloc(sizeof(stack));
        (*s)->data=n;
        return;
    }
    stack* temp = malloc(sizeof(stack));
    temp->data=n;
    temp->next=*s;
    *s=temp;
}

void inOrderIter(node* root) {
    node* currentNode = root;
    stack* s = NULL;

    while (currentNode || !isEmpty(s)) {
        if (currentNode) {
            push(&s, currentNode);
            currentNode = currentNode->left;
        } else {
            currentNode = pop(&s);
            printf("%d ", currentNode->data);
            currentNode = currentNode->right;
        }
    }
}

void preOrderIter(node* root) {
    node* currentNode = root;
    stack* s = NULL;

    while (currentNode || !isEmpty(s)) {
        if (currentNode) {
            printf("%d ", currentNode->data);
            push(&s, currentNode);
            currentNode = currentNode->left;
        } else {
            currentNode = pop(&s);
            currentNode = currentNode->right;
        }
    }
}

void postOrderiter(node* root){
    stack* s=NULL;

    if (root == NULL) {
        return;
    }

    do {
        while (root) {
            if (root->right) {
                push(&s, root->right);
            }
            push(&s, root);
            root = root->left;
        }

        root = pop(&s);

        if (root->right && root->right == s->data) {
            pop(&s);
            push(&s, root);
            root = root->right;
        } else {
            printf("%d ", root->data);
            root = NULL;
        }
    } while (!isEmpty(s));
}


node* createNode(int value){
    node* temp = malloc(sizeof(node));
    temp->data=value;
    temp->left=temp->right=NULL;
    return temp;
}

node* createTree(node* root, int value){
    if(root==NULL){
        return createNode(value);
    }

    if(value < root->data){
        root->left=createTree(root->left, value);
    }

    else if(value > root->data){
        root->right=createTree(root->right, value);
    }

    return root;
}

int main(){
    node* root=NULL;
    int n, value;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        printf("Element %d: ", (i+1));
        scanf("%d", &value);
        root=createTree(root, value);
    }

    printf("\nPreorder: ");
    preOrderIter(root);
    
    printf("\nInorder: ");
    inOrderIter(root);

    printf("\nPostorder: ");
    postOrderiter(root);

    return 0;
}