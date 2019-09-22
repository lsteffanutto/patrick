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

  int status; // status fils

  int toto = 0;
  while(++toto); //incremente hasta dépasser capacité variable, ont attend assez logntemps
  // attente active le mec s'occupe
  // attente passive, pgm en sommeil

  wait(&status);
  // si on recupere pas code de retour
  // On peut faire wait NULL


  printf("pid père est:%i\n",pere);
  printf("pid fils terminé est:%i\n",fils);


  return 0;
}
