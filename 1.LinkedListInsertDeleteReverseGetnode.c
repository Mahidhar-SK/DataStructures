#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};


void Insert_begin(int x, struct node** head);
void Insert_end(int x, struct node** head);
void Insert_nth(int x,struct node** head, int pos);
void Delete_nth(int pos, struct node** head);
void Reverse(struct node** head);
void GetNode(struct node** head, int pos);
void Print(struct node* head);


int main(){
    struct node* head = NULL;
    int i,x,be,d,g,exit_flag=0;
    while(!exit_flag){
        
        printf("1.Insert at Beginning\n2.Insert at End\n3.Insert at nth position\n4.Delete nth node\n5.Reverse List\n6.Get node value\n7.Exit\n");
        scanf("%d",&be);
        switch(be){
            case 1:printf("Enter a number\n");
                   scanf("%d",&x);
                   Insert_begin(x, &head);break;
            case 2:printf("Enter a number\n");
                   scanf("%d",&x);
                   Insert_end(x, &head);break;
            case 3:printf("Enter a number\n");
                   scanf("%d",&x);
                   printf("Enter position\n");
                   int num;
                   scanf("%d",&num);
                   Insert_nth(x, &head, num);
                   break;
            case 4:printf("Enter position of the node\n");
                   scanf("%d",&d);
                   Delete_nth(d, &head);
                   break;
            case 5:Reverse(&head);break;
            case 6:printf("Enter Position\n");
            scanf("%d",&g);
            GetNode(&head,g);
            break;
            case 7:exit_flag = 1;break;
            
            default: printf("invalid choice\n");
        }
        Print(head);
    }

}

void Insert_begin(int x, struct node** head){
    struct node* temp = (struct node*)(malloc(sizeof(struct node)));
    temp->data = x;
    temp->next = *head;
    *head = temp;
}

void Print(struct node* head){
    printf("List is:\n");
    while(head!=NULL){
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\n");
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

void Insert_nth(int x, struct node** head, int pos){
    struct node* temp1 = (struct node*)malloc(sizeof(struct node));
    temp1->data = x;
    temp1->next = NULL;
    if(*head==NULL){
        *head=temp1;
    }
    if(pos == 0){
        temp1->next = *head;
        *head= temp1;
    }
    else{
        struct node* temp2 = (struct node*)malloc(sizeof(struct node));
        temp2=*head;
        int tra=0;
        int flag = 0;
        while(temp2!=NULL){
            if(tra == pos - 1){
                temp1->next = temp2->next;
                temp2->next = temp1;
                flag = 1;
                break;
            }
            else{
                temp2=temp2->next;
            }
            tra++;
        }
        if(flag == 0)printf("Invalid position\n");
    }
}


void Delete_nth(int pos, struct node** head){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp = *head;

    if(pos == 0){
        *head = temp->next;
        free(temp);
    }
    else{
        int tra = 0, flag = 0;
        while(temp->next!=NULL){
            if(tra == pos-1){
                struct node* temp1 = (struct node*)malloc(sizeof(struct node));
                temp1 = temp->next;
                temp->next = temp1->next;
                free(temp1);
                flag = 1;
            }
            else{
                temp = temp->next;
            }
            tra++;
        }
        if(!flag) printf("invalid position\n");
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


void GetNode(struct node** head, int pos){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp = *head;
    int count = 0, val = 0;
    while(temp!=NULL){
        if(count == pos){
            val = temp->data;
            printf("%d\n",val);
            break;
        }
        else{
            temp = temp->next;
        }
        count++;

    }

}
