#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
} node;

node* newNode(int value){  
    struct node *temp;  
    temp = (node*)malloc(sizeof(node));  
    temp->data = value;  
    temp->left = NULL;  
    temp->right = NULL;  

    return temp;  
}  

node* createTreeRecursive(node *root, int value){
    if(root==NULL){
        return newNode(value);
    }

    if(value < root->data){
        root->left=createTreeRecursive(root->left, value);
    }

    else if(value > root->data){
        root->right=createTreeRecursive(root->right, value);
    }

    else if(value == root->data){
        return root;
    }

    return root;
}

node* createTree(node *root, int value){
    node *p=root;
    node *parent=NULL;

    while(p!=NULL){
        parent=p;
        if(value < p->data){
            p=p->left;
        }

        else if(value > p->data){
            p=p->right;
        }

        else if(value == p->data){
            return root;
        }
    }

    node* temp=newNode(value);

    if(parent==NULL){
        root = temp;
    }
    else if(value < parent->data){
        parent->left=temp;
    }
    else if(value>parent->data){
        parent->right=temp;
    }

    return root;
}

void inOrder(node* root){
    if(root==NULL) return;
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

void preOrder(node* root){
    if(root==NULL) return;
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(node *root){
    if(root==NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}

int main(){
    node* root=NULL;
    printf("Enter number of elements: ");
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        printf("Element %d: ", (i+1));
        int value;
        scanf("%d", &value);
        root=createTree(root, value);
    }
    
    printf("\nIn-order: ");
    inOrder(root);

    printf("\nPre-order: ");
    preOrder(root);

    printf("\nPost-order: ");
    postOrder(root);

    return 0;
}