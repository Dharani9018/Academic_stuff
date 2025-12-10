#include <stdio.h>
#include <stdlib.h>

#define MAX 50
int a[MAX][MAX];
int f = 0, r = -1;
int queue[MAX];
int n, p;
int path[MAX];
int parent[MAX];

void create_matrix()
{
    printf("\nEnter the elemnts in the graph: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
}

void display()
{
    printf("graph:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
}

int *bfs(int v)
{
    f = 0; 
    r = -1;

    int *visited = calloc(MAX, sizeof(int));

    visited[v] = 1;
    queue[++r] = v;
    printf("\nBFS traversal:\n");
    printf("%d\t", v);

    while (f <= r)
    {
        v = queue[f++];

        for (int u = 0; u < n; u++)
        {
            if (a[v][u] == 1 && visited[u] == 0)
            {
                queue[++r] = u;
                visited[u] = 1;
                printf("%d\t", u);
            }
        }
    }
    printf("\n");
    return visited;
}

void is_connected()
{
    int v = 0;
    f = 0;
    r = -1;

    int *visited = bfs(v);

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            printf("Not Connected\n");
            return;
        }
    }

    printf("\nConnected\n");
}

void CheckCycle()
{
    int visited[MAX] = {0};
    for(int i = 0; i < n; i++)
        parent[i] = -1;

    f = 0;
    r = -1;

    queue[++r] = 0;
    visited[0] = 1;

    while (f <= r)
    {
        int v = queue[f++];

        for (int u = 0; u < n; u++)
        {
            if (a[v][u] == 1)
            {
                if (!visited[u])
                {
                    visited[u] = 1;
                    parent[u] = v;
                    queue[++r] = u;
                }
                else if (u != parent[v])
                {
                    printf("Cycle detected\n");
                    return;
                }
            }
        }
    }
    printf("\nCycle not found\n");
    return;
}

void Bfspath(int s,int d)
{
    int visited[MAX] = {0};
    f=0,r=-1;
    for(int i=0;i<n;i++)
    {
        parent[i] = -1;
    }
    queue[++r] = s;
    visited[s] = 1;
    while(f<=r)
    {
        int u = queue[f++];
        if(u==d)
        {
            break;
        }
        for(int v=0;v<n;v++)
        {
            if(a[u][v]==1 && !visited[v])
            {
                queue[++r] = v;
                parent[v] = u;
                visited[v] = 1;
            }
        }
    }
}

void printpath(int s,int d)
{
    Bfspath(s,d);
    if(parent[d]==-1 && s!=d)
    {
        printf("\nPath not found\n");
        return;
    }
    p = 0;
    for(int v = d;v!=-1;v = parent[v])
    {
        path[p++] = v;
    }
    printf("\nPath from %d to %d\n",s,d);
    for(int i = p-1;i>=0;i--)
    {
        printf("%d\t",path[i]);
    }
    printf("\n");
}

int main()
{
    int v,ch,s,d;

    printf("Enter the no. of vertices: ");
    scanf("%d", &n);

    create_matrix();
    while(1)
    {
        printf("\n1.Display\n2.Cycle Detection\n3.Check connectivity\n4.Find shortest path\n");
        scanf("%d",&ch);
        switch (ch)
        {
            case 1:
                display();
                break;
            case 2:
                CheckCycle();
                break;
            case 3:
                is_connected();
                break;
            case 4:
                printf("Enter source and destination: \n");
                scanf("%d %d",&s,&d);
                printpath(s,d);
                break;

            default:
                printf("INvalid\n");
                break;
        }
    }

    return 0;
}

