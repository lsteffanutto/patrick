#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]) {

  int fd[2]; // 0 extrémité lecture , 1 en écriture

  pipe(fd);

  pid_t pid = fork();

  if(pid>0){ //père

    close(fd[1]);

    //***
  }

  return 0;
}
