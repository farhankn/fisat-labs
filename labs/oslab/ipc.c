#include<stdio.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<sys/ipc.h>

key_t key;
size_t size;
int * strtaddr;
long int shmid;

main()
{

 printf("\n Enter the key:");
 scanf("%ld",&key);
 printf("\n Enter the size:");
 scanf("%ld",&size);
 shmid=shmget(key,size,IPC_CREAT|0666);
 if(shmid<0)
  printf("\nError!");
 else
  strtaddr=shmat(shmid,NULL,0);
 
 int i,j='A';
 for(i=0;i<25;++i)
 {
  
  *strtaddr++=j;
  j=j+1;
 }
 sleep(5);
}
