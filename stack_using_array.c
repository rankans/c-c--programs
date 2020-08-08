#include<stdio.h>
#include<stdlib.h>
#define MAX 20
void push(int[],int);
void pop(int []);
void delStack();
void displayStack(int []);

int stack[MAX],TOP;

int main(){

    int choice,data;
    TOP = -1;
    while(1){
    printf("\n\nEnter your choice:\n\n");
    printf("1.Display Stack.\n\n2.PUSH an element\n\n3.POP an element\n\n4.DELETE THE STACK\n\n0.EXIT\n\n");
    scanf("%d",&choice);
    switch(choice){
    case 1:
        displayStack(stack);
        break;
    case 2:
        printf("\nEnter the data: ");
        scanf("%d",&data);
        push(stack,data);
        break;
    case 3:
        pop(stack);
        break;
    case 4:
        delStack();
        break;
    case 0:
        exit(0);
        break;
    default:
        printf("Invalid choice\n");
    };
    }
}

void push(int stack[],int data){
if(TOP == MAX-1){
    printf("ERROR: Stack Full");
    return; //failsafe
}
else{
    ++TOP;
    stack[TOP]=data;
    printf("Insertion successful...\n");
}
    //printf("\n\n\nTOP= %d\n\n\n\n",TOP); //debug note

}

void pop(int stack[]){
 int itemDeleted, confirm=0;
    //printf("\n\n\nTOP= %d\n\n\n\n",TOP); //debug note

 if(TOP == -1){
    printf("ERROR: Stack Empty");
    return; //failsafe
 }
 else{
    itemDeleted = stack[TOP];
    printf("Item to be deleted : %d press 1 to confirm ", itemDeleted);
    scanf("%d",&confirm);
    if(confirm == 1){
    --TOP;
    printf("DELETION SUCCESSFUL...\n");
    }
    else{
        printf("OPERATION CANCELLED...\n");
    }
 }
}

void displayStack(int stack[]){
    int temp = TOP;
    //printf("\n\n\nTOP= %d\n\n\n\n",TOP);  //debug note
    int i=0;
if(TOP == -1){
    printf("\n\nERROR: Stack Empty\n\n");
    return; //failsafe

}
else{
    while(temp > -1){
            if(temp == TOP){
        printf("%d<--TOP\n", stack[temp]);
            }
        else{
                printf("%d\n", stack[temp]);
        }
    --temp;
    }
    printf("END OF STACK");
}
}

void delStack(){
    int confirm=0;
if(TOP == -1){
    printf("ERROR: Stack Empty");
    return //failsafe
}
else{
        printf("YOUR ARE ABOUT TO DELETE THE WHOLE STACK ONCE DELETED\nTHE DATA CANNOT BE RETRIEVED. PRESS 1 TO CONFIRM.  \n");
        scanf("%d",&confirm);
    if(confirm == 1){
            printf("DELETING STACK..\n");
    while(TOP > -1){
            --TOP;
    }
    printf("Stack deleted... Value of TOP = %d\n",TOP);
    }
    else{
        printf("\nOPERATION CANCELLED");
    }
}
}