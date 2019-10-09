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
  // int fd[2];
  // pipe(fd);
  int mkfifo("michel",S_IRWXU) // créationtube nommé
  pid = fork();

  if(pid >0){
    char buffer[] = "Je suis un transexuel\n";
    close(fd[0]);
    write(fd[1], michel, strlen(michel));
  } else if (pid == 0) {
    int fd_r = open("michel", O_RDONLY);
    char truc[32]="deuxseptzero";
    char* truc = malloc()
    close(fd[1]);
    read(fd[0], michel, 32);
    fprintf(stdout, "%s\n", michel);
  }

  return EXIT_SUCCESS;
}
