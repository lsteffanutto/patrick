#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]) {

  int fd[2]; // 0 extrémité lecture, 1 en écriture
  pipe(fd);

  pid_t pid = fork();

  if(pid>0) //père
  {
    close(fd[1]);         //ferme extrem écriture

    //***REDIRECTION STDIN******
    close(STDIN_FILENO);  //ferme input
    dup(fd[0]);           //dup lecture qui prend le STDN
    close(fd[0]);         //ferme extrem lecture

    execlp("wc","wc","-l",NULL);
  }

  else if(0==pid) //fils
  {
    int fd2[2];
    int pid2;
    pipe(fd2);

    pid2 = fork();

    if(pid2>0){
      close(fd[0]);
      close(fd2[1]);
      close(STDOUT_FILENO);
      dup(fd[1]);
      close(fd[1]);

      close(STDIN_FILENO);
      dup(fd2[0]);
      close(fd2[0]);

      execlp("grep","grep","truc",NULL);

    }

    else if(0 == pid2)
    {
      close(fd[0]);
      close(fd2[0]);
      close(STDOUT_FILENO);
      dup(fd2[1]);
      close(fd2[1]);

      execlp("cat","cat","text.txt",NULL);
    }
  }




  return 0;
}
