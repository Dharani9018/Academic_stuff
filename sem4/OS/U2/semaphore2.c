#include<semaphore.h>
#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<string.h>

sem_t s1;

void *thread1(void *arg)
{
  char s[] = "abcdefgh";
    int l = strlen(s);
  for(int i = 0;i<l;i++)
  {
    //wait
    sem_wait(&s1); //acquiring resource
    //critical section
    putchar(s[i]);
    fflush(stdout);
    sleep(2);

    //signal
    sem_post(&s1); 
  }
}

void *thread2(void *arg)
{
  char s[] = "ABCDEFGH";
  int l = strlen(s);

  for(int i = 0;i<l;++i)
  {
    //wait
    sem_wait(&s1);

    //critical section
    putchar(s[i]);
    fflush(stdout);
    sleep(2);

    //signal
    sem_post(&s1);
  }
}

int main()
{
  pthread_t t1,t2;
  sem_init(&s1,0,1);

  pthread_create(&t1,NULL,thread1,NULL);

  sleep(2);

  pthread_create(&t2,NULL,thread2,NULL);

  pthread_join(t1,NULL);
  pthread_join(t2,NULL);

  sem_destroy(&s1);
  printf("\n");

  return 0;
}

