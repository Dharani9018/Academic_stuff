#include <stdio.h>

//building max heap--> heapify down!!
void bottom_up_heap(int *h,int n)
{
    int i, j, k ,key;

    for( k = (n-1)/2;k>=0;k--)
    {
        j = k;
        key = h[j];
        i = 2*j + 1;
        while(i<=n)
        {
            if(i + 1<=n && h[i+1] > h[i])
            {
                i++;
            }
            if(key<h[i])
            {
                h[j] = h[i];
                j = i;
                i = 2*j+1;
            }
            else
            {
                break;
            }
        }
        h[j] = key;
    }    
}

int main()
{
    int h[100];
    int n, i;

    printf("Enter the number of elements: ");
    scanf("%d",&n);

    printf("Enter the elements: \n");
    for(int i = 0;i<n;i++)
    {
        scanf("%d",h+i);
    }
    printf("\nBefore:\n");
    for(int i = 0;i<n;i++)
    {
        printf("%d\t",h[i]);
    }
    bottom_up_heap(h,n-1);
    printf("\nAfter bottom up heap construction: \n");
    for(int i = 0;i<n;i++)
    {
        printf("%d\t",h[i]);
    }
    printf("\n");
    return 0;
}

