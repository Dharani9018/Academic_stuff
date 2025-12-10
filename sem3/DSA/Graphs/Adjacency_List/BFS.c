#include <stdio.h>
#include <stdlib.h>
#define MAX 50

int n = 0;

typedef struct node 
{
    int data;
    struct node *link;
} NODE;


NODE *insertrear(int v, NODE *q) 
{
    NODE *newnode = malloc(sizeof(NODE));
    newnode->link = NULL;
    newnode->data = v;
    if (q == NULL) return newnode;
    NODE *cur = q;
    while (cur->link != NULL)
        cur = cur->link;
    cur->link = newnode;
    return q;
}

NODE *deletefront(NODE *q) 
{
    if (q == NULL) return NULL;
    NODE *temp = q;
    q = q->link;
    free(temp);
    return q;
}

// Graph creation
void insert(NODE *a[], int s, int d) 
{
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

void creategraph(NODE *a[]) 
{
    int s, d;
    for (int i = 0; i < n; i++)
        a[i] = NULL;

    while (1) {
        printf("Enter source and destination (-1 -1 to stop): ");
        scanf("%d %d", &s, &d);
        if (s == -1 && d == -1)
            break;
        if (s < 0 || d < 0 || s >= n || d >= n) {
            printf("Invalid vertices\n");
            continue;
        }
        insert(a, s, d);
    }
}

void bfs(NODE *a[], int v) 
{
    NODE *q = NULL, *list;
    int visited[MAX] = {0};
    visited[v] = 1;
    q = insertrear(v, q);
    printf("BFS traversal: ");

    while (q != NULL) {
        int u = q->data;
        printf("%d ", u);
        q = deletefront(q);
        list = a[u];
        while (list != NULL) 
        {
            int w = list->data;
            if (!visited[w]) {
                visited[w] = 1;
                q = insertrear(w, q);
            }
            list = list->link;
        }
    }
    printf("\n");
    return;
}

void is_connected(NODE *a[])
{
    int queue[MAX],f=0,r=0,count=0,visited[MAX]={0},start=0;
    visited[start]=1;
    queue[r++] = start;
    while(f<r)
    {
        int u = queue[f++];
        count++;
        NODE *temp = a[u];
        while(temp!=NULL)
        {
            if(!visited[temp->data])
            {
                visited[temp->data] =1;
                queue[r++] = temp->data;
            }
            temp = temp->link;
        }
    }
    if(count==n)
    {
        printf("\nConnected\n");
        return;
    }
    printf("\nNOT Connected\n");
    return;
}

//only for directed graphs, kahn's algorithm
int isCyclic(NODE *a[])
{
    int indegree[MAX] = {0};
    int queue[MAX],f=0,r=0,count=0;
    //compute indegree:

    for(int i = 0;i<n;i++)
    {
        NODE *temp = a[i];
        while(temp!=NULL)
        {
            indegree[temp->data]++;
            temp = temp->link;
        }
    }
    for(int i = 0;i<n;i++)
    {
        if(indegree[i]==0)
        {
            queue[r++] = i;
        }
    }

    //Bfs:
    while(f<r)
    {
        int u = queue[f++];
        count++;
        NODE *temp = a[u];
        while(temp!=NULL)
        {
            indegree[temp->data]--;
            if(indegree[temp->data]==0)
            {
                queue[r++] = temp->data;
            }
            temp = temp->link;
        }
    }
    return count!=n;
}
int main() 
{
    NODE *a[MAX];
    int s,d,ch,v;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    creategraph(a);

    while(1)
    {
        printf("\n1.BFS Traversal\n2.Check Connectivity\n3.Check cyclic\n");
        scanf("%d",&ch);
        switch (ch)
        {
            case 1:
                printf("Enter vertex to start BFS");
                scanf("%d",&v);
                bfs(a,v);
                break;
            case 2:
                is_connected(a);
                break;
            case 3:
                if(isCyclic(a))
                {
                    printf("Cycle detectedn");
                }
                else
                {
                    printf("NO cycle found\n");
                }
                break;
        }
    }
    return 0;
}

