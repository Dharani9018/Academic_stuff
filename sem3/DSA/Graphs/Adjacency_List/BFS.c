#include <stdio.h>
#include <stdlib.h>
#define MAX 50

int visited[MAX] = {0};

typedef struct node {
    int data;
    struct node *link;
} NODE;


NODE *insertrear(int v, NODE *q) {
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

NODE *deletefront(NODE *q) {
    if (q == NULL) return NULL;
    NODE *temp = q;
    q = q->link;
    free(temp);
    return q;
}

// Graph creation
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

int bfs(NODE *a[], int v,int n) {
    NODE *q = NULL, *list;
    for (int i = 0; i < MAX; i++)
        visited[i] = 0;

    visited[v] = 1;
    int count = 1;
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
                count++;
            }
            list = list->link;
        }
    }
    printf("\n");
    return count==n; //returns 1 if the whole graph is connected.
}
int main() 
{
    NODE *a[MAX];
    int n, v;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    creategraph(a, n);

    for (int i = 0; i < MAX; i++)
        visited[i] = 0;
    printf("\n");

    return 0;
}

