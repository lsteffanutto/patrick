# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>

// compilation: gcc -0 prgm prgm.c
// execution: ./prgm

// ***** OUVRE UN FICHIER EN LECTURE SEULE ET LE CREE SI EXISTE PAS *****
// AVEC RWX ONLY FOR USER

int main(int argc, char const *argv[]) {
  
  int a = open( "TestOpenCreat", O_RDONLY | O_CREAT, S_IRWXU);
  printf("index du nouveau descripteur de fichier pour a est: %i\n",a);

  return 0;
}
