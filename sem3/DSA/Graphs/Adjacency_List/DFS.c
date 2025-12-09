#include <stdio.h>
#include <stdlib.h>
#define MAX 50


typedef struct node 
{
    int data;
    struct node *link;
} NODE;

//Global variables
int path[MAX] = {0};
int k = 0;

//Functions:

//To create Graph:
void creategraph(NODE *a[], int n);
void insert(NODE *a[], int s, int d);

//DFS traversal:
void dfs(NODE *a[], int v,int *visited);

//graph Connectivity:
void is_connected(NODE *a[],int n);

//Cycle:
int dfs_cycle(NODE *a[],int v,int *visited);
int isCyclic(NODE *a[],int n);

//Path finding:
void printALLpath(NODE *a[],int src,int des);
void printALLpathsdfs(NODE *a[],int src,int des,int *visited);

void insert(NODE *a[], int s, int d) {
    NODE *newnode = malloc(sizeof(NODE));
    newnode->data = d;
    newnode->link = NULL;
    if (a[s] == NULL) {
        a[s] = newnode;
        return;
    }
    NODE *cur = a[s];
    while (cur->link != NULL)
        cur = cur->link;
    cur->link = newnode;
}

void creategraph(NODE *a[], int n) {
    int s, d;
    for (int i = 0; i < n; i++)
        a[i] = NULL;

    while (1) 
    {
        printf("Enter source and destination (-1 -1 to stop): ");
        scanf("%d %d", &s, &d);
        if (s == -1 && d == -1)
            break;
        if (s < 0 || d < 0 || s >= n || d >= n) 
        {
            printf("Invalid vertices\n");
            continue;
        }
        insert(a, s, d);
    }
}

//DFS Traversal: 
void dfs(NODE *a[], int v,int *visited)
{
    NODE *temp;
    visited[v] = 1;
    printf("%d ", v);

    temp = a[v];
    while (temp != NULL) {
        if (!visited[temp->data])
        { 
            dfs(a, temp->data,visited);
        }
        temp = temp->link;
    }
}

void is_connected(NODE *a[],int n)
{
    int visited[MAX] = {0};
    dfs(a,0,visited);
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

int dfs_cycle(NODE *a[],int v,int *visited)
{
    NODE *temp;
    visited[v] = 1;
    path[v] = 1;
    temp = a[v];
    while(temp!=NULL)
    {
        if((!visited[temp->data] && dfs_cycle(a,temp->data,visited)) || path[temp->data])
        {
            return 1;
        }
        temp = temp->link;
    }
    path[v] = 0;
    return 0;
}

int isCyclic(NODE *a[],int n)
{
    int visited[MAX] = {0};
    for(int i=0;i<n;i++)
    {
        path[i] = 0;
    }
    for(int i = 0;i<n;i++)
    {
        if(!visited[i] && dfs_cycle(a,i,visited))
        {
            return 1;
        }
    }
    return 0;
}

void printALLpath(NODE *a[],int src,int des)
{
    int visited[MAX] = {0};
    k =0;
    printf("All the paths from %d to %d:\n",src,des);
    printALLpathsdfs(a,src,des,visited);
}

void printALLpathsdfs(NODE *a[],int src,int des,int *visited)
{
    visited[src] = 1;
    path[k++] = src;
    if(src==des)
    {
        for(int i=0;i<k;i++)
        {
            printf("%d\t",path[i]);
        }
        printf("\n");
    }
    else
    {
        NODE *temp = a[src];
        while(temp!=NULL)
        {
            if(!visited[temp->data])
            {
                printALLpathsdfs(a,temp->data,des,visited);
            }
            temp = temp->link;
        }
    }
    k--;
    visited[src] = 0;
}

int main() 
{
    NODE *a[MAX];
    int n,ch,s,d;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    creategraph(a, n);
    printf("\n");
    while(1)
    {
        printf("1.Check if graph is connected\n\n2.Check Cyclic\n3.print path\n");
        scanf("%d",&ch);
        switch (ch)
        {
            case 1:
                is_connected(a,n);
                break;

            case 2:
                if(isCyclic(a,n))
                {
                    printf("\nCycle detected\n");
                }
                else
                {
                    printf("\nNo Cycle");
                }
                break;
            case 3:
                printf("Enter source and destination: ");
                scanf("%d %d",&s,&d);
                printALLpath(a,s,d);
                break;
                
        }
    }
    return 0;
}

