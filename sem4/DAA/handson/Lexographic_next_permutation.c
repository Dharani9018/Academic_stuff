#include<stdio.h>

void swap(int *x,int *y);
void reverse(int *a,int start,int end);
void display(int *a,int n);
int find_j(int *a,int n,int i);
int find_i(int *a,int n);

void swap(int *x,int *y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}

void reverse(int *a,int start,int end)
{
  
  while(start < end)
  {
    swap(a+start,a+end);
    ++start;
    --end;
  }
}


void display(int *a,int n)
{
  printf("\n");
  for(int i = 0;i<n;i++)
  {
    printf("%d\t",a[i]);
  }
}

int find_i(int *a,int n)
{
  int index = -1;
  for(int i=0;i<n-1;i++)
  {
    if(a[i+1]>a[i])
    {
      index = i;
    }
  }
  return index;
}

int find_j(int *a,int n,int i)
{
  int index = -1;
  for(int j = i+1;j<n;j++)
  {
    if(a[i]<a[j])
    {
      index = j;
    }
  }
  return index;
}
/* tests
void test_find_i()
{
  int a[5] = {1,2,3,4,5};
  printf("Index: %d\n",find_i(a,5));
  printf("Index: %d\n",find_i(a,0));
}
void test_find_j()
{
  int a[5] = {5,4,7,1,2};
  printf("Index: %d\n",find_j(a,5,0));
  printf("Index: %d\n",find_j(a,5,1));
}
void test_swap()
{
  int x,y;
  printf("Enter the numbers to be swapped: x, y ");
  scanf("%d %d",&x,&y);
  swap(&x,&y);
  printf("x = %d y = %d\n\n",x,y);
  x = 10;y = 10;
  printf("Before: x = %d, y = %d",x,y);
  swap(&x,&y);
  printf("\tAfter x = %d y = %d\n",x,y);
  x = 1;y = 2;
  printf("Before: x = %d, y = %d",x,y);
  swap(&x,&y);
  printf("\tAfter x = %d y = %d\n",x,y);  
}
void test_reverse()
{
  int a[5] = {1,2,3,4,5};
  display(a,5);
  reverse(a,0,4);
  printf("from 0 to 4");
  display(a,5);
}
*/

void gen_perm(int *p,int n)
{
  display(p,n);
  int i = find_i(p,n);
  while(i!=-1)
  {
    int j = find_j(p,n,i);
    if(j!=-1)
    {
      swap(p+i,p+j);
      reverse(p,i+1,n-1);
      display(p,n);
    }
    i = find_i(p,n);
  }
}
int main()
{
  /*test_swap();
  test_reverse();
  test_find_i();*/
  int p[4] = {1,2,3,4};
  gen_perm(p,4);
  return 0;
}
//-Wall
//

