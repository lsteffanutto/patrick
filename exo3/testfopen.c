#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {

   FILE * fo = fopen("file.txt","r");
   int fo_no = fileno(fo);
   int fd = open("file.txt", O_RDONLY);

   //printf("index")
   printf("index fopen est : %d\n",fo_no);
   printf("index open est : %d\n",fd);
   // affiche 4 car normalement index descripteur fopen = 3 ;)


  return 0;
}
