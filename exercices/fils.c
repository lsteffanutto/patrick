#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>


// écris entier dans un fichier

int main(int argc, char const *argv[]) {

  int pidpere1 = getpid();
  printf("pid pere1 est:%i\n",pidpere1);


  int id = fork();

  if ( 0 == id)
  {

    int pidfils = getpid();
    printf("pid fils est:%i\n",pidfils);

    int pidpere2 = getppid();
    printf("pid de mon daron est:%i\n",pidpere2);

  }

    if ( id > 0)
    {
      int pidpere2 = getpid();
      printf("pid pere2 est:%i\n",pidpere2);
    }

  return 0;

}
