#include<stdio.h>
#include<stdlib.h>

#define MAX 10

typedef struct node
{
  int data;
  int flag;
} NODE;

typedef struct hash
{
  int size;
  struct node *hashtable;
} HASH;

int count = 0;

HASH *createHASH(int size)
{
  HASH *hash = malloc(sizeof(HASH));
  hash->size = size;
  hash->hashtable = malloc(size*(sizeof(NODE)));
  for(int i = 0;i<size;i++)
  {
    hash->hashtable[i].flag = 0;
  }
  return hash;
}

void rehash(int key,HASH **h)
{
  int newsize = ((*h)->size)*2;
  //prime no. not taken
  HASH *newhash = createHASH(newsize);
  int hash,j=0;
  for(int i = 0;i<((*h)->size);i++)
  {
    if((*h)->hashtable[i].flag == 1) //collision
    {
      //linear probing:
      hash = ((*h)->hashtable[i].data + j)%newsize;
      while(newhash->hashtable[hash].flag!=0)
      {
        j++;
        hash = ((*h)->hashtable[i].data%newsize+j)%newsize;
      }
      newhash->hashtable[hash].flag=1;
      newhash->hashtable[hash].data=(*h)->hashtable[i].data;
    }
  }
  destroy(*h);
  *h = newhash;
}

int hash_fun(int key,int size)
{
  return key % size;
}

void insert(int key, HASH *h)
{
  int index,i=0;
  count++;
  if(count>(float)(0.75*(h->size)))
  {
    rehash(key,&h);
  }
  else
  {
     index = hash_fun(key);
    if(h->hashtable[index].flag==1)
    {

    }
  }
}
int main()
{
  HASH *hashtable = createHASH(MAX);
  int ch,key;
  while(1)
  {
    printf("\n1.Insert\n");
    scanf("%d",&ch);
    switch (ch):
    {
      case 1: printf("Enter the key: ");
        scanf("%d",&key);
        insert(key,hashtable);
        break;
    }
  }

}
