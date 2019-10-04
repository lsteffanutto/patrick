#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>


// execute ./printf
int main(int argc, char const *argv[]) {

  char ** my_args = malloc(2*sizeof(char*));
  my_args[0]="./print";
  my_args[1]=NULL;

  pid_t fils = fork();

    if(0==fils)
      execv("./print",my_args);

    if(0<fils)
      printf("jsuis pere mais je fais R\n");

  return 0;

}
