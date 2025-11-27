/*adjacency matrix using array */
#include <stdio.h>
#define Max_vertices 100
void addEdge(int graph[Max_vertices][Max_vertices],int start,int end)
{
  graph[start][end] = 1;
  //graph[end][start] = 1; //add this line for undirected.
}
void display(int graph[Max_vertices][Max_vertices],int vertices)
{
  for(int i = 0;i<vertices;i++)
  {
    for(int j = 0;j<vertices;j++)
    {
      printf("%d\t",graph[i][j]);
    }
  }
}
int outdegree(int graph[Max_vertices][Max_vertices],int v,int n)
{
  int count = 0;
  for(int i = 0;i<n;i++)
  {
   if(graph[v][j]==1)
   { 
     count++;
   }
  }
  return count;
}
int indegree(int graph[Max_vertices][Max_vertices],int v,int n)
{
  int count = 0;
  for(int i = 0;i<n;i++)
  {
    if(graph[i][v]==1)
    {
      count++;
    }
  }
  return count;
}
int main()
{
  int vertices, edges;
  printf("Enter the number of vertices & edges: ");
  scanf("%d",&vertices);
  scanf("%d",&edges);
  if(vertices<=0 || vertices>Max_vertices)
  {
    printf("\nInvalid input\n");
    return 1;
  }
  int graph[Max_vertices][Max_vertices] = {0};
  for(int i = 0; i< edges;i++)
  {
    int start, end;
    printf("Enter edge %d(start end)",i+1);
    scanf("%d%d",&start,&end);
    if(start<0 || start>=vertices || end<0 || end>vertices)
    {
      printf("\nInvalid vertices\n");
      i--;
      continue;
    }
    addEdge(graph,start,end);
  }
  display(graph,vertices);
}
