#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>



//boucle affiche PID à l'infini puis envoie "kill -9 PID" ou "kill SIGKILL PID" ou "kill SIGTERM PID" pour le finir
int main(int argc, char const *argv[]) {

  pid_t monpid = getpid();
  int i =100;

  printf("mon pid est: %d\n", monpid);

  pid_t fils = fork();

  if(fils>0){

    while(i>0){

      printf("boucle %d numéro %d en cours ...\n", i, monpid);
      i--;
    }
    

  }

  if(fils == 0){

    int kill(monpid,SIGKILL);
  }

  return 0;
}
