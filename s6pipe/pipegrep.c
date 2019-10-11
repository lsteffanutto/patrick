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
  pipe(fd); //1er tube = fd

  pid_t pid = fork();

  if(pid>0) //père
  {
    close(fd[1]);         //ferme extrem écriture 1er tube

    //***REDIRECTION STDIN******
    close(STDIN_FILENO);  //ferme input STDIN
    dup(fd[0]);           //dup en lecture du tube 1  qui prend le STDN 1er
    close(fd[0]);         //ferme extrem lecture tube 1

    execlp("wc","wc","-l",NULL); // pere execute le comptage1er fils  de ligne
  }

  else if(0==pid) //fils
  {
    int fd2[2];
    int pid2;
    pipe(fd2);

    pid2 = fork();

    if(pid2>0){            //****FILS 1
      close(fd[0]);  //ferme extrémité en lecture tube 1
      close(fd2[1]); //ferme extrémité en écriture tube 2
      close(STDOUT_FILENO);  //ferme STDOUT la sortie
      dup(fd[1]);      //pour la rediriger sur l'écriture du1er fils  tube 1
      close(fd[1]);

      close(STDIN_FILENO);  //close stdin
      dup(fd2[0]);   //pour la rediriger sur la lecture tube 2
      close(fd2[0]);

      execlp("grep","grep","truc",NULL); // 1er fils execute le grep de truc

    }

    else if(0 == pid2)      //****FILS 2
    {
      close(fd[0]); //ferme lecture tube1
      close(fd2[0]); //ferme lecture tube2
      close(STDOUT_FILENO);
      dup(fd2[1]);   //écriture tu 2 en stdout
      close(fd2[1]);

      execlp("cat","cat","text.txt",NULL);  //dernier fils execute cat
    }
  }




  return 0;
}
