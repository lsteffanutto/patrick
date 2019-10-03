#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  char* buffer = "J'aime les pâtes";

  pid_t p = fork();

  pid_t pidpere = getpid();

  if(p>0)
  {
    pid_t pidpere = getppid();

    printf("\nje suis le père et %s\n",buffer );
    printf("mon pid est : %d\n", p);

  }
  if(0 == p)
  {
    pid_t pidpere = getppid();
    printf("je suis le fils et %s\n", buffer);
    printf("mon pid est : %d\n\n\n", p);
    printf("le processus de mon père est: %d\n\n\n", pidpere);


  }

  return 0;
}
