#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>


//créer fils puis boucle attente active, attend terminaison fils
int main(int argc, char const *argv[]) {

  pid_t fils = fork();
  wait(&status); //info fils
  printf("valeur de retour du fils:%d\n", WEXISTATUS(status));
  exit(EXIT_SUCCESS);


  else if (fils >0) // code du pere
  {
    int toto=0;
    int status;
    while(++toto);
    wait(&status); //info fils
    printf("valeur de retour du fils:%d\n", WEXISTATUS(status));

    exit(EXIT_SUCCESS);
  }

}
