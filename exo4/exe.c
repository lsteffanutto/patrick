#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>


//créer fils puis boucle attente active, attend terminaison fils
int main(int argc, char const *argv[]) {

  char argv[2]=("print",NULL);

  execv("/S7/progsysteme/exo4/print", &argv);

  return 0;

}
