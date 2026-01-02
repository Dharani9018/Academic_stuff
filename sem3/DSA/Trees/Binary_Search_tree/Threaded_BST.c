//Inorder traversal of Binary search tree without recursion or stack using threaded bst.
// 2 types: Single threaded( right threaded: Where all NULL right pointers are made to point to the inorder successor (if successor exists), left threaded:  Where all NULL left pointers are made to point to the inorder predecessor)  & double threaded(both left and right NULL pointers are made to point to inorder predecessor and inorder successor).


//Right threaded-->

#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
  int data,lthread,rthread;
  struct Node *right,*left;
} NODE;

typedef struct tree
{
  NODE *root;
} tree;

tree *init()
{
  tree *temp = malloc(sizeof(tree));
  temp->root = NULL;
  return temp;
}

void Create(tree *ptr,int data)
{
  NODE *newnode = malloc(sizeof(NODE));
  newnode->data = data;
  newnode->left = newnode->right = NULL;
  newnode->lthread = 1;newnode->rthread = 1;
  if(ptr->root == NULL)
  { 
    ptr->root = newnode;
    return;
  }
  NODE *cur = ptr->root;
  while(1)
  {
    if(cur->data == data)
    {
      return;
    }
    if(data<cur->data)
    {
      if(cur->lthread==0)
      {
        cur = cur->left;
      }
      else
      {
        break;
      }
    }
    else
    {
      if(cur->rthread==0)
      {
        cur = cur->right;
      }
      else
      {
        break;
      }
    }
  }
  if(data<cur->data)
  {
    newnode->right = cur;
    newnode->left = cur->left;
    cur->left = newnode;
    cur->lthread = 0;
  }
  else
  {
    newnode->right = cur->right;
    newnode->left = cur;
    cur->right = newnode;
    cur->rthread = 0;
  }
}

NODE *inorder_successor(NODE *node)
{
  if(node==NULL)
    return NULL;
  if(node->rthread==1)
  {
    node = node->right;
  }
  else
  {
    node = node->right;
    while(node->lthread==0)
    {
      node = node->left;
    }
  }
  return node;
}


void inorder(tree *ptr)
{
  NODE *cur = ptr->root;
  if(cur==NULL)
  { 
    printf("\nEmpty\n");
    return;
  }
  while(cur->lthread==0)
  {
    cur = cur->left;
  }
  while(cur!=NULL)
  {
    printf("%d\t",cur->data);
    cur = inorder_successor(cur);
  }
}

int main()
{
  tree *t = init();
  int ch,ele;
  while(1)
  {
    printf("\n1.Create\n2.inorder\n3.exit\n");
    scanf("%d",&ch);
    switch (ch)
    {
      case 1:
        printf("\nEnter the element: ");
        scanf("%d",&ele);
        Create(t,ele);
        break;
      case 2:
        inorder(t);
        break;
      case 3:
        return 0;
      default:
        printf("\nInvalid choice\n");
    }
  }
}
