#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
} node;

node* createNode(int value){
    node* temp=(node*)(malloc(sizeof(node)));
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

    node* temp = (node*)(malloc(sizeof(node)));
    temp=createNode(value);
    
    if(value<parent->data){
        parent->left=temp;
    }
    else{//if (value>parent->data)
        parent->right=temp;
    }

    return root;
}

void inorder(node* root){
    if(root==NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}


node* deleteNodeiPre(node* root, int value){
    if(root==NULL){
        return NULL;
    }

    if(value < root->data){
        root->left=deleteNodeiPre(root->left, value);
    }

    else if(value > root->data){
        root->right=deleteNodeiPre(root->right, value);
    }

    else{
        if(root->left==NULL){
            node* temp=root->right;
            free(root);
            return temp;
        }

        else if(root->right==NULL){
            node* temp=root->left;
            free(root);
            return temp;
        }

        node* temp=root->left;
        while(temp->right!=NULL){
            temp=temp->right;
        }
        root->data=temp->data;
        root->left=deleteNodeiPre(root->left, temp->data);
    }

    return root;
}


node* deleteNodeiSucc(node* root, int value){
    if(root==NULL) return NULL;

    if(value < root->data){
        root->left = deleteNodeiSucc(root->left, value);
    }

    else if(value > root->data){
        root->right = deleteNodeiSucc(root->right, value);
    }

    else{
        if(root->right==NULL){
            node* temp=root->left;
            free(root);
            return temp;
        }
        else if(root->left==NULL){
            node* temp=root->right;
            free(root);
            return temp;
        }
        
        node* temp=root->right;
        while(temp->left!=NULL){
            temp=temp->left;
        }
        root->data=temp->data;
        root->right=deleteNodeiSucc(root->right, value);
    }

    return root;
}

int main(){
    int n, value, choice;
    node* root=NULL;

    printf("1. Insert \n2. Display \n3. Delete \n4. Exit \n");

    while (true){
        printf("\nChoice: ");
        scanf("%d", &choice);

        if(choice==1){
            printf("Element: ");
            scanf("%d", &value);
            root=createTree(root, value);
        }

        else if(choice==2){
            printf("\nIn-order: ");
            inorder(root);
            printf("\n");
        }

        else if(choice==3){
            printf("Element to Delete: ");
            scanf("%d", &value);
            root=deleteNodeiPre(root, value);
        }

        else if(choice==4){
            break;
        }

        else printf("\nSelect valid option!!\n");
    }
}