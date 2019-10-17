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

void* fonction(void * arg){
  fprintf(stdout,"salut je suis le thread %i\n",*(int *) arg);
}


int main(int argc, char const *argv[]) {

  pthread_t tid[10];
  int i;
  int mon_i[10];

  for(i=0; i<10; i++){
    mon_i[i]=i;
    pthread_create(&tid[i],NULL,fonction,(void *)&mon_i[i]);
  }
  sleep(10);

  exit(EXIT_SUCCESS);

}
