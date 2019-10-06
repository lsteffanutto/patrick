#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>

//Un pere crée 2 fils qui ne sont pas affiliés entre eux

int main(int argc, char const *argv[]) {

  char* tab = "salut";

  struct stat * stockage; //pointeur pour modifier avec fonction
  stockage = malloc(sizeof(stockage));

  int fd = open("text.txt", O_RDWR);
  ftruncate(3, 4000/8); // 1 byte = 8 bits = 1 octet

  int taille = fstat(fd, stockage);
  int taillefile = stockage->st_size;
  printf("taille bytes est %d\n", taillefile );


  char* addr = mmap(NULL, taillefile, PROT_READ, MAP_ANONYMOUS);


  return 0;

}
