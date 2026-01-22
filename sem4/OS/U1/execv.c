#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
int main()
{
  printf("Using execv() to execute `prog1`: \n");
  char *args[] = {"meow",NULL};
  if(fork()==0)
  {
    execv("./meow",args);
    perror("exec failed");
    exit(1);
  }
  wait(NULL);
  printf("execv() finished\n");
  return 0;
}
