#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>


int main(int argc, char const *argv[]) {

  pid_t pidpere1 = getpid();

  pid_t fils = fork();

  int pidfils, pidfils1;
  printf("fils = %i\n", fils);
  if ( 0 == fils)
  {
    pidfils = getpid();
  }

  int status;
  printf("pidfils: %i\npidpere1:%i\n",pidfils, pidpere1 );
  wait(&status); //info fils
//  printf("valeur de retour du fils:%d\n", WIFEXITED(status));
  exit(EXIT_SUCCESS);

  if (fils>0)
  {
    int toto = 0;
    while(++toto);
    pidfils1 = wait(&status);
    printf("pidfils terminé est: %i\n", pidfils );
    printf("code de retour fils est: %\ni", WEXITSTATUS(status) );
    printf("pidfils1 terminé est: %i\n", pidfils1 );
  }

  return 0;
}
