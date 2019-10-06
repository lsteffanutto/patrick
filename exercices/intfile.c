#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {

  char filename[] = "output.txt";

  char entier[] = "salut\n";

  char buffer[20];

  //printf("%s\n",entier);

  int fd = open(filename, O_RDWR);
  write( fd, entier, sizeof(entier));
  return 0;
}
