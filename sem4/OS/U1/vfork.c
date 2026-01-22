#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
  pid_t pid = vfork();
  int y = 0;
  if(pid>0)
  {  
    for(int i = 0;i<5;i++)
    {
      sleep(i);
      y = y - 1;
      printf("This is parent. Process id=%d\n",getpid());
    }
  }
  else if(pid==0)
  {
    for(int i = 0;i<5;i++)
    {
      sleep(i);
      printf("In child, process id=%d, parent Process id=%d \n",getpid(),getppid());
    }
    _exit(0);
  }
  else 
  {
    printf("Fork Failed\n");
  }
  return 0;
}
