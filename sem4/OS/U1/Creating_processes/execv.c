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
<<<<<<< HEAD
    //exec -> overwrites the child's memory with the program to execute the executable file(here-> meow)
    //v->vector : The arguments to the program are passed as an array (vector) of pointers.
    execv("./meow",args); //path to the executable execv("path",args)
=======
    execv("./meow",args);
>>>>>>> 981fe96f5bd74891b42b1f36e81e31547d541f42
    perror("exec failed");
    exit(1);
  }
  wait(NULL);
  printf("execv() finished\n");
  return 0;
}
