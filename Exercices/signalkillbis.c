#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

//le programme affiche son pid et s'arrête lui même
int main(int argc, char const *argv[]) {
  pid_t pid = getpid();
  fprintf(stdout, "%d\n",pid );

  kill(pid, 9);

  return 0;
}
