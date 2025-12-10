#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct node {
    int data;
    int flag;    // 0 = empty, 1 = occupied
} NODE;

typedef struct hash {
    int size;
    struct node *hashtable;
} HASH;

int count = 0;

HASH *createHASH(int size)
{
    HASH *hash = malloc(sizeof(HASH));
    hash->size = size;
    hash->hashtable = malloc(size * sizeof(NODE));
    for (int i = 0; i < size; i++) {
        hash->hashtable[i].flag = 0;
    }
    return hash;
}

int hash_fun(int key, int size)
{
    return key % size;
}

void rehash(int key, HASH **h)
{
    int newsize = (*h)->size * 2;

    HASH *newhash = createHASH(newsize);

    for (int i = 0; i < (*h)->size; i++)
    {
        if ((*h)->hashtable[i].flag == 1)
        {
            int data = (*h)->hashtable[i].data;
            int idx = hash_fun(data, newsize);
            int start = idx;

            while (newhash->hashtable[idx].flag == 1)
            {
                idx = (idx + 1) % newsize;
                if (idx == start)
                    break; 
            }

            newhash->hashtable[idx].data = data;
            newhash->hashtable[idx].flag = 1;
        }
    }

    free((*h)->hashtable);
    free(*h);

    *h = newhash;
}

void insert(int key, HASH *h)
{
    count++;

    // Load factor check
    if (count > (float)(0.75 * h->size))
    {
        rehash(key, &h);   // expand the table
    }

    int index = hash_fun(key, h->size);
    int start = index;

    while (h->hashtable[index].flag == 1)
    {
        index = (index + 1) % h->size;
        if (index == start)
        {
            printf("Hash table is full\n");
            return;
        }
    }

    h->hashtable[index].data = key;
    h->hashtable[index].flag = 1;
}

int main()
{
    HASH *hashtable = createHASH(MAX);
    int ch, key;

    while (1)
    {
        printf("\n1.Insert\n");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                printf("Enter key: ");
                scanf("%d", &key);
                insert(key, hashtable);
                break;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

