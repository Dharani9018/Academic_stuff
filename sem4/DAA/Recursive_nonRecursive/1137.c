nth tribonacci number:
int tribonacci(int n) 
{
  /* Recursive
    if(n==0)
    {
        return 0;
    }    
    if(n==1 || n== 2)
    {
        return 1;
    }
    return tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);
  */
  //Iterative:
    int a[n+1];
    for(int i = 0;i<n+1;i++)
    {
        if(i==0)
        {
            a[i]=0;
        }
        else if(i==1 || i == 2)
        {
            a[i] = 1;
        }
        else
        {
            a[i] = a[i-1] + a[i-2] + a[i-3];
        }
    }
    return a[n];
}
