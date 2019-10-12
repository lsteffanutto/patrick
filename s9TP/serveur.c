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

void traitantusr(int signum, siginfo_t * sinfo,void * contexte){

  volatile pid_t fils = fork();

  if(0 == fils){
    pid_t client;
    int valeur;
    int fd,fd2;
    client = sinfo->si_pid;
    valeur = sinfo->si_value.sival_int;
    int numero1 = valeur>>16;
    int numero2 = (numero1<<16)^valeur;

    char * chaineclient;
    char pid[10];
    memset(&pid,'\0',strlen(pid));
    chaineclient = malloc(MAXCHAR*sizeof(char));
    memcpy(chaineclient, "/tmp/PIPE_", strlen("/tmp/PIPE_"));
    sprintf(pid,"%d",client);
    strcat(chaineclient,pid);
    strcat(chaineclient,"_");

    char * chaineclient_2;
    memset(&pid,'\0',strlen(pid));
    chaineclient_2 = malloc(MAXCHAR*sizeof(char));
    memcpy(chaineclient_2, "/tmp/PIPE_", strlen("/tmp/PIPE_"));
    sprintf(pid,"%d",client);
    strcat(chaineclient_2,pid);
    strcat(chaineclient_2,"_");

    memset(&pid,'\0',strlen(pid));
    sprintf(pid,"%d",numero1);
    strcat(chaineclient,pid);
    memset(&pid,'\0',strlen(pid));
    sprintf(pid,"%d",numero2);
    strcat(chaineclient_2,pid);

    fd = open(chaineclient,O_RDONLY);



    char * reponse = "merci pour le message !";
    char * buffer;
    int rd=0;
    buffer = malloc(MAXCHAR*sizeof(char));

    struct stat st;
    memset(&st,0,sizeof(struct stat));
    if (fstat(fd,&st)==-1) {
      perror(":error");
    }

    do{
      rd += read(fd,buffer +rd , st.st_size - rd);
    }while(rd != st.st_size);



    fd2 = open(chaineclient_2,O_WRONLY);

    int sent =0;

    do{
      sent += write(fd2,reponse+sent,strlen(reponse) - sent);
    }while(sent!=strlen(reponse));

  }

}


int main(int argc, char const *argv[]) {

  printf("Je suis le père serveur de PID:%d\n",getpid() );

  siginfo_t * sinfo;
  struct sigaction sa;
  memset(&sa, '\0', sizeof(sa)); //init à 0
  sa.sa_sigaction = &traitantusr; // pointeur de fonction (pointe sur la fonction traitant)
  sa.sa_flags = SA_SIGINFO;

  sigaction(SIGUSR1, &sa, NULL);




  while(1){

  }



  return 0;
}
