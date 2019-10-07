#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <string.h>

#define SIGUSR1 10

// fork on garde les traintant pas à travers un exec

void signal_reception (int sig_number);

int main(int argc, char const *argv[]) {

  pid_t pid = getpid();

  printf("mon pid est: %d\n", pid);

  struct sigaction traitant;
  memset (&traitant, 0, sizeof(traitant));

  traitant.sa_handler = &signal_reception;

  sigaction(10, &traitant,NULL);

  while(1){
    printf("mon pid est: %d\n", pid);

  }



  return 0;
}

void signal_reception (int signum)
{
  printf(" signal %d received!\n", 15);
}
