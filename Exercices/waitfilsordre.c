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

  int statut,i=0,j=0;
  int indexpid[3];

  for(i=0; i<3; i++)
  {
    pid_t fils = fork();

    if(0 == fils)
    {
      pid_t pidfils = getpid();
      printf("salut je suis le fils %d, de pid %d\n",i+1,pidfils);
      pid_t pidpere = getppid();
      printf("pere de pid %d\n\n",pidpere);
      indexpid[i]=pidfils;

      printf("j'attends %d secondes\n\n",i);
      sleep(i);
      break;
    if(0<fils)
    {
      sleep(2);

      for (j = 0; j < 3; j++) {
        waitpid(indexpid[2-j], &statut, WEXITSTATUS(&statut));
        printf("pid fils terminé est:%i\n",indexpid[2-j]);

      }
      printf("pid père est:%i\n",pidpere);
      printf("code de retour est: %d\n",WEXITSTATUS(statut));
    }
    }

  }


  int toto = 0;
  while(++toto);

  int michel = wait(&statut);
  //attend que le fils est terminé avant de reprendre


  // if(0==fils)
  // {
  //   pid_t pidfils = getpid();
  //   printf("pid fils terminé est:%i\n",pidfils);
  //   printf("pid de mon père est:%i\n",pidpere);
  //   sleep(3);
  //   exit(69); //return 0 si EXIT_SUCCESS sinon retourne code de retour identifiable 69
  //   // exit(EXIT_SUCCESS); //return 0
  // }


  return 0;
}
