#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
} node;

node* createNode(int value){
    node* temp=malloc(sizeof(node));
    temp->data=value;
    temp->left=temp->right=NULL;
    return temp;
}

node* createTree(node* root, int value){
    if(root==NULL){
        return createNode(value);
    }
    node *p=root, *parent=NULL;
    while(p!=NULL){
        parent=p;
        if(value < p->data){
            p=p->left;
        }
        else if(value > p->data){
            p=p->right;
        }
        else if(value==p->data){
            return root;
        }
    }

    node* temp=malloc(sizeof(node));
    temp=createNode(value);

    if(value < parent->data){
        parent->left=temp;
    }
    else {
        parent->right=temp;
    }

    return root;
}

node* copyTree(node* root, node* copy){
    if(!root) return NULL;

    copy=createNode(root->data);

    copy->left=copyTree(root->left, copy->left);
    copy->right=copyTree(root->right, copy->left);

    return copy;
}

void inorder(node *root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int compareTree(node* a, node* b){

    if(a==NULL && b==NULL) return 1;

    if (a != NULL && b != NULL) {
        return (a->data == b->data && compareTree(a->left, b->left) && compareTree(a->right, b->right));
    }

    return 0;
}

int main(){
    node *root1=NULL, *copy=NULL, *root2=NULL;
    int n, value;
    printf("Enter number of elements for first tree: ");
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        printf("Element %d: ", (i+1));
        scanf("%d", &value);
        root1=createTree(root1, value);
    }

    printf("\nEnter number of elements for second tree: ");
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        printf("Element %d: ", (i+1));
        scanf("%d", &value);
        root2=createTree(root2, value);
    }

    printf("\nIn_order of first tree: ");
    inorder(root1);

    copy=copyTree(root1, copy);
    printf("\nIn-order of copied tree: ");
    inorder(copy);

    printf("\nIn_order of second tree: ");
    inorder(root2);

    bool comparison=compareTree(root1, root2);
    printf("\nComparing: %d", comparison);
}