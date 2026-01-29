#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
  pid_t p1;
  int y = 10;
  p1 = fork(); //The process splits here
  if(p1>0)
  {
    printf("p1=%d\n",p1);
    y = y + 1;
    printf("This is parent process. Process Id= %d , y = %d\n", getpid(),y);
  }
  else if(p1==0)
  {
    printf("p1=%d\n",p1);
    y = y-1;
    printf("This is child. Calling Process Id = %d, Parent Process Id=%d y = %d\n", getpid(),getppid(),y);
  }
  else
  {
    printf("Fork failed\n");

  }
}
