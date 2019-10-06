#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {

  char filename[] = "output.txt";

  //char entier[] = "salut\n";

  //char buffer[20];

  //printf("%s\n",entier);

  open(filename, O_RDWR);

  dup2(3,1);
  printf("redirection du printf\n");
  //write( fd, entier, sizeof(entier));
  return 0;
}
