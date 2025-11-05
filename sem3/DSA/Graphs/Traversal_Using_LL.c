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
    return q; // return the head
}

NODE *deletefront(NODE *q) {
    if (q == NULL) return NULL;
    NODE *temp = q;
    q = q->link;
    free(temp);
    return q;
}

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
        if (s < 0 || d < 0) break;
        if (s >= n || d >= n) {
            printf("Invalid vertices\n");
            continue;
        }
        insert(a, s, d);
    }
}

void bfs(NODE *a[], int v) {
    NODE *q = NULL, *list;
    visited[v] = 1;
    q = insertrear(v, q);
    printf("BFS traversal: ");
    while (q != NULL) {
        int u = q->data;
        printf("%d ", u);
        q = deletefront(q);
        list = a[u];
        while (list != NULL) {
            int w = list->data;
            if (!visited[w]) {
                visited[w] = 1;
                q = insertrear(w, q);
            }
            list = list->link;
        }
    }
    printf("\n");
}

int main() {
    NODE *a[MAX];
    int n, v;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    creategraph(a, n);
    printf("Enter starting vertex: ");
    scanf("%d", &v);
    bfs(a, v);
}



