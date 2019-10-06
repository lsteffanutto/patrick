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

// page 55.1

/*

  Dans ce fichier :

mmap = le père, qui fait hériter à ses fils le /tmp/montube
├── fork fils qui lance mmap3
│   └── joue l'écrivain :
│       ├── Open() le fichier
│       ├── mmap() le ficher opened
│       ├── memcpy() du texte dans l'adresse retournée par mmap
│       └── (close, close, munmap)
├── fork 2e fils qui lance mmap4
│   └── joue l'écrivain :
│       ├── Open() le fichier
│       ├── mmap() le ficher opened
│       ├── printf(%s) de l'adresse retournée par mmap
│       └── (close, close, munmap)
└── (unlink tube de sync, unlink le fichier partagé)


*/

// ((prend toto.txt en arg))
int main(int argc, char **argv)
{

   pid_t pid, pid2;
   int fd;

   mkfifo("/tmp/montube",S_IRUSR|S_IWUSR); //tube de synchronisation créé

   //ouvre le fichier à map juste pour le préparer à 4Ko (pour mmap)
   fd = open(argv[1],O_RDWR|O_CREAT|O_EXCL,S_IRUSR|S_IWUSR);
   if (fd != -1) ftruncate(fd,4096);
   close(fd);

   pid = fork(); //1er fork du père

   if(pid > 0){ // parent

      pid2 = fork(); //2e fork du père

      if (pid2 == 0){ // fils cadet

        execlp("./16_mmap3","16_mmap3",argv[1],argv[2],NULL);

      }else if (pid2 > 0){ // parent

    	  wait(NULL);
    	  wait(NULL);

    	}
   }else if (pid == 0){ // fils ainé

      execlp("./16_mmap4","16_mmap4",argv[1],argv[2],NULL);

   }

   unlink("/tmp/montube");
   unlink(argv[1]);
   return 0;

}
