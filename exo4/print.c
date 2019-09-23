#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>


//Se fait éxécuter par "exe.c"
int main(int argc, char const *argv[]) {

  while(*argv){
    fprintf(stdout, "Arg: %s\n", *argv++);
  }
  //fprintf("salut toi !");

  return 0;

}
