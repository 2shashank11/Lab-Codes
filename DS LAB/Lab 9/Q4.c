#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} node;

void insert(node **head, int element){
    node *p=*head;

    if(*head==NULL){
        *head=(node*)(malloc(sizeof(node)));
        (*head)->data=element;
        (*head)->next=NULL;
        return;
    }

    while(p->next!=NULL){
        p=p->next;
    }
    node *temp=(node*)(malloc(sizeof(node)));
    temp->data=element;
    temp->next=NULL;
    p->next=temp;
}

void deleteDuplicate(node **head){
    node *current=*head;

    if(current->next==NULL){
        return;
    }

    while(current!=NULL){
        node *next=current->next;
        while(next!=NULL && current->data==next->data){
            node *temp=next;
            next=next->next;
            free(temp);
        }
        current->next=next;
        current=current->next;
    }
}

void display(node **head){
    node *p=*head;
    printf("\n");
    do
    {
        printf("%d ", p->data);
        p=p->next;
    } while (p!=NULL);
    
}

int main(){
    node *head=NULL;
    int n;
    printf("Enter number of elements in list: ");
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        printf("Element %d: ", (i+1));
        int element;
        scanf("%d", &element);
        insert(&head, element);
    }

    printf("\nDeleting Duplicates...\n");
    deleteDuplicate(&head);
    printf("\nUpdated List: ");
    display(&head);
    free(head);
}
