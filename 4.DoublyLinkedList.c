#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
    struct node* prev;
};

struct node* head;

void Insert_begin(int x){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->prev = NULL;
    temp->next = NULL;
    if(head == NULL){
        head = temp;
        return;
    }
    head->prev = temp;
    temp->next = head;
    head = temp;
}

void Print(){
    printf("List is:\n");
    while(head!=NULL){
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\n");
}

void main(){
    head = NULL;
    Insert_begin(1);
    Insert_begin(2);
    Insert_begin(3);
    Insert_begin(4);
    Insert_begin(5);
    Print();



}