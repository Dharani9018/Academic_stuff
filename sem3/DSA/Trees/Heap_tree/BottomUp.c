#include <stdio.h>

//building max heap:
void bottom_up_heap(int *h,int n)
{
    int i, j, k ,key;
    
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
    bottom_up_heap(h,n-1);
    printf("After bottom up heap construction: \n");
    for(int i = 0;i<n;i++)
    {
        printf("%d\t",h[i]);
    }
    printf("\n");
    return 0;
}