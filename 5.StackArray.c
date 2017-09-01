//Stack: Array Implementation

#include<stdio.h>
#define MAX_SIZE 100
int A[MAX_SIZE];
int top = -1;

void Push(int x){
    if(top == MAX_SIZE-1){
        printf("Stack overflow\n");
        return;
    }
    A[++top] = x;
}

void Pop(){
    if(top == -1){
        printf("Stack Empty\n");
        return;
    }
    top--;
}

int Top(){
    return A[top];
}

void Print(){
    int i;
    printf("Stack : ");
    for(i=0;i<=top;i++)
        printf("%d ",A[i]);
    printf("\n");
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
        Print();
        if(eflag)
            break;
    }
}
