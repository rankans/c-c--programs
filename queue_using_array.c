#include<stdio.h>
#include<stdlib.h>
#define MAX 20

void display();
void insert();
void del();

 int data[MAX];
 int front = -1;
 int rear = -1;

int main(){
    int choice,dta;
    while(1){
    printf("Select option\n\n");
    printf("1. DISPLAY queue\n2. INSERT into queue\n3. DELETE from queue\n0.EXIT\n");
    scanf("%d",&choice);
    switch(choice){
case 1:
    display();
    break;
case 2:
    printf("Enter data: ");
    scanf("%d", &dta);
    insert(dta);
    break;
case 3:
    del();
    break;
case 0:
    exit(0);
    break;
    };
}
return 0;
}

void insert(int data_add){

if(rear == MAX-1){
    printf("ERROR: OVERFLOW, cannot insert element\n");
    return; //failsafe
}
else{
    if(front == -1 && rear == -1){
        front = 0;
        rear = 0;
    }
    else{
        ++rear;
    }
    data[rear] = data_add;
    printf("\nINSERTION SUCCESSFUL\n");
}
}

void del(){
    int confirm;
    if (front == -1 && rear == -1){
        printf("ERROR: UNDERFLOW, no data to delete\n");
        return;
    }

    else{
            if(front == rear){
                printf("DATA TO DELETE %d. press 1 to confirm. \n",data[front]);
        scanf("%d",&confirm);
        if(confirm == 1){
            front = rear = -1;
        }
        else{
            printf("OPERATION CANCELLED\n\n");
            return;
        }
            }
            else{

        printf("DATA TO DELETE %d. press 1 to confirm. \n",data[front]);
        scanf("%d",&confirm);
        if(confirm == 1){
            ++front;
        }
        else{
            printf("OPERATION CANCELLED\n\n");
            return;
        }

    }
}
}

void display(){
    int i;
    if(rear == -1){
        printf("ERROR: EMPTY QUEUE\n");
    }
    else{
    printf("data in the queue\n");
    for(i=front;i<=rear;++i){
            if(i == front && i == rear){
                printf("%d <--- FRONT <---REAR\n", data[i]);
            }
            else if(i == front){
                printf("%d <--- FRONT\n", data[i]);
            }
            else if(i == rear){
                printf("%d <--- REAR\n", data[i]);
            }
            else{
        printf("%d\n",data[i]);
            }
    }
}
}