//---------------------------QUEUE USING LINKED LIST------------------------------------

#include<stdio.h>
#include<stdlib.h>

void insert(int);
void del();
void display();

struct node{
int data;
struct node *next;
};

struct node *front = NULL, *rear = NULL;

int main(){
    int choice,data;
    printf("QUEUE USING LINKED LIST\n\n");

    while(1){
    printf("ENTER YOUR CHOICE:\n\n");
    printf("1. DISPLAY\n2. INSERT\n3. DELETE\n0. EXIT\n\n");
    scanf("%d",&choice);
    switch(choice){
case 1:
    display();
    break;
case 2:
    printf("Enter the data: ");
    scanf("%d", &data);
    insert(data);
    break;
case 3:
    del();
    break;
case 0:
    exit(0);
    break;
default:
    printf("Wrong input\n\n");
    break;
    };
    }
    free(front);
    free(rear);
return 0;
}

void insert(int data){
    struct node *newNode = (struct node *) malloc(sizeof(struct node));

    if(newNode == NULL){
        printf("ERROR: MEMORY OVEFLOW\n\n");
        return;
    }
    else{
        if(front == NULL){
            printf("This is the first node...\n\n");
            newNode->data = data;
            front = newNode;
            rear = newNode;
            rear->next = NULL;
        }
        else{
            newNode->data = data;
            rear->next = newNode;
            rear = newNode;
            rear->next = NULL;
        }
        printf("INSERTION SUCCESSFUL...\n\n");
    }

}

void del(){
    int confirm;
    struct node *todel;
    if(front == NULL){
        printf("ERROR: MEMORY UNDERFLOW, QUEUE EMPTY\n\n");
        return;
    }
    else{
        todel = front;
        printf("DATA to be deleted: %d press 1 to confirm\n\n", todel->data);
        scanf("%d", &confirm);
        if(confirm == 1){
        front = front->next;
    }
        else{
            printf("OPERATION CANCELLED\n\n");
            return;
        }
    }
    free(todel); //garbage collection
}

void display(){
    struct node *temp;
        temp = front;
    if(temp == NULL){
        printf("ERROR: MEMORY UNDERFLOW, QUEUE EMPTY\n\n");
        return;
    }
    else{
    printf("Data in queue...\n\n");
    while(temp != NULL){
            if(temp == front){
        printf("%d <--- FRONT\n", temp->data);
        }
        else if(temp == rear){
            printf("%d <---REAR\n", temp->data);
        }
        else{
            printf("%d\n", temp->data);
        }
        temp = temp->next;
    }
    printf("END OF QUEUE\n\n");
}
free(temp); //garbage collection
}
