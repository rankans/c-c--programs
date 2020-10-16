//BINARY SEARCH TREE

#include<stdio.h>
#include<stdlib.h>

struct node *insert(struct node *root, int data);
struct node *create(int data);
void traverse(struct node *root);
struct node *del(struct node *root, int key);
struct node *minValueNode(struct node *node);


struct node{
    int data;
    struct node *left, *right;
}*root = NULL;

int main(){
int choice,data,key;

while(1){
    printf("select your choice: \n");
    printf("1. INSERT\n2. TRAVERSE\n3. DELETE AN ELEMENT\n0. EXIT\n");
    scanf("%d", &choice);
    switch(choice){
case 1:
    printf("Enter the data: ");
    scanf("%d", &data);
    root = insert(root, data);
    break;
case 2:
    traverse(root);
    break;
case 3:
    printf("Enter the element to be deleted: ");
    scanf("%d", &key);
    root = del(root, key);
    break;
case 0:
    exit(0);
    break;
    }
}
return 0;
}

struct node *create(int data){
    struct node *newNode = (struct node *) malloc(sizeof(struct node));
    if(newNode == NULL){
        printf("ERROR: MEMORY OVERFLOW\n");
        return NULL;
    }
    else{
            newNode->data = data;
            newNode->left = NULL;
            newNode->right = NULL;
    }
    return newNode;
}

struct node *insert(struct node *root, int data){

    if(root == NULL){
        return create(data);
    }

    else if(data<= root->data){
        root->left = insert(root->left, data);
    }
    else if(data> root->data){
        root->right = insert(root->right, data);
    }
    return root;
}

void traverse(struct node *root){
    if(root!=NULL){
        traverse(root->left);
        printf("%d->", root->data);
        traverse(root->right);
    }
}
struct node *minValueNode(struct node *node) {
  struct node *current = node;

  while (current && current->left != NULL)
    current = current->left;

  return current;
}

struct node *del(struct node *root, int key) {
  if (root == NULL){
        return root;
  }
  if (key < root->data)
    root->left = del(root->left, key);
  else if (key > root->data)
    root->right = del(root->right, key);

  else {
    if (root->left == NULL) {
      struct node *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      struct node *temp = root->left;
      free(root);
      return temp;
    }

    struct node *temp = minValueNode(root->right);

    root->data = temp->data;

    root->right = del(root->right, temp->data);
  }
  return root;
}
