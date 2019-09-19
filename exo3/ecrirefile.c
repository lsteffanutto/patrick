# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>
#include <unistd.h>


// écris entier dans un fichier

int main(int argc, char const *argv[]) {

  char nom[] = "file.txt";
  // valeur qu'on écrit
  char entier[] = "75";

  //buff pour stocker ce qu'on a ecrit et qu'on veut lire
  char stockage[20];


  open((const char*) nom, O_RDWR);
  write(3, (const char*) entier, sizeof(entier));
  printf("7 5 C'est la CL\n");
  close(3);
  // on doit fermer le fichier pour remettre l'offset à 0, sinon on lit R
  //on le réouvre et c ban
  open((const char*) nom, O_RDWR);
  read(3, (char*) stockage , 20);
  printf("%s papapapa\n", stockage);

  return 0;

}
