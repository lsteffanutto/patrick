#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]) {

  int i=0;
  int tab[3]={1, 2, 3};

  for(i=0; i<3;i++)
  {
    printf("tab[%d]=%d\n", i, tab[i]);
  }
  return 0;
}
