#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  pid_t pid = getpid();
  fprintf(stdout, "%d\n",pid );

  while(1){

  }
  return 0;
}
