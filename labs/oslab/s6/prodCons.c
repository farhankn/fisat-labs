#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>


sem_t full,empty,mutex;
pthread_t pThreads[5],cThreads[5];
int buff[100], nget = 0, nput = 0, value = 0;

void *produce(int *);
void *consume(int *);

int main()
{
  int i;
  int producer[10],consumer[10];

  system("clear");

  sem_init(&full, 0, 0);
  sem_init(&empty, 0, 4);
  sem_init(&mutex, 0, 1);

  for(i = 0; i < 3; i++)
    {
      producer[i] = i;
      pthread_create(&pThreads[i], NULL, produce, &producer[i]);
    }

 for(i = 0; i < 2; i++)
    {
      consumer[i] = i;
      pthread_create(&cThreads[i], NULL, consume, &consumer[i]);
    }
 

 for(i = 0;i < 4; i++)
    pthread_join(pThreads[i],NULL);
  
  for(i = 0;i < 2; i++)
    pthread_join(cThreads[i],NULL);
 

 sleep(20);
  
  printf("\n");

  return 0;
}


void *produce(int *arg)
{
  while(1)
    {
      sem_wait(&empty);
      sem_wait(&mutex);
  
      sleep(1);
      buff[nput%4] = value;
      printf("\n\t Producer %d produced item %d ", *arg, buff[nput%4]);
      nput++;
      value++;
      

      sem_post(&mutex);
      sem_post(&full);
    }
}

void *consume(int *arg)
{
  int value;

  while(1)
    {
      sem_wait(&full);
      sem_wait(&mutex);
  
      sleep(1);
      value = buff[nget%4];
      nget++;
      printf("\n\t Consumer %d consumed item %d ", *arg, buff[nget%4]);

      sem_post(&mutex);
      sem_post(&empty);
    }

}