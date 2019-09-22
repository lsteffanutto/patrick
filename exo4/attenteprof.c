#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>


//créer fils puis boucle attente active, attend terminaison fils
int main(int argc, char const *argv[]) {

  pid_t pere = getppid();
  pid_t fils = fork();

  if (fils>0) //code du pere
  {
    int toto = 0;
    while(++toto); //incremente hasta dépasser capacité variable, ont attend assez logntemps
    // attente active le mec s'occupe
    // attente passive, pgm en sommeil

    wait(NULL);
  }
  exit(EXIT_SUCCESS);

}
