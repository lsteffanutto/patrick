#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {

  int i=0;
  pid_t pid = getpid();
  pid_t papa = getppid();

  printf("\nSalut j'suis le pere, pid = %d, je vais créer 10 pfdp\n", pid);
  printf("PS:mon papa à moi est: %d\n\n\n", papa);

  for(i=0; i<3; i++)
  {
    pid_t fils = fork();

    if(0 == fils)
    {
      pid_t pidfils = getpid();
      printf("salut je suis le fils %d, de pid %d\n",i+1,pidfils);
      pid_t pidpere = getppid();
      printf("pere de pid %d\n\n",pid);
      break;
    }

  }


  return 0;
}
