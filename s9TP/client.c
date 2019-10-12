#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h> //strlen
#include <sys/types.h>
#include <sys/wait.h> //wait
#include <sys/mman.h>
#include <signal.h> //sig kill


#include <stdio.h> //printf
#include <stdlib.h>
#define MAXCHAR 1024

int main(int argc, char const *argv[]) {

  if (argc<2) {
    printf("Manque le pid du serveur\n");
    exit(1);
  }

  int fd,fd2;

  //on fabrique /tmp/PIPE_23444
  char * chaineclient;
  char pid[10];
  memset(&pid,'\0',strlen(pid));
  chaineclient = malloc(MAXCHAR*sizeof(char));
  memcpy(chaineclient, "/tmp/PIPE_", strlen("/tmp/PIPE_"));
  sprintf(pid,"%d",getpid());
  strcat(chaineclient,pid);
  strcat(chaineclient,"_");

  char * chaineclient_2;
  memset(&pid,'\0',strlen(pid));
  chaineclient_2 = malloc(MAXCHAR*sizeof(char));
  memcpy(chaineclient_2, "/tmp/PIPE_", strlen("/tmp/PIPE_"));
  sprintf(pid,"%d",getpid());
  strcat(chaineclient_2,pid);
  strcat(chaineclient_2,"_");


  int n1 = 54, n2 = 78;
  memset(&pid,'\0',strlen(pid));
  sprintf(pid,"%d",n1);
  strcat(chaineclient,pid);


  memset(&pid,'\0',strlen(pid));
  sprintf(pid,"%d",n2);
  strcat(chaineclient_2,pid);

  //tube nommé en lecture et en écriture
  mkfifo(chaineclient,S_IRWXU);
  mkfifo(chaineclient_2,S_IRWXU);

  // création de l'entier a envoyer
  n1 = n1<<16;
  int n3 = n1|n2;

  pid_t pid_serveur = atoi(argv[1]);
  union sigval sig;
  sig.sival_int=n3;


  if (sigqueue(pid_serveur,SIGUSR1,sig)==-1) {
    printf("pas de processus avec ce pid\n");
  }
  char * reponse;
  char * buffer;
  int rd = 0;
  buffer = malloc(MAXCHAR*sizeof(char));
  reponse = malloc(MAXCHAR*sizeof(char));
  read(0,buffer,MAXCHAR);


  fd = open(chaineclient,O_WRONLY);


  int sent =0;

  do{
    sent += write(fd,buffer+sent,strlen(buffer) - sent);
  }while(sent!=strlen(buffer));


  fd2 = open(chaineclient_2,O_RDONLY);
  struct stat st;
  memset(&st,0,sizeof(struct stat));
  if (fstat(fd2,&st)==-1) {
    perror(":error");
  }

  rd=0;
  do{
    rd += read(fd2,reponse +rd , st.st_size - rd);
  }while(rd != st.st_size);

  read(fd2,reponse,MAXCHAR);

  printf("%s\n",reponse);

  return 0;
}
