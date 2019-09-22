#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>


//créer fils puis boucle attente active, attend terminaison fils
int main(int argc, char const *argv[]) {

  pid_t fils = fork();

  int status;
  wait(&status); //info fils

  printf("valeur de retour du fils:%d\n", WEXISTATUS(status));
  exit(EXIT_SUCCESS);

  pid_t pere = getppid();

  printf("pid pere:%i\n",pere);

}
