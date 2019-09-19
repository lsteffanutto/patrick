#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>


// écris entier dans un fichier

int main(int argc, char const *argv[]) {

  int fd = open("toto.txt", O_RDWR);
  close(STDOUT_FILENO);
  dup(fd);
  close(fd);j


  return 0;

}
