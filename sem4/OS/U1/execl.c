#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
int main()
{
  printf("Using execl() to execute `prog1`: \n");
  if(fork()==0)
  {
    execl("./meow","meow",NULL);
    perror("execl failed");
    exit(1);
  }
  wait(NULL);
  printf("execl() finished\n");
  return 0;
}
