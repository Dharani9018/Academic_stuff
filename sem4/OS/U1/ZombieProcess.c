#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
  pid_t pid = fork();
  if(pid>0)
  {  
    sleep(15);
    printf("In parent\n");
  }
  else if(pid==0)
  {
    printf("In child\n");
    exit(0);
  }
  return 0;
}
