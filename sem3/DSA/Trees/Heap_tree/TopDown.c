#include <stdio.h>
#define MAX 25

//prelocate up
void siftUp(int *h,int *size,int value)
{
  if(*size>=MAX)
  {
    printf("priority queue is full\n");
    return;
  }
  int i = *size;
  int parent;
  h[i] = value;
  (*size)++;
  while(i>0)
  {
    parent = (i-1)/2;
    if(h[parent]<h[i])
    {
      int temp = h[parent];
      h[parent] = h[i];
      h[i] = temp;
      i = parent;
    }
    else
    {
      break;
    }
  }
  return;
}

//heapify down
void heapify(int *h,int n)
{
  int i = 0,j,key;
  key = h[i];
  j = 2*i+1;
  while(j<=n)
  {
    if(j+1<=n && h[j+1]>h[j])
      j++;

    if(key<h[j])
    {
      h[i] = h[j];
      i = j;
      j = 2*i + 1;
    }
    else
    {
      break;
    }
  }
  h[i] = key;
}

void display(int *h,int size)
{
  if(size<=0)
  {
    printf("\nEmpty\n");
    return;
  }
  for(int i = 0;i<size;i++)
  {
      printf("%d\t",h[i]);
  }
  printf("\n");

}

void deleteMax(int *h,int *size)
{
  if(*size==0)
  {
    printf("Heap is empty\n");
    return;
  }
  int max = h[0];
  h[0] = h[--(*size)];
  printf("Deleted %d\n",max);
  if(*size>0)
  { 
    heapify(h, *size - 1);
  }
  return;
}

int main()
{
    int h[MAX];
    int value, ch,size=0;
    while(1)
    {
      printf("\n1.Insert\n2.Delete\n3.display\n");
      scanf("%d",&ch);
      
      switch (ch)
      {
        case 1:printf("Enter the Value: ");
          scanf("%d",&value);
          siftUp(h,&size,value);
          break;

        case 2:
          deleteMax(h,&size);
          break;

      case 3:display(h,size);
        break;

      default:printf("\nInvalid\n");
        break;
        
      }
    }
    return 0;
}
