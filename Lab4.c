#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int front=-1,rear=-1;
typedef struct process{
    int pr;
}job;

job pjob[MAX];

void insert(){
    int pr;
    if(rear==MAX-1){
        printf("Queue is Full");
    }
    else{
        printf("Enter the Priority\n");
        scanf("%d",&pr);
        if(rear==-1){
            front++;
            rear++;
        }
        else{
            rear++;
        }
        pjob[rear].pr=pr;
    }
}
void delete(){
    int i, pmax=0;int pr;
    if(rear==-1){
        printf("Queue is Empty");
    }
    else if(front == rear){
        rear=-1;
        front=-1;
    }
    else{
        for(int i=front;i<rear;i++){
            if(pjob[i].pr>pmax){
                pmax=pjob[i].pr;
                pr=i;
            }
        }
        for(int i=pr;i<rear;i++){
            pjob[i].pr=pjob[i+1].pr;
        }
    }
    rear--;
}
void display(){
    if(rear==-1){
        printf("Queue is Empty\n");
    }
    else{
        for(int i=front;i<rear;i++){
            printf("%d",pjob[i]);
        }
    }
}
void main(){
    int ch;
    while(1){
        printf("Enter the choice \n");
        printf("1.Insert\t2.Delete\t3.Display\t4.Exit\t\n");
        scanf("%d",&ch);
        switch(ch){
            case 1: insert();
            break;
            case 2: delete();
            break;
            case 3: display();
            break;
            case 4: exit(0);
            default:printf("Invalid Choice\n");
            
        }
    }
}
