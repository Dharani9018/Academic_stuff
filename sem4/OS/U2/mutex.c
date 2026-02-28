#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

pthread_t tid[2];
int counter;
pthread_mutex_t lock;

void *thread_function(void *arg)
{
  pthread_mutex_lock(&lock);

  unsigned long i = 0;
  counter + = 1;
  printf("\n Job %d has started\n",counter);

  for(i = 0;i<(0xFFFFFFFF); i++)

    ;

  printf("\n Job %d has finished\n",counter);
  pthread_mutex_unlock(&lock);

  return NULL;

}

int main(void)
{
  int i = 0;
  int error;
  if(pthread_mutex_init(&lock,NULL)!=0)
  {
    printf("\n mutext init has failed\n");
    return 1;
  }

  while(i<2)
  {
    error = pthread_create(&tid[i],NULL,&thread_function,NULL);
    if(error!=0)
    {
      printf("\n Thread can't be created: [%s]",strerror(error));
      return 1;
    }
  }
}
