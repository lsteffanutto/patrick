#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {

  pid_t pidpere = getpid();
  printf("salut je suis le pere de pid %d\n", pidpere );

  int statut;

  pid_t fils = fork();

  int toto = 0;
  while(++toto);

  int michel = wait(&statut);
  //attend que le fils est terminé avant de reprendre


  if(0==fils)
  {
    pid_t pidfils = getpid();
    printf("pid fils terminé est:%i\n",pidfils);
    printf("pid de mon père est:%i\n",pidpere);
    sleep(3);
    exit(69); //return 0 si EXIT_SUCCESS sinon retourne code de retour identifiable 69
    // exit(EXIT_SUCCESS); //return 0
  }
  if(0<fils)
    printf("pid père est:%i\n",pidpere);
    printf("code de retour est: %d\n",WEXITSTATUS(statut));



  return 0;
}
