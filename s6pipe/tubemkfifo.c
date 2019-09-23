#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

// dans ce cas il n'y a plus de pipe mais des fifo et close

int main(int argc, char const *argv[]) {

  pid_t pid;
  int fd[2];
  pipe(fd);
  pid = fork();

  if(pid >0){
    char buffer[] = "Je suis un transexuel\n";
    close(fd[0]);
    write(fd[1], buffer, strlen(buffer));
  } else if (pid == 0) {
    char truc[32];
    close(fd[1]);
    read(fd[0], truc, 32);
    fprintf(stdout, "%s\n", truc);
  }

  return EXIT_SUCCESS;
}
