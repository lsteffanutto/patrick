#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h> //strlen
#include <sys/types.h>
#include <sys/wait.h> //wait
#include <sys/mman.h>
#include <signal.h> //sig kill
#include <stdio.h> //printf
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
//correction envoyée par et merciierrrr la zona
//10 fils qui affiche un truc QUE quand pere remet des jetons dans sem_t
//ici on la fait avec des threads
void * threadmaphore(void * sem){

    sem_wait(sem);
    printf("oui chef\n");

}
int main(int argc, char const *argv[]) {

  sem_t *sem = malloc(sizeof(sem_t));

  sem_init(sem, 0, 0);
  pthread_t thread;

  int j=0;
  for(j=0;j<10;j++){
    pthread_create(&thread,NULL,threadmaphore,(void*)sem);
  }

  printf("tu print oui mtnt stp\n");

  int i=0;
  for(i=0;i<10;i++){
    sem_post(sem);
  }

  pthread_join(thread,NULL);



  return 0;
}
