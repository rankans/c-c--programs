#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    int data;
    struct node *next;
}*header,*tempii;

struct node *createNode(int data);
void insert_end(int);
void insert_beg(int data);
void insert_pos(int data, int pos);
void del_beg();
void del_end();
void del_pos(int);
void del_ele(int);
void DELETE_WHOLE();
void display();
void process();

int main(){
    process();
    return 0;
}


void process(){
        int choice, data, pos;
        while(1){
            printf("Enter your choice\n");
            printf("1. INSERT ELEMENT\n2. INSERT ELEMENT AT BEGINNING\n3. INSERT ELEMENT AT THE END\n4. INSERT ELEMENT AT A SPECIFIC POSITION\n");
            printf("5. DELETE AN ELEMENT FROM BEGINNING\n6. DELETE THE LAST ELEMENT\n7. DELETE AN ELEMENT BY POSITION\n8. DELETE AN ELEMENT BY VALUE");
            printf("\n9. DISPLAY LIST\n1010. DELETE THE WHOLE LIST--> CAUTION: USE WITH CARE\n0. EXIT\n\nInput: ");
            scanf("%d", &choice);
            switch(choice){
        case 1:
            printf("Enter the data: ");
            scanf("%d", &data);
            insert_end(data);
            break;
        case 2:
            printf("Enter the data: ");
            scanf("%d", &data);
            insert_beg(data);
            break;
        case 3:
            printf("Enter the data: ");
            scanf("%d", &data);
            insert_end(data);
            break;
        case 4:
            printf("Enter the data: ");
            scanf("%d", &data);
            printf("Enter the position: ");
            scanf("%d", &pos);
            insert_pos(data, pos);
            break;
        case 5:
            del_beg();
            break;
        case 6:
            del_end();
            break;
        case 7:
            printf("Enter the position: ");
            scanf("%d", &pos);
            del_pos(pos);
            break;
        case 8:
            printf("Enter the element to delete: ");
            scanf("%d", &data);
            del_ele(data);
            break;
        case 9:
            display();
            break;
        case 1010:
            DELETE_WHOLE();
            break;
        case 0:
            exit(0);
            break;
        default:
            printf("PLEASE ENTER A valid choice...\n\n");

            }
    }
}

struct node *createNode(int data){

    struct node *newNode;
    newNode = (struct node *) malloc(sizeof(struct node));

    if(newNode == NULL){
        printf("ERROR: MEMORY OVERFLOW!\n\n");
    }

    else{
        newNode->data = data;
        newNode->next = NULL;
    }
    return newNode;
}

void insert_end(int data){
    struct node *newNode;
    newNode = createNode(data);

    if(header == NULL){
        header = newNode;
        tempii = header;
    }

    else{
        tempii->next = newNode;
        tempii = tempii->next;
    }
}

void insert_beg(int data){
    struct node *newNode;
    newNode = (struct node *) malloc(sizeof(struct node));
    if(newNode == NULL){
        printf("ERROR: MEMORY OVERFLOW!\n\n");
        return;
    }

    else{
        newNode->data = data;
        newNode->next = header;
        header = newNode;
    }
}

void insert_pos(int data, int pos){
    struct node *temp, *newNode;
    int i;
    temp = header;
    newNode = (struct node *) malloc(sizeof(struct node));

    if(newNode == NULL){
        printf("ERROR: MEMORY OVERFLOW!\n\n");
    }
    else{
        for(i=0; i<pos-2; ++i){
        temp = temp->next;
        if(temp == NULL){
            printf("ERROR: Invalid Position\n\n");
        }
        }
        newNode->data = data;
        newNode->next = temp->next;
        temp->next = newNode;
    }

}

void del_beg(){
    struct node *temp;
    int confirm;
    temp = header;
    printf("You are about to delete %d, press 1 to confirm...", temp->data);
    scanf("%d", &confirm);
    if(confirm == 1){
    header = header->next;
    free(temp);
    }
    else{
        return;
    }
}

void del_end(){
    struct node *temp, *tempo;
    int confirm;
    temp = header;
    while(temp->next != NULL){
        tempo = temp;
        temp = temp->next;
    }
    printf("Your are about to delete %d, Press 1 to confirm", temp->data);
    scanf("%d", &confirm);
    if(confirm == 1){
        free(temp);
        tempo->next = NULL;
    }
    else{
        return;
    }
}

void del_pos(int pos){
    struct node *temp, *tempo;
    int i, confirm;
    temp=header;
    for(i=0;i<pos-1;++i){
            tempo = temp;
        temp = temp->next;
    }
    printf("You are about to delete %d, Press 1 to confirm...", temp->data);
    scanf("%d", &confirm);
    if(confirm == 1){
        if(temp == header){
            header = header->next;
            free(temp);
        }
        else if(temp->next == NULL){
            tempo->next = NULL;
            free(temp);
        }
        else{
            tempo->next = temp->next;
            free(temp);
        }
    }

}

void del_ele(int ele){
    struct node *temp, *tempo;
    temp = header;
    tempo = temp;
    while(temp != NULL){
            if(temp->data == ele){
                if(temp == header){
                        printf("Deleting: %d\n", temp->data);
                    header = header->next;
                    free(temp);
                }
                else if(temp->next == NULL){
                        printf("Deleting: %d\n", temp->data);
                    tempo->next = NULL;
                    free(temp);
                }

                else{
                    printf("Deleting: %d\n", temp->data);
                    tempo->next = temp->next;
                    free(temp);
                }
                return;
            }

        tempo = temp;
        temp = temp->next;
    }

}

void DELETE_WHOLE(){
    char confirm_uno[4];
    int confirm_dos;
    struct node *temp;
    temp = header;
    printf("\n\nCAUTION: YOU ARE ABOUT TO DELETE THE WHOLE LIST!!, TYPE 'YES/yes' TO CONTINUE...");
    scanf("%s", confirm_uno);
    if(!strcmpi("yes", confirm_uno)){
        printf("\n\nAre you sure?, Press 1 to confirm....");
        scanf("%d", &confirm_dos);
        if(confirm_dos == 1){
            printf("\n\nDeleting elements...\n\n");
            while(temp != NULL){
                printf("Deleting: %d\n", temp->data);
                temp = temp->next;
            }
            free(temp);
            free(header);
            header = NULL;
            temp = NULL;
            system("cls");
            printf("\n\nLIST CLEAR.\nRestarting menu...\n\n");
        }
        else{
            return;
        }
    }
    else{
        return;
    }
}

void display(){
    struct node *temp;
    temp = header;
    int i = 0;
    if(header == NULL){
        printf("ERROR: MEMORY UNDEFLOW, List is Empty!!!\n\n");
    }
    else{
printf("\n\n\n");
    while(temp != NULL){
            ++i;
            if(temp == header){
                printf("%d <----- HEADER----%d\n", temp->data, i);
            }
            else{
                printf("%d----%d\n", temp->data, i);
            }
        temp = temp->next;
    }
    free(temp);
    printf("\n\n\n");
}
}

/*void merge_sort(){
}*/
