//directed
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct node {
    int data;
    struct node *link;
} NODE;

void insert(NODE *a[], int i, int j)
{
    NODE *newnode = malloc(sizeof(NODE));
    newnode->data = j;
    newnode->link = NULL;

    if (a[i] == NULL)
        a[i] = newnode;
    else {
        NODE *cur = a[i];
        while (cur->link != NULL)
            cur = cur->link;
        cur->link = newnode;
    }
}

void display(NODE *a[], int n)
{
    for (int i = 0; i < n; i++) {
        NODE *cur = a[i];
        printf("%d -> ", i);
        while (cur != NULL) {
            printf("%d ", cur->data);
            cur = cur->link;
        }
        printf("\n");
    }
}

void create_graph(NODE *a[], int n)
{
    int i, j;
    for (int k = 0; k < n; k++)
        a[k] = NULL;

    while (1) {
        printf("Enter the source and destination (-1 -1 to stop): ");
        scanf("%d %d", &i, &j);
        if (i < 0 || j < 0 || i >= n || j >= n)
        {     
            break;
        }
        insert(a, i, j);
    }
}

int indegree(NODE *a[], int v, int n)
{
    int count = 0;
    for (int i = 0; i < n; i++) {
        NODE *cur = a[i];
        while (cur != NULL) {
            if (cur->data == v)
                count++;
            cur = cur->link;
        }
    }
    return count;
}

int outdegree(NODE *a[], int v)
{
    int count = 0;
    NODE *cur = a[v];
    while (cur != NULL) {
        count++;
        cur = cur->link;
    }
    return count;
}

int main()
{
    int n, v;
    NODE *a[MAX];
    printf("\nVertices: ");
    scanf("%d", &n);

    create_graph(a, n);
    display(a, n);

    printf("\nEnter vertex to calculate indegree/outdegree: ");
    scanf("%d", &v);

    printf("Indegree of %d = %d\n", v, indegree(a, v, n));
    printf("Outdegree of %d = %d\n", v, outdegree(a, v));

    return 0;
}

