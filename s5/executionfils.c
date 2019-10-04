#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>


int main(int argc, char const *argv[]) {

  // int fd = open("test.txt", O_RDWR);
  //
  // printf("l'index est: %i\n", fd );
  //

  pid_t pid = fork();

  if(0 == pid){

    //printf("valeur pid fils : %i\n", fd);

    char ** my_args = malloc(2*sizeof(char*));
    my_args[0]="./dispindex";
    my_args[1]=NULL;

    execv("./dispindex",my_args);
  }

  else if(pid > 0){
    printf("je fais R\n");
  }


  exit(EXIT_SUCCESS);
}
