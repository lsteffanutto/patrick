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

// caster un int toto => (void *)&toto
void* thread1(void * prenom){
  int ret = 10;
  printf("salut je suis le thread A %s\n",(char *) prenom);
  pthread_exit((void*)&ret);
}

void* thread2(void * prenom){
  int ret=27;
  printf("salut je suis le thread B %s\n",(char *) prenom);
  pthread_exit((void*)&ret);

}

int main(int argc, char const *argv[]) {

  char * jack = "jack";
  char * daniel = "daniel";
  int * ret1,* ret2;

  printf("Création du thread A\n");
  pthread_t threadA;
  printf("Création du thread B\n");
  pthread_t threadB;



  pthread_create(&threadA,NULL,thread1,(void *)jack);
  pthread_create(&threadB,NULL,thread2,(void *)daniel);

  pthread_join(threadA,(void*)&ret1);
  pthread_join(threadB,(void*)&ret2);

  printf("\nret1=%d, ret2=%d\n",*ret1,*ret2 );

  return 0;
}
