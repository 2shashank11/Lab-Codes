#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *left;
    struct node* right;
} node;

node* newNode(int value){
    node* temp = (node*)(malloc(sizeof(node)));
    temp->data=value;
    temp->left=temp->right=NULL;
    return temp;
}

node* createTree(node* root, int value){
    if(root==NULL){
        return newNode(value);
    }

    if(value < root->data){
        root->left=createTree(root->left, value);
    }

    else if(value > root->data){
        root->right=createTree(root->right, value);
    }

    else if(value == root->data){
        return root;
    }
    return root;
}

void inorder(node* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void inorderSuccessor(node* root, int value){
    node* p = root;
    if(value < p->data){
        p=p->left;
    }

    else if(value > p->data){
        p=p->right;
    }

    else if(value == p->data){
        p=p->right;
        while(p->left!=NULL){
            p=p->left;
        }
    }

    printf("Inorder Successor is: %d", p->data);
}

int main(){
    int n, value;
    node* root=NULL;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        printf("Element %d: ", (i+1));
        scanf("%d", &value);
        root=createTree(root, value);
    }

    printf("\nIn-order: ");
    inorder(root);
    
    int key;
    printf("\nInorder Successor of: ");
    scanf("%d", &key);
    inorderSuccessor(root, key);
    return 0;
}