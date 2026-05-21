# include <stdio.h>
# include <stdlib.h>

# define MAX 50

int n;
int graph[MAX][MAX];
int dist[MAX];
int visited[MAX];
int parent[MAX];

void create_matrix()
{
  printf("\nEnter the elements in the graph(999 for no edge): \n");
  for(int i = 0; i<n;i++)
  {
    for(int j = 0; j<n;j++)
    {
      scanf("%d",&graph[i][j]);
    }
  }
}

int main()
{
  int ch,source,destination;
  printf("Enter the number of vertices: ");
  scanf("%d",&n);
  create_matrix();
}
