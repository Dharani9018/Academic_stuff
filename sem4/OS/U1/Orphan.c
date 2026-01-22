#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
  pid_t pid = fork();
  if(pid>0)
  {  
    printf("In parent process id = %d\n",getpid());
    exit(0);
  }
  else if(pid==0)
  {
    sleep(2);
    printf("In child, process id=%d, parent Process id=%d \n",getpid(),getppid());
  }
  else 
  {
    printf("Fork Failed\n");
  }
  return 0;
}
