# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>

// compilation: gcc -0 prgm prgm.c
// execution: ./prgm

// ***** OUVRE UN
int main(int argc, char const *argv[]) {
  
  int a = open( "test", O_RDONLY);
  printf("index du nouveau descripteur de fichier pour a est: %i\n",a);

  int b = open( "test", O_RDONLY);
  printf("index du nouveau descripteur de fichier pour b est: %i\n",b);



  return 0;
}
