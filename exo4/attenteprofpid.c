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
  printf("valeur de retour du fils:%d\n", WEXITSTATUS(status));
  exit(EXIT_SUCCESS);


  if (fils >0) // code du pere
  {
    int toto=0;
    while(++toto);
    wait(&status); //info fils
    printf("valeur de retour du fils:%d\n", WEXITSTATUS(status));

    exit(EXIT_SUCCESS);
  }

}
