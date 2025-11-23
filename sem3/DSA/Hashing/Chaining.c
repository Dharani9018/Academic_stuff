#include<stdio.h>
#include<stdlib.h>
#define MAX 7

typedef struct node
{
  int data;
  struct node *link;
} NODE;

int hash_fun(int key)
{
  return key%MAX;
}

NODE *create(int key)
{
  NODE *temp = malloc(sizeof(NODE));
  temp->data = key;
  temp->link = NULL;
  return temp;
}

NODE *insert(int key,NODE *root)
{
  NODE *temp = create(key);
  NODE *cur = root;
  if(cur==NULL)
  {
    return temp;
  }
  while(cur->link!=NULL)
  {
    cur = cur->link;
  }
  cur->link = temp;
  return root;
}

void display(NODE *a[])
{
  NODE *cur;
  for(int i = 0;i<MAX;i++)
  {
    printf("%d---\t",i);
    cur = a[i];
    while(cur!=NULL)
    {
      printf("%d\t",cur->data);
      cur = cur->link;
    }
    printf("\n");
  }
}

void search(int key, NODE *a[])
{
  int index = hash_fun(key);
  NODE *cur = a[index];
  while(cur!=NULL)
  {
    if(cur->data==key)
    {
      printf("Element found!!");
      return;
    }
    cur = cur->link;
  }
  printf("Element not found\n");
  return;
}

void delete(int key,NODE *a[])
{
  int index = hash_fun(key);
  NODE *cur = a[index],*pre=NULL;
  while(cur!=NULL)
  {
    if(cur->data==key)
    {
      if(pre==NULL)
      {
        a[index] = cur->link;
      }
      else
      { 
        pre->link = cur->link;
      }
      free(cur);
      printf("Deleted %d\n",key);
      return;
    }
    cur = cur->link;
    pre = cur;
  }
  printf("Element not found\n");
  return;
}

int main()
{
  NODE *a[MAX];
  for(int i = 0;i<MAX;i++)
  {
    a[i] = NULL;
  }
  int ele,ch,key,index;
  while(1)
  {
    printf("\n1.Insert\n2.Display\n3.Search\n4.Delete\n");
    scanf("%d",&ch);
    switch (ch)
    {
      case 1: printf("Enter the key: ");
        scanf("%d",&key);
        index = hash_fun(key);
        a[index] = insert(key,a[index]);
        break;
      case 2:
        display(a);
        break;
      case 3:
        printf("Enter the key to search: ");
        scanf("%d",&key);
        search(key,a);
        break;
      case 4:
        printf("Enter the key to delete: ");
        scanf("%d",&key);
        delete(key,a);
        break;
    }
  }
}
