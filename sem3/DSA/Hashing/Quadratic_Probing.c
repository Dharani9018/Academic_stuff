#include<stdio.h>
#include<stdlib.h>

#define MAX 10
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

void init()
{
  for(int i = 0;i<MAX;i++)
  {
    array[i].flag = 0;
    array[i].data = NULL;
  }
}

int hash_fun(int key)
{
  return key%MAX;
}
void insert(int key,int value)
{
  int index,i;
  item *ele = malloc(sizeof(item));
  ele->key = key;
  ele->value = value;
  i = hash_fun(key);
  index = i;
  int h = 1;
  while(array[i].flag==1)
  {
    if(array[i].data->key==key)
    {
      printf("duplicate!! update value\n");
      array[i].data->value = value;
    }
    i = (i+(h * h))%MAX;
    h++;
    if(index==i)
    {
      printf("\nHash table full\n");
      return;
    }
  }
  array[i].flag = 1;
  array[i].data = ele;
  printf("%d key is inserted at index %d",key,i);
}

void display()
{
  for(int i =0;i<MAX;i++)
  {
    if(array[i].data==NULL)
    {
      printf("No data\t");
    }
    else
      printf("Key(%d):value(%d)\t",array[i].data->key,array[i].data->value);

  }
  printf("\n");
}

void search(int key)
{
  int i ,index;
  i = hash_fun(key);
  index = i;
  int h = 1;
  while(array[i].flag!=0)
  {
    if(array[i].flag==1 && array[i].data->key == key)
    {
      printf("Key is found");
      return;
    }
    i = (i + (h*h))%MAX;
    h++;
    if(i==index)
    {
      printf("Not found\n");
      return;
    }
  }
}

void remove_key(int key)
{
  int index = hash_fun(key);
  int i = index;
  int h =1;
  while(array[i].flag!=0)
  {
    if(array[i].data->key==key)
    {
      array[i].flag=2;
      array[i].data=NULL;
      return;
    }
    i = (i+(h*h))%MAX;
    h++;
    if(i==index)
      break;
  }
  printf("Element not found\n");
  return;
}

int main()
{
  int key,value,choice;
  array = malloc(MAX * sizeof(hash_table));
  init();
  while(1)
  {
    printf("\n1.insert\n2.display\n");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:
        printf("Enter key and value: ");
        scanf("%d %d",&key,&value);
        insert(key,value);
        break;
      case 2:
        display();
    }
  }
}

