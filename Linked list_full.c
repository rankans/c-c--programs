#include<stdio.h>
#include<stdlib.h>

/*
Name:- Rankan Sen
Class - 3BTCS B
Reg NO. - 1960375
*/

struct node {                 //Node declaration
    int data; 		          //Data part
    struct node *next;        //Address part
}*header;

void newNode();
void insertBeg();
void insertEnd();
void insertMiddle();
void delStart();
void delEnd();
void delMid();
void traverseList();
void DELETEWHOLE();


//----------------------------------------------------------------------Main----------------------------------------------
int main(){

int choice, CONFIRM;
printf("Reg No. - 1960375\nName :- Rankan Sen\nClass :- 3BTCS_B\n\n");
abc:
printf("\n\nPlease enter your choice :\n\n");
printf("1. Create a new Linear Linked list\n2. Insert a new element at the beginning of the list\n3. Enter a new element at the end of the list\n4. Enter a new element at the middle of the list\n");
printf("5. Delete an element from the beginning of the list\n6. Delete an element from the end of the list\n7. Delete an element from the middle of the list\n8. Traverse the list\n\n\n100. DELETE THE WHOLE LIST\n\n");
printf("PRESS \'0\' TO EXIT\n\n\n");
scanf("%d", &choice);

switch(choice){

case 1:
//new Linked List
newNode();
goto abc;
break;

case 2:
//insert at beginning
insertBeg();
goto abc;
break;

case 3:
//insert at End
insertEnd();
goto abc;
break;

case 4:
//Insert At middle
insertMiddle();
goto abc;
break;

case 5:
//deletion at start
delStart();
goto abc;
break;

case 6:
//deletion at end
delEnd();
goto abc;
break;

case 7:
//deletion at middle
delMid();
goto abc;
break;

case 8:
//traverse the list
traverseList();
goto abc;
break;

case 100:
//CAUTION: Delete complete list
printf("ARE YOU SURE? ONCE DELETED THE LIST CANNOT BE RESTORED!! PRESS 101 TO CONFIRM 9 TO GO BACK TO MAIN MENU: \n");
scanf("%d", &CONFIRM);
if(CONFIRM == 101){
DELETEWHOLE();
}
else{
goto abc;
}
goto abc;
break;

case 0:
//exit
exit(0);
break;
}

return 0;
}

//----------------------------------------------------------------End main------------------------------------------------------------------

//----------------------------------new node part ----------------------------------------------------------------------------------------
void newNode(){
 int n, data, i;
    printf("Enter the total number of nodes: ");
    scanf("%d", &n);
     struct node *newNode, *temp;

    /* A node is created by allocating memory to a structure */
    newNode = (struct node *)malloc(sizeof(struct node));

    /* If unable to allocate memory for head node */
    if(newNode == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        printf("Enter the data of node 1: ");
        scanf("%d", &data);

        newNode->data = data; //Links the data field with data
        newNode->next = NULL; //Links the address field to NULL
        header = newNode;     //Header points to the first node
        temp = newNode;       //First node is the current node
for(i=2; i<= n; i++)
    {
      /* A newNode is created by allocating memory */
      newNode = (struct node *)malloc(sizeof(struct node));

      if(newNode == NULL)
      {
         printf("Unable to allocate memory.");
         break;
      }
      else
      {
         printf("Enter the data of node %d: ", i);
         scanf("%d", &data);

         newNode->data = data; //Links the data field of newNode with data
         newNode->next = NULL; //Links the address field of newNode with NULL

         temp->next = newNode; //Links previous node i.e. temp to the newNode
         temp = temp->next;
       }
     }
     printf("New node created successfully\n\n");
   }
}

//--------------------------------------------------------------- End new node-------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------insert at beginning--------------------------------------------------------------------------

void insertBeg(){
int data;
    printf("\n ENTER THE  Data in the list \n");
    scanf("%d", &data);

    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));

    if(newNode == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        newNode->data = data; 	//Links the data part
        newNode->next = header; 	//Links the address part
         header = newNode; 	//Makes newNode as first node
         printf("DATA INSERTED SUCCESSFULLY\n");
    }
}

//---------------------------------------------------------insert at beginning done--------------------------------------------------------------------------------------------

//---------------------------------------------------------------insert at End-------------------------------------------------------------------------------------------------

void insertEnd(){

int data1;
    printf("\n ENTER THE  Data in the list \n");
    scanf("%d", &data1);

struct node *newNode,*temp1;
    newNode = (struct node*)malloc(sizeof(struct node));

    if(newNode == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        newNode->data = data1; 	//Links the data part
        newNode->next = NULL; 	//Links the address part
         temp1 = header;
         {

		 while(temp1->next!=NULL)
		 {
		 temp1=temp1->next;
     	}
		 temp1->next=newNode;	//Makes newNode as first node
         printf("DATA INSERTED SUCCESSFULLY\n");
     }
    }
}

//----------------------------------------------------------insert at End done-------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------insert at middle---------------------------------------------------------------------------------------

void insertMiddle(){
 int data1, position,i;
 printf("\n ENTER THE  Data in the list \n");
    scanf("%d", &data1);
    printf("\n ENTER THE  Position in the list \n");
    scanf("%d", &position);

	struct node *newNode, *temp2;
	newNode = (struct node *)malloc(sizeof(struct node));
	if(newNode == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        newNode->data = data1; 	//Links the data part
        newNode->next = NULL;

       temp2=header;
       for(i=2;i<=position-1;i++)
       {
       	temp2=temp2->next;
       	if(temp2==NULL)
       	break;
	   }
	   if(temp2!=NULL)
	   {
	   	newNode->next=temp2->next;
	   	temp2->next=newNode;
	   	printf("data inserted sucessfully");
	   }
	   else
	   {
	   printf("UNABLE TO INSERT DATA AT THE GIVEN POSITION\n");
	   }
     }

}

//------------------------------------------------insertion at middle done--------------------------------------------------------------------------------------

//------------------------------------------------------deletion at the start-------------------------------------------------------------------------------------

void delStart(){

 struct node *toDelete;

    if(header == NULL)
    {
        printf("List is already empty.");
    }
    else
    {
        toDelete = header;
        header = header->next;

        printf("\nData deleted = %d\n", toDelete->data);

        /* Clears the memory occupied by first node*/
        free(toDelete);

        printf("SUCCESSFULLY DELETED FIRST NODE FROM LIST\n");
    }
}
//-------------------------------------------------deletion at the start finish-----------------------------------------------------------------------------------

//-----------------------------------------------------deletion at the end----------------------------------------------------------------------------------------

void delEnd(){

struct node *toDelete, *secondLastNode;
	toDelete=header;
	secondLastNode=header;
	while(toDelete->next!=NULL)
	{
	secondLastNode= toDelete;
	toDelete = toDelete->next;
	}
	if(toDelete==header) {header=NULL;
	}
	else
	{
		/*Disconnects the link of second last node with last node */
		secondLastNode->next=NULL;
	}
	/*delete last node*/
	free(toDelete);
}

//----------------------------------------------------------------------------deletion at the end finish-----------------------------------------------------------------

//------------------------------------------------------------------deletion at the middle-------------------------------------------------------------------------------

void delMid(){
int i,position;
printf("Enter the position: ");
    scanf("%d", &position);

	struct node *toDelete, *prevNode;
	if(header==NULL)
	{
	printf("List is already empty");
	}
		else
		{
			toDelete = header;
			prevNode = header;

			for(i=2;i<=position;i++)
			{
			prevNode=toDelete;
			toDelete=toDelete->next;

			if(toDelete==NULL)
			break;
		   }
			if(toDelete!=NULL)
			{
			if(toDelete==header)
			header=header->next;
			prevNode->next=toDelete->next;
			toDelete->next=NULL;
			free(toDelete);
			printf("Successfully  Deleted From Middle of List");
			}
			else
			{
			printf("Invalid Position Unable to delete");
			}
			}
}

//-----------------------------------------------------deletion at the middle Finish--------------------------------------------------------------------------------------

//------------------------------------------------------------transverse list---------------------------------------------------------------------------------------------

void traverseList()
{
  struct node *temp;
  int i=0;

  /* If the list is empty i.e. head = NULL */
  if(header == NULL)
  {
    printf("List is empty.");
  }
  else
  {
    temp = header;
    while(temp != NULL)
    {
     ++i;
     printf("Data %d = %d\n", i, temp->data); //Prints the data of current node
     temp = temp->next; 	//Advances the position of current node
    }
  }
}

//-----------------------------------------------------------------------tranverse list Finish------------------------------------------------------------------------------


//-------------------------------------------------------------------------DELETE WHOLE LIST---------------------------------------------------------------------------------

void DELETEWHOLE(){

struct node *toDelete;

    if(header == NULL)
    {
        printf("List is already empty.");
    }
    else
    {
        while(header != NULL)
        {
        toDelete = header;
        header = header->next;

        printf("\nData deleted = %d\n", toDelete->data);

        /* Clears the memory occupied by first node*/
        free(toDelete);

        printf("SUCCESSFULLY DELETED THE LIST\n");
    }
    }

}

//---------------------------------------------------------------------------DELETION COMPLETE-------------------------------------------------------------------------------
