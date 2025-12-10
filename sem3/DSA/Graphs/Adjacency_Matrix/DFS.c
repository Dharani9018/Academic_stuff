#include<stdio.h>

#define MAX 50
int a[MAX][MAX];
int n;
int path[MAX];
int p;


void create_matrix()
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
void dfs(int v,int *visited)
{

  visited[v] = 1;
  printf("%d is visited\n",v);
  for(int i = 0;i<n;i++)
  {
    if(a[v][i]==1 && visited[i]==0)
    {
      dfs(i,visited);
    }
  }
}

//For directed graph:
int dfs_cycle(int v,int *visited)
{
    visited[v] = 1;
    path[v] = 1;
    for(int u = 0;u<n;u++)
    {
        if(a[v][u]==1 && ((!visited[u] && dfs_cycle(u,visited)) || path[u]))
        {
            return 1;
        }
    }
    path[v] = 0;
    return 0;
}

int isCyclic()
{
    int visited[MAX] = {0};
    for(int i=0;i<n;i++)
    {
        path[i] = 0;
    }
    for(int i = 0;i<n;i++)
    {
        if(!visited[i] && dfs_cycle(i,visited))
        {
            return 1;
        }
    }
    return 0;
}

// For undirected graph:
/*
int dfs_cycle(int v, int parent, int *visited)
{
    visited[v] = 1;

    for(int u = 0; u < n; u++)
    {
        if(a[v][u] == 1)
        {
            if(!visited[u])
            {
                if(dfs_cycle(u, v, visited))
                    return 1;
            }
            else if(u != parent)
            {
                return 1; 
            }
        }
    }
    return 0;
}

int isCyclic()
{
    int visited[MAX] = {0};

    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            if(dfs_cycle(i, -1, visited))
                return 1;
        }
    }
    return 0;
}
*/

//Path finding:
void printall(int u,int d,int *visited)
{
  visited[u] = 1;
  path[p++] = u;
  if(u==d)
  {
    for(int i =0 ;i<p;i++)
    {
      printf("%d\t",path[i]);
    }
    printf("\n");
  }
  else
  {
    for(int v = 0;v<n;v++)
    {
      if(a[u][v]==1 && !visited[v])
      {
        printall(v,d,visited);
      }
    }
  }
  visited[u] = 0;
  p--;
}

void printpath(int s,int d)
{
  int visited[MAX]={0};
  for(int i = 0;i<n;i++)
  {
    path[i] = 0;
  }
  p = 0;
  printall(s,d,visited);

}

void is_connected()
{
    int visited[MAX] = {0};
    dfs(0,visited);
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            printf("\nGraph not Connected\n");
            return;
        }
    }
    printf("\nGraph Connected\n");
    return;
}


int main()
{
  int s,d,ch;
  printf("Enter the no. of vertices: ");
  scanf("%d",&n);
  create_matrix();
  while(1)
  {
    printf("\n1.Cycle Detection\n2.Connectivity\n3.Path finding\n4.Display");
    scanf("%d",&ch);
    switch (ch)
    {
      case 1:
        if(isCyclic())
        {
          printf("Cycle detected");
        }
        else
        {
          printf("NOt cyclic");  
        }
        break;
      case 2:
        is_connected();
        break;
      case 3:
        printf("Enter source and destination: \n");
        scanf("%d %d",&s,&d);
        printpath(s,d);
        break;

      case 4:
        display();
        break;

      default:
        printf("Invalid\n");
        break;
        
    }

  }
}

