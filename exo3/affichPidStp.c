#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>


int main(int argc, char const *argv[]) {

  pid_t pid = getpid();
  printf("%i\n", pid);
  printf("Patrick au village\n");
  pid_t pid_new = fork();


  printf("Patrick a la plage %i\n", pid_new);


  return 0;
}
