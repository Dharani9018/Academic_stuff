#include<stdio.h>
#include<stdlib.h>

typedef struct node {
  int data;
  struct node *left, *right;
} NODE;

void Insert(NODE **root, int num)
{
  NODE *newnode = malloc(sizeof(NODE));
  newnode->data = num;
  newnode->left = newnode->right = NULL;

  if (*root == NULL) {
    *root = newnode;
    return;
  }

  NODE *pre = NULL, *cur = *root;
  while (cur != NULL)
  {
    pre = cur;
    if (num < cur->data)
      cur = cur->left;
    else if (num > cur->data)
      cur = cur->right;
    else 
    {
      free(newnode);  // duplicates not allowed
      return;
    }
  }

  if (num < pre->data)
    pre->left = newnode;
  else
    pre->right = newnode;
}

void Preorder(NODE *root) 
{
  if (root == NULL) return;
  printf("%d\t", root->data);
  Preorder(root->left);
  Preorder(root->right);
}

void Inorder(NODE *root) 
{
  if (root == NULL) return;
  Inorder(root->left);
  printf("%d\t", root->data);
  Inorder(root->right);
}

void Postorder(NODE *root) 
{
  if (root == NULL) return;
  Postorder(root->left);
  Postorder(root->right);
  printf("%d\t", root->data);
}

void Delete(NODE **root, int key) 
{
  if (*root == NULL) 
  {
    printf("\nEmpty tree\n");
    return;
  }

  NODE *cur = *root, *parent = NULL;

  while (cur != NULL && cur->data != key) 
  {
    parent = cur;
    if (key < cur->data)
      cur = cur->left;
    else
      cur = cur->right;
  }

  if (cur == NULL) {
    printf("\nElement doesn't exist\n");
    return;
  }

  int x = cur->data;
  NODE *succParent = NULL, *succ = NULL;

  // Node with 2 children
  if (cur->left != NULL && cur->right != NULL) 
  {
    succParent = cur;
    succ = cur->right;
    while (succ->left != NULL) 
    {
      succParent = succ;
      succ = succ->left;
    }
    cur->data = succ->data;  // Replace data
    cur = succ;
    parent = succParent;
  }

  NODE *child = (cur->left != NULL) ? cur->left : cur->right;

  if (parent == NULL) {  // Deleting root
    *root = child;
    free(cur);
    printf("\nNode %d deleted\n", x);
    return;
  }

  if (cur == parent->left)
    parent->left = child;
  else
    parent->right = child;

  free(cur);
  printf("\nNode %d deleted\n", x);
}

//WAF to find the max node:
int MaxNode(NODE *root)
{
  if(root==NULL)
    return -1;

  if(root->right==NULL)
  {
    return root->data;
  }
  NODE *cur = root,*pre=NULL;

  while(root!=NULL)
  {
    pre = cur;
    cur = cur->right;
  }
  return pre->data;
}

//waf to count the no. of nodes:
int countNodes(NODE *root)
{
    if(root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

//waf to count the no. of leaf nodes:
int leafcount(NODE *root)
{
  int l,r;
  if(root==NULL)
    return 0;
  if(root->left==NULL && root->right==NULL)
    return 1;
  l = leafcount(root->left);
  r = leafcount(root->right);
  return l+r;
}

//waf to search for a particular element:
int search(NODE *root,int key)
{
  if(root==NULL)
    return 0;
  if(root->data==key)
    return 1;
  if(key>root->data)
  { 
    return search(root->right,key);
  }
  return search(root->left,key);
}

//waf to calculate the height of the binary tree:
int height(NODE *root)
{
  int l,r;
  if(root==NULL)
    return -1;
  if(root->left==NULL && root->right==NULL)
    return 0;

  l = height(root->left);
  r = height(root->right);
  return (l > r) ? (l + 1) : (r + 1);
}

int main() {
  NODE *root = NULL;
  int ch, num;

  while (1) {
    printf("\n1.Insert\n2.Preorder\n3.Inorder\n4.Postorder\n5.Delete\n6.Exit\n");
    scanf("%d", &ch);

    switch (ch) 
    {
      case 1:
        printf("Enter data: ");
        scanf("%d", &num);
        Insert(&root, num);
        break;

      case 2:
        printf("\nPreorder Traversal\n");
        Preorder(root);
        break;

      case 3:
        printf("\nInorder Traversal\n");
        Inorder(root);
        break;

      case 4:
        printf("\nPostorder Traversal\n");
        Postorder(root);
        break;

      case 5:
        printf("\nEnter the element to delete: ");
        scanf("%d", &num);
        Delete(&root, num);
        break;

      case 6:
        return 0;

      default:
        printf("\nInvalid Option\n");
    }
  }
}

