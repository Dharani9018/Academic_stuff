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
    queue[++r] = v; //insert starting element into queue
    printf("\nBFS traversal:\n");
    printf("%d\t", v);

    while (f <= r) //loop until front less than or equal to rear
    {
        v = queue[f++]; //delete from front and store it in v (v->row index)

        for (int u = 0; u < n; u++)
        {
            if (a[v][u] == 1 && visited[u] == 0) //find neighbours of v and check if they're visited
            {
                //if not visited, insert to queue, mark visited and print.
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

    int *visited = bfs(v); //track visited array from bfs traversal.

    for (int i = 0; i < n; i++)
    {
        if (!visited[i]) //if any 1 of the vertex is not visited, then the graph is not connected.
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

    queue[++r] = 0; //start from the vertex 0, insert it queue.
    visited[0] = 1; //mark visited.

    while (f <= r) //loop until from less than or equal to rear.
    {
        int v = queue[f++]; //delete front and store it in v.

        for (int u = 0; u < n; u++) 
        {
            if (a[v][u] == 1) //if u find a neighbour.
            {
                if (!visited[u]) //if the neighbour is not visitedd, mark visited.
                {
                    visited[u] = 1;
                    parent[u] = v; //store the parent of u.
                    queue[++r] = u; //insert to queue.
                }
                else if (u != parent[v]) 
                //if its already  visited and if u is not the parent of v
                //, cycle detected!!  
                //avoids detecting this as a cycle:
                // [0] --- [1]      
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
    queue[++r] = s; //insert source to queue
    visited[s] = 1;//mark visited.
    while(f<=r)
    {
        int u = queue[f++]; //delete from front and store it in u.
        if(u==d) 
        {
            break;
        }
        for(int v=0;v<n;v++)
        {
            if(a[u][v]==1 && !visited[v]) //check if the neighbours are not visited.
            {
                queue[++r] = v; //insert to queue
                parent[v] = u; //track parent(row)
                visited[v] = 1;//mark visited.
            }
        }
    }
}


void printpath(int s,int d)
{
    //BFS used to find shortest path.
    Bfspath(s,d);
    if(parent[d]==-1 && s!=d) //if d doesnt have a parent(means d is not a neighbour of any vertex) and source and destination are not the same.
    {
        printf("\nPath not found\n");
        return;
    }
    p = 0;
    for(int v = d;v!=-1;v = parent[v]) 
    //ex d=3, parent[-1,0,0,1,3] after loop-> path[3,1,0]    
    {
        path[p++] = v;
    }
    
    printf("\nPath from %d to %d\n",s,d);
    for(int i = p-1;i>=0;i--)
    {
        //print path from reverse.
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

