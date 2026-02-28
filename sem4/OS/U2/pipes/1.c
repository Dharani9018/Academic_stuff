#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
  int a[2] ={3,4};
  int pid = fork(); //after fork there are 2 copies of a(both are independent) use pipes for the child and parent to have shared memory.
  //When the OS creates parent and child processes both will share the same physical memory but if the data in any of the processes is written/modified, the process which is modifying the data will get a new copy of the data, now the both processes have different physical memory.
  //This is called Copy on Write
  //Copy on write only affects user-space-memory and not kernel objects(like pipes)
  if(pid==0)
  {
    a[1] = 0;
  }
  else
  {
    a[0] = 1; 
    wait(NULL);
  }
  printf("%d a[0], %d a[1], pid: %d\n",a[0],a[1],pid); // in the child process a[0] = 3 and a[1] = 0
  // in parent process a[0] = 1 and a[1] = 4.
  
}
