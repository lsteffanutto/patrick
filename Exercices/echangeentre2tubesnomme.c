#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]) {

  int fd;
  char* tube = "/tmp/tubalife";

  mkfifo(tube,S_IRUSR|S_IWUSR);

  pid_t papa = getpid();
  printf("mon pid est: %d\n",papa );
  pid_t pid = fork();

  if (pid>0){

    printf("pere de pid: %d\n",pid );
    char* sender = "Assalam";
    fprintf(stdout, "jveux envoyer %s\n\n",sender );
    fd = open("/tmp/tubalife", O_WRONLY);

    if(fd<0) perror("bite je suis pas ouvert : \n\n");

    printf("tube ouvert pour ecrire\n");
    write(fd, sender, strlen(sender) );
    printf("msg sent\n");

    close(fd);
  }

  if(pid ==0){

    printf("pere de pid: %d\n",pid );

    char receiver[64];
    printf("sizeof receiver =%d\n", sizeof(receiver));

    fd = open("/tmp/tubalife",O_RDONLY);
    if(fd<0) perror("bite jpeux pas lire\n\n");
    printf("msg reçu\n");
    printf("tube ouvert pour lire\n");

    read(fd, receiver, sizeof(receiver) );
    printf("mon pere sent: %s\n", receiver);
    close(fd);

  }

  return 0;
}
