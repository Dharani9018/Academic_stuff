#include<stdio.h>
#include<stdlib.h>
#define MAX 50
int visited[MAX] = {0};

typedef struct node
{
  int data;
  struct node *link;
}NODE;

NODE *insertrear(int v,NODE *q)
{
  NODE *newnode = malloc(sizeof(NODE));
  newnode->link = NULL;
  newnode->data = v;
  if(q==NULL)
  {
    q = newnode;
    return newnode;
  }
  NODE *cur = q;
  while(cur->link!=NULL)
  {
    cur = cur->link;
  }
  cur->link = newnode;
  return newnode;
}

NODE *deletefront(NODE *q)
{
  if(q==NULL)
  {
    return q;
  }
 if(q->link==NULL)
  {
    free(q);
    q = NULL;
    return q;
  }
    NODE *first = q;
    NODE *second = q->link;
    q = second;
    free(first);
    first = NULL;
  return q;
}
void bfs(NODE *a[],int v)
{
  NODE *q = NULL,*list;
  int u;
  visited[v] = 1;
  q = insertrear(v,q);
  printf("%d is visited\n",v);
  while(q!=NULL)
  {
    u = q->data;
    q = deletefront(q);
    list = a[u];
    while(list!=NULL)
    { 
      v = list->data;
      if(visited[v]==0)
      {
        visited[v] =1;
        q = insertrear(v,q);
        printf("%d\t",v);
      }
      list = list->link;
    }
  }
}

void insert(NODE *a[],int s,int d)
{
  NODE *newnode = malloc(sizeof(NODE));
  newnode->data = d;
  newnode->link = NULL;
  NODE *cur = a[s];
  if(cur==NULL)
  {
    a[s] = newnode;
    return;
  }
  while(cur->link!=NULL)
  {
    cur = cur->link;
  }
  cur->link = newnode;
}

void creategraph(NODE *a[],int n)
{
  int s,d;
  for(int i = 0;i<n;i++)
  {
    a[i] = NULL;
  }
  while(1)
  {
    printf("enter the source and destination: ");
    scanf("%d %d",&s,&d);
    if(s<0 || d<0 || s>=n || d>=n)
    {
      break;
    }
    insert(a,s,d);
  }
}

/* using array.
void dfs(int v)
{
  visited[v] = 1;
  printf("%d is visited\n",v);
  for(int i = 0;i<n;i++)
  {
    if(a[v][i]==1 && visited[i]==0)
    {
      dfs(i);
    }
  }
}
*/

int main()
{
  NODE *a[MAX];
  int n,v;
  printf("Enter the number of  vertices: ");
  scanf("%d",&n);
  creategraph(a,n);
  printf("Enter the starting vertex: ");
  scanf("%d",&v);
  bfs(a,v);
}




