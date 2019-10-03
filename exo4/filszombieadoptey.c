#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {

  pid_t pidpere = getpid();

  printf("pere de PID %d\n", pidpere );

  pid_t pid = fork();

  if(0 == pid)
  {
    pid_t pidpereavant = getppid();
    printf("Le pid de mon pere avant est: %d \n", pidpereavant);
    sleep(5);
    pid_t pidpereapressamort = getppid();
    printf("Le pid de mon pere après est: %d \n", pidpereapressamort);
    exit(69);
  }


  if(0 < pid)
    sleep(1);

    exit(0);


  return 0;
}
