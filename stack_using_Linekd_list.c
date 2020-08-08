#include<stdio.h>
#include<stdlib.h>

void displayStack();
void push(int);
void pop();

struct node{

int data;
struct node *next;
};
struct node *top;

int main(){
    int data,choice;
    printf("STACK USING LINKED LIST\n\n");
    while(1){
        printf("1. DISPLAY STACK\n2. PUSH\n3. POP\n0. EXIT\n\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
        case 1:
          displayStack();
          break;
        case 2:
            printf("\n\nEnter the data value: ");
            scanf("%d",&data);
            push(data);
            break;
        case 3:
            pop();
            break;
        case 0:
	    free(top); //garbage collection
            exit(0);
            break;
        default:
            printf("\nWARNING!! WRONG INPUT\n\n");
        };

    }
}

void push(int data){
    struct node *newNode;
    newNode = (struct node *) malloc(sizeof(struct node));

    if(newNode==NULL){
        printf("ERROR: Memory Overflow, cannot insert element\n\n");
    }
    else{
        if(top == NULL){
            printf("STACK EMPTY: This is the first element.\n\n");
            newNode->data = data;
            newNode->next = NULL;
            top = newNode;
        }
        else{
            newNode->data = data;
            newNode->next = top;
            top = newNode;
        }
        printf("ITEM PUSHED...\n\n");
    }
}

void pop(){
    int confirm;
    struct node *temp;
    temp = top;
    if(temp == NULL){
            printf("ERROR: STACK EMPTY\n\n");
	    return; //failsafe
    }
    else{
    printf("Item to be deleted: %d press 1 to confirm.\n\n", temp->data);
    scanf("%d",&confirm);
    if(confirm == 1){
        top = top->next;
        printf("DATA DELETED\n\n");
        free(temp);
    }
    else{
        printf("OPERATION CANCELLED...\n\n");
	return; //failsafe
    }
}
}

void displayStack(){
    int i=0;
    struct node *temp;
    temp = top;

    if(temp == NULL){
        printf("\n\nERROR: Empty Stack\n\n");
    }
    else{
    while(temp != NULL){
            ++i;
            if(i==1){
                printf("%d <-- TOP\n", temp->data);
            }
            else{

            printf("%d\n", temp->data);
            }
            temp = temp->next;
    }
    }
free(temp); //garbage collection
}