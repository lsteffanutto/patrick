#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  pid_t pidpere = getpid();
  printf("\nje suis le père mon pid est %d\n\n", pidpere);

  pid_t fils = fork();

  if( 0 == fils)
  {
    pid_t pidfils = getpid();
    pid_t pidpere1 = getppid();

    printf("je suis le fils mon pid est %d\n\n", pidfils);
    printf("je suis le fils pid de mon pere est %d\n\n", pidpere);


  }

  return 0;
}
