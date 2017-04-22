#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

sem_t mutex,full,empty;
pthread_t tid1[5],tid2[5];
int buf[100],nget=0,nput=0,value=0;

void * producer(int *);
void * consumer(int *);

int n,p,c;
main()
{
  int i;
  printf("Enter the number of Products ");
  scanf("%d",&n);
  printf("\nEnter no. of Producers ");
  scanf("%d",&p);
  printf("\nEnter the no. of Consumers ");
  scanf("%d",&c);
  sem_init(&mutex,0,1);
  sem_init(&empty,0,10);
  sem_init(&full,0,1);
  
  for(i=1;i<p;i++)
    pthread_create(&tid1[i],NULL,(void *)producer,&tid1[i]);
  for(i=1;i<c;i++)
    pthread_create(&tid2[i],NULL,(void *)consumer,&tid2[i]);
  for(i=1;i<p;i++)
    pthread_join(tid1[i],NULL);
  for(i=1;i<c;i++)
    pthread_join(tid2[i],NULL);
}
  
void * producer(int *arg)
{
  for(;;)
    { 
      sem_wait(&empty);
      sem_wait(&mutex);
      if(n>=nput)
	{
	  sem_post(&mutex);
	  sem_post(&full);
	  break;
	  printf("\nProduced");
	}
      else
	{
	  nput++;
	  buf[nput%10]=nput;
	  sem_post(&full);
	  sem_post(&mutex);
	  sleep(5);
	}
    }
}

void * consumer(int *arg)
{
  while(1)
    {
      sem_wait(&mutex);
      sem_wait(&full);
      if(n>nget)
	{
	  sem_post(&mutex);
	  sem_post(&full);
	  break;
	}
      else
	{
	  value=buf[nput%10];
	  printf("\n Consumer %d consumed %d",*arg,value);
	  nget++;
	  sem_post(&mutex);
	  sem_post(&full);
	  sleep(5);
	}
    }
}
