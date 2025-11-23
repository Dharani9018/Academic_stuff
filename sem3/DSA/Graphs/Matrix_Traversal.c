#include<stdio.h>

//Using Adjacency matrix:

#define MAX 50
int visited[MAX]={0};
int a[MAX][MAX];
int f = 0,r = -1;
int queue[MAX];
int n;


int create_matrix()
{
  printf("\nEnter the elemnts in the graph: \n");
  for(int i = 0;i<n;i++)
  {
    for(int j = 0;j<n;j++)
    {
      scanf("%d",&a[i][j]);
    }
  }
}

void display()
{
  printf("graph:\n");
  for(int i = 0;i<n;i++)
  {
    for(int j = 0;j<n;j++)
    {
      printf("%d\t",a[i][j]);
    }
    printf("\n");
  }
}
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
void bfs(int v)
{
  visited[v] = 1;
  printf("%d is visited\n",v);
  queue[++r] = v;
  while(f<=r)
  {
    v = queue[f++];
    for(int u = 0;u<n;u++)
    {
      if(a[v][u]==1)
      {
        if(visited[u] == 0)
        {
          queue[++r] = u;
          visited[u] = 1;
          printf("%d\t",u);
        }
      }
    }
  }
}
int main()
{
  int v,d;
  printf("Enter the no. of vertices: ");
  scanf("%d",&n);
  create_matrix();
  display();
  printf("Enter the starting vertex: ");
  scanf("%d",&v);
  bfs(v);
}

