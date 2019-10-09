#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]) {

  int fd[2];
  pipe(fd);
  pid_t pid = fork();

  if(pid>0){

    char bufferenvoie[] = "salut ça va ?";

    close(fd[0]);
    write(fd[1], bufferenvoie, strlen(bufferenvoie));


  }else if(pid == 0) {
    char bufferreception[64];

    close(fd[1]);
    read(fd[0], bufferreception, 64);

    fprintf(stdout, "Mon dar m'a sent: %s\n", bufferreception );

  }

  return 0;
}
