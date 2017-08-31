#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

void Print(struct node* p);
void PrintRev(struct node* p);
void Insert_end(int x, struct node** head);

void Print(struct node* p){
    if(p==NULL)return;
    printf("%d ",p->data);
    Print(p->next);

}
void PrintRev(struct node* p){
    if(p==NULL){
        return;
    }
    PrintRev(p->next);
    printf("%d ",p->data);
    
}

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

void main(){
    struct node* head = NULL;
    Insert_end(1, &head);
    Insert_end(2, &head);
    Insert_end(3, &head);
    Insert_end(4, &head);
    Insert_end(5, &head);
    Insert_end(6, &head);
    Insert_end(7, &head);
    Print(head);
    printf("\n");    
    PrintRev(head);
}