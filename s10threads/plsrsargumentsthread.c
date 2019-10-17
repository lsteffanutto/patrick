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

// Plusieurs arguments => structure;


void* thread1(void * prenom){
  printf("salut je suis le thread A %s\n",(char *) prenom);
}

void* thread2(void * prenom){
  printf("salut je suis le thread B %s\n",(char *) prenom);
}


int main(int argc, char const *argv[]) {

  char * jack = "jack";
  char * daniel = "daniel";

  printf("Création du thread A\n");
  pthread_t threadA;
  printf("Création du thread B\n");
  pthread_t threadB;



  pthread_create(&threadA,NULL,thread1,(void *)jack);
  pthread_create(&threadB,NULL,thread2,(void *)daniel);

  sleep(5);
}
