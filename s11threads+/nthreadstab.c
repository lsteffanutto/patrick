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

void * threadsachacal(void * numthread){
  printf("%d",tab[2]);
  printf("%d",numthread);
}

int main(int argc, char const *argv[]) {

  int tab[9] = {2,1,5,6,7,8,4,9,0};
  pthread_t thread;

  int nbthread=5;
  int j=0;
  for(j=0;j<nbthread;j++){
    pthread_create(&thread,NULL,threadsachacal,(void*)&tab);
  }

  return 0;
}
