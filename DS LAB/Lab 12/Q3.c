#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
} node;

node* newNode(int value){
    node* temp = (node*)(malloc(sizeof(node)));
    temp->data=value;
    temp->left=temp->right=NULL;
    return temp;
}

node* insert(node* root, int value){
    node* p=root;
    node* parent=NULL;

    while(p!=NULL){
        parent=p;

        if(value < p->data){
            p=p->left;
        }

        else if(value > p->data){
            p=p->right;
        }

        else return root;
    }

    node* tmp = newNode(value);
    if(parent==NULL){
        root=tmp;
    }

    else if(value < parent->data){
        parent->left=tmp;
    }

    else if(value > parent->data){
        parent->right=tmp;
    }

    return root;
}

void searchAncestor(node* root, int value){
    if(root==NULL) return; //printf("\nNo Ancestors, tree empty!!\n");

    if(value < root->data){
        printf("%d ", root->data);
        searchAncestor(root->left, value);
    }

    else if(value > root->data){
        printf("%d ", root->data);
        searchAncestor(root->right, value);
    }
}

void inOrder(node *root){
    if(root==NULL) return;
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

int main(){
    node* root=NULL;
    int n, value;
    printf("Enter number of terms: ");
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        printf("Enter element %d: ", (i+1));
        scanf("%d", &value);
        root=insert(root, value);
    }

    printf("\nIn-Order: ");
    inOrder(root);

    printf("\nSearch ancestor of key: ");
    int key;
    scanf("%d", &key);
    printf("Ancestors of %d are: ", key);
    searchAncestor(root, key);
    return 0;
}