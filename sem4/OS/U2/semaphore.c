#include<semaphore.h>
#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

sem_t s1;

void *my_thread(void *arg)
{
  sem_wait(&s1);
  printf("\nEntered..\n");

  //critical section
  sleep(4);
  //signal
  printf("\nExiting..\n");
  sem_post(&s1); //releases sem; Increases semaphore value (from 0 to 1)
}

int main()
{
  pthread_t t1,t2;
  sem_init(&s1,0,1);

  pthread_create(&t1,NULL,my_thread,NULL);

  sleep(2);

  pthread_create(&t2,NULL,my_thread,NULL);

  pthread_join(t1,NULL);
  pthread_join(t2,NULL);

  sem_destroy(&s1);

  return 0;
}

