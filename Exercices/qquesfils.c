#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdlib.h>


int main(int argc, char const *argv[]) {

  pid_t pid;

  for(int i=0; i<10; i++)
  {
    pid = fork();

    if( pid > 0)
    {
      
    }
    if(0 == pid)
    {
      int pidfils = getpid();
      printf("pid fils %i est:%i\n", i , pidfils );
      break;

    }
  }
  return 0;
}
