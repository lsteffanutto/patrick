#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <unistd.h>
#include <sys/mman.h>
#include <string.h>
#include <signal.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAP_SIZE 4096

int main(int argc, char **argv)
{
   char  *base_addr = NULL;
   char  *curr_addr = NULL;
   char  *filename  = NULL;
   int    str_len   = 0;
   int    fd,fd2,i;

   fprintf(stdout,"PID : %i\n",getpid());

   filename = argv[1]; //il y a toujours le toto.txt hérité du père
   str_len = strlen(argv[2])+1; //+1 pour le caractère de fin de chaine
   // argv[2] contient le texte à partager dans le fichier mbappé

   fd = open(filename,O_RDWR);
   base_addr = (char *)mmap(NULL, MAP_SIZE , PROT_READ | PROT_WRITE, MAP_SHARED , fd , 0);
   curr_addr = base_addr;

   memcpy(curr_addr, argv[2], str_len); //memcpy(dest, source, len) copy le texte passé en argument 2 à l'adresse du fichier mappé

   fd2 = open("/tmp/montube",O_WRONLY);//SYNCHRONISATION
   //tube nommé sinon on sait pas si l'autre a déjà ouvert le tube aussi ou non
   //open est bloquant tant que pas 1 écrivain 1 lecteur

   close(fd2);
   close(fd);
   munmap((void *)base_addr,MAP_SIZE);
   return 0;
}
