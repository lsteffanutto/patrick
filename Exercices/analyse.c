#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {

  FILE * fo = fopen("text.txt", "r");

  int nb_ligne = 0;
  char c;
  while ((c = getc(fo)) != EOF){
    if (c == '\n')
      ++nb_ligne;
  }
  printf("nb ligne = %i\n",nb_ligne );
  return 0;
}
