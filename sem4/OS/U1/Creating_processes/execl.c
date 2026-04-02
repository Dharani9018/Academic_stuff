#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
int main()
{
  printf("Using execl() to execute `prog1`: \n");
  if(fork()==0)
  {
<<<<<<< HEAD
    execl("./meow","meow",NULL); //arguments passed list-wise
=======
    execl("./meow","meow",NULL);
>>>>>>> 981fe96f5bd74891b42b1f36e81e31547d541f42
    perror("execl failed");
    exit(1);
  }
  wait(NULL);
  printf("execl() finished\n");
  return 0;
}
