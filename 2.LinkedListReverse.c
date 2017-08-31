#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};


void Insert_end(int x, struct node** head);
void Print(struct node* head);
void Reverse(struct node** head);
void ReverseRec(struct node** head, struct node* p);


void Insert_end(int x, struct node** head){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = NULL;
    if(*head==NULL){
        *head = temp;
    }
    else{
        struct node* tra = (struct node*)malloc(sizeof(struct node));
        tra = *head;
        while(tra->next!=NULL){
            tra=tra->next;
        }
        tra->next = temp;
    }
    
}


void Reverse(struct node** head){
    struct node* current = (struct node*)malloc(sizeof(struct node));
    struct node* prev = (struct node*)malloc(sizeof(struct node));
    struct node* next = (struct node*)malloc(sizeof(struct node));
    current = *head;
    prev = NULL;
    while(current!=NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

void ReverseRec(struct node** head, struct node* p){ //Things are simpler if head is global
    if(p->next==NULL){
        *head = p;
        return;
    }
    ReverseRec(head, p->next);
    p->next->next = p;
    p->next = NULL;

}

void Print(struct node* head){
    printf("List is:\n");
    while(head!=NULL){
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\n");
}

void main(){

    struct node* head = (struct node*)malloc(sizeof(struct node));
    head = NULL;
    int ch = 0,x,flag = 0;
    while(1){
        printf("1.Insert node\n2.Reverse List\n3.Reverse List using recursion\n4.Exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:printf("Enter Number\n");
            scanf("%d",&x);
            Insert_end(x, &head);
            break;
            case 2:Reverse(&head);break;
            case 3:ReverseRec(&head, head);break;
            default:flag = 1;
        }
        Print(head);
        if(flag) break;
}}
