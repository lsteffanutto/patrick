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

//  1)   Déclaration du traitant de signal concerné
// Si le pgm reçoit le signal il va rentrer là dedans
void traitantusr(int signum){

  char * sender = "OK Jean-Mi !\n";
  write(STDOUT_FILENO,sender, strlen(sender));

}
//deuxieme traitant o`u le pgm s'arrête quand reçoit SIGUSR2
void traitantusr2(int signum){

  exit(EXIT_SUCCESS);
}

//Quand ce pgm reçoit SIGUSR1, il affiche OK Jean-Mi !
int main(int argc, char const *argv[]) {

  pid_t pid = getpid();
  printf("salut moi c'est %d\n",pid );

  int sigint = SIGUSR1;

  int sigint2 = SIGUSR2;

  //  2)   Déclaration/initialisation struct sigaction
  struct sigaction sa;
  memset(&sa, '\0', sizeof(sa)); //init à 0
  sa.sa_handler = &traitantusr; // pointeur de fonction (pointe sur la fonction traitant)

  struct sigaction sa2;
  memset(&sa2, '\0', sizeof(sa2));
  sa2.sa_handler = &traitantusr2;

  //  3)   Mise en place effective
  sigaction(SIGUSR1, &sa, NULL);
  sigaction(SIGUSR2, &sa2, NULL);

  //bloque le pgm pour qu'il attendent de recevoir des signaux USR1
  // Quand c'est le cas il passe dans le traitant de signaux

  while(1){

  }


  return 0;
}
