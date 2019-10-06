#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {

  int pidpere = getpid();
  printf("pid PERE est: %i\n", pidpere);

  for (int i=0;i<10; i++)
  {
    int id = fork();

    if (0 == id)
    {
      int pidfils = getpid();
      printf("pid fils %i est: %i\n", i , pidfils);
      break;
    }
  }

  return 0;
}
