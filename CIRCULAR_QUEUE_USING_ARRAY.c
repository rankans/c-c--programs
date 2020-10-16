
//----------------circular queue using array--------------------------------------------------------------------------

#include<stdio.h>
#include<stdlib.h>
#define MAX 50

void insert(int);
void display();
void del();

int dat[MAX];
int front = -1, rear = -1;

int main(){
    int choice=0,data;
    printf("Circular queue using array...\n\n");
while(1){
    printf("Enter your option: \n");
    printf("1. INSERT\n2. DISPLAY\n3. DELETE\n0. EXIT\n");
    scanf("%d",&choice);
    switch(choice){
case 1:
    printf("Enter the data: ");
    scanf("%d",&data);
    insert(data);
    break;
case 2:
    display();
    break;
case 3:
    del();
    break;
case 0:
    exit(0);
default:
    printf("wrong input...\n\n");
    }
    };
return 0;
}

void insert(int data){
    if(rear == MAX-1 || front == rear+1){
        printf("MEMORY OVERFLOW: QUEUE FULL\n\n");
    }
    else if(front == -1){
        front = 0;
        rear = 0;
    }
    else{
        if(rear == MAX-1){
            rear = 0;
        }
        else{
            rear = rear + 1;
        }
    }
    dat[rear] = data;
    printf("INSERTION SUCCESSFUL...\n\n");
}

void del(){
     if(front == -1){
        printf("ERROR: UNDERFLOW, QUEUE EMPTY\n\n");
        return;
     }
     else{
        if(front == rear){
            front = rear = -1;
        }
        else if(front == MAX-1){
            front = 0;
        }
        else{
            ++front;
        }
     }

}

void display()
{
    int front_pos = front,rear_pos = rear;
    if(front == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements :\n");
    if( front_pos <= rear_pos )
        while(front_pos <= rear_pos)
        {
            printf("%d ",dat[front_pos]);
            front_pos++;
        }
    else
    {
        while(front_pos <= MAX-1)
        {
            printf("%d ",dat[front_pos]);
            front_pos++;
        }
        front_pos = 0;
        while(front_pos <= rear_pos)
        {
            printf("%d ",dat[front_pos]);
            front_pos++;
        }
    }
    printf("\n");
}
