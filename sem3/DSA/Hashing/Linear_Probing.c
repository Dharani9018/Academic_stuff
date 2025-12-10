#include<stdio.h>
#include<stdlib.h>
#define MAX 5
typedef struct item
{
  int key;
  int value;
} item;

typedef struct hash
{
  int flag;
  struct item *data;
} hash_table;

hash_table *array;

int hash_fun(int key)
{
  return(key%MAX);
}

void insert(int key, int value)
{
  int index,i;
  item *ele = malloc(sizeof(item));
  ele->key = key;
  ele->value = value;
  i = hash_fun(key);
  index = i;
  while(array[i].flag==1)
  {
    if(array[i].data->key==key)
    {
      printf("duplicate key, updated value\n");
      array[i].data->value = value;
      return;
    }
    i = (i+1)%MAX;
    if(i==index)
    {
      printf("Hash table is full");
      return;
    }
  }
  array[i].flag = 1; 
  array[i].data = ele;
  printf("%d inserted at index %d",key,i);
  return;
}

void search(int key)
{
  int i,index;
  i = hash_fun(key);
  index=i;
  while(array[i].flag!=0)
  {
    if(array[i].flag==1 && array[i].data->key==key)
    {
      printf("key is found\n");
      return;
    }
    i = (i+1)%MAX;
    if(i==index)
      break;
  }
  printf("Not found\n");
}

void remove_key(int key)
{
  int index = hash_fun(key);
  int i = index;
  while(array[i].flag!=0)
  {
    if(array[i].flag==1 && array[i].data->key==key)
    {
      array[i].flag=2;
      free(array[i].data);
      array[i].data=NULL;
      return;
    }
    i = (i+1)%MAX;
    if(i==index)
      break;
  }
  printf("Element not found\n");
  return;
}

void display()
{
  for(int i =0;i<MAX;i++)
  {
    if(array[i].flag!=1 || array[i].data==NULL)
    {
      printf("No data\t");
    }
    else
      printf("Key(%d):value(%d)\t",array[i].data->key,array[i].data->value);

  }
  printf("\n");
}

int main()
{
  int key,value,choice;
  array = malloc(sizeof(hash_table)*MAX);
  for(int i = 0;i<MAX;i++)
  {
    a[i].data=NULL;
    a[i].flag = 0;
  }

  while(1)
  {
    printf("\n1.Insert\n2.Display\n3.Search\n4.remove_key\n");
    scanf("%d",&choice);
    switch (choice)
    {
      case 1:
        printf("Enter key: ");
        scanf("%d",&key);
        printf("\nEnter value: ");
        scanf("%d",&value);
        insert(key,value);
        break;
      case 2:
        display();
        break;
      case 3:
        printf("Enter the key: ");
        scanf("%d",&key);
        search(key);
        break;

      case 4:
        printf("Enter the key: ");
        scanf("%d",&key);
        remove_key(key);
        break;
    }
  }
}
