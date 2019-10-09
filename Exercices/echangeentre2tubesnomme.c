#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]) {

  char* tube = "tubalife";
  mkfifo(tube,S_IXUSR);
  int fd;

  pid_t pid = fork();

  if (pid>0){
    char* sender = "Assalam";

    fd = open(tube, O_WRONLY);
    printf("tube ouvert pour ecrire\n");


    write(fd, sender, strlen(sender) );
    printf("msg sent\n");

    close(fd);
  }

  if(pid ==0){

    char receiver[64];
    
    fd = open(tube,O_RDONLY);
    printf("tube ouvert pour lire\n");

    read(fd, receiver, sizeof(receiver) );
    printf("msg reçu\n");
    printf("mon pere sent: %s\n", receiver);
    close(fd);

  }

  return 0;
}
