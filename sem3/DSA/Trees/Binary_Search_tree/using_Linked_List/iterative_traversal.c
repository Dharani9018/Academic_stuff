#include<stdio.h>
#include<stdlib.h>

typedef struct tree_node
{
  int data;
  struct tree_node *left,*right;
} TN;

//Global variable:
TN *stack[100];
int top;

//Stack functions:
int isempty()
{
  if(top==-1)
    return 1;
  return 0;
}

void push(TN *temp)
{
  stack[++top] = temp;
}

TN *pop()
{
  TN *temp;
  temp = stack[top--];
  return temp;
}

void inorder(TN *root)
{
  top = -1;
  while(root!=NULL)
  {
    push(root);
    root = root->left;
  }
  while(!isempty())
  {
    root = pop();
    printf("%d\t",root->data);;
    if(root->right!=NULL)
    {
      root = root->right;
      while(root!=NULL)
      {
        push(root);
        root = root->left;
      }
    }
  }
}

void insert(TN ** root,int data)
{
  TN *newnode = malloc(sizeof(TN));
  newnode->data = data;
  newnode->left = newnode->right = NULL;
  if(*root == NULL)
  { 
    *root = newnode;
    return;
  }
  TN *cur = *root,*pre;
  while(cur!=NULL)
  {
    if(cur->data==data)
    {
      return;
    }
    pre = cur;
    if(cur->data>data)
    {
      cur = cur->left;
    }
    else
    {
      cur = cur->right;
    }
  }
  if(data<pre->data)
  {
    pre->left = newnode;
  }
  else
  {
    pre->right = newnode;
  }
  return;
}

int main()
{
  int num,ch;
  TN *root;
  root=NULL;
  while(1)
  {
    printf("\n1.Insert\n2.Inorder\n3.Exit\n");
    scanf("%d",&ch);
    switch (ch)
    {
      case 1:
        printf("\nEnter the element: ");
        scanf("%d",&num);
        insert(&root,num);
        break;
      case 2:
        printf("\nInorder traversal: \n");
        inorder(root);
        printf("\n");
        break;
      case 3:
        return 0;

      default:printf("Invalid choice\n");
    }
  }
}
