//Stack: Linked List Implementation

#include<stdio.h>
#include<stdlib.h>


struct node{
    int data;
    struct node* next;
};

struct node* top = NULL;

void Push(int x){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = top;
    top = temp;
}

void Pop(){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    if(top == NULL){
        printf("Stack empty\n");
        return;
    }
    temp = top;
    top = top->next;
    free(temp);
}

void Print(struct node* p){
    if(p == NULL)return;
    Print(p->next);
    printf("%d ",p->data);


}

int main(){
    int p,x,eflag = 0;
    while(1){

    
        printf("1.Push\n2.Pop\n");
        scanf("%d",&p);
        switch(p){
            case 1:printf("Enter number\n");
            scanf("%d",&x);
            Push(x);
            break;
            case 2:Pop();
            break;
            default:eflag = 1;
        }
        printf("Stack:\t");
        Print(top);
        printf("\n");
        if(eflag)
            break;
    }
}
