#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

int g = 0;

void *myThreadFunction(void *vargp)
{
  int *myid = (int *)vargp;
  static int s= 0;
  int l=0;
  ++l;++s;++g;
  printf("Thread ID: %d, Local: %d, Static: %d, Global: %d\n",*myid,l,s,g);
  pthread_exit(NULL);
}

int main()
{
   int i;
  pthread_t tid;
  for(int i = 0;i<3;i++)
  {
    pthread_create(&tid,NULL,myThreadFunction,(void *)&tid);
    pthread_join(tid,NULL);
  }
  printf("IN main\n");
  return 0;
}
